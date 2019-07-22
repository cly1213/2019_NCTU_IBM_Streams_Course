// eJx9kWFLwzAQhrl_1IsPPTdMNoUWEypxUq6jVD34qaXezwTQp6dW6f2_1WdoJFJRDCe_09xz5srTe3JovZasijq9tOTGimKEndnprMlAgffHQ4Lz2O0b5Bd4k1v77I_0SP3wXsrw9vnxNb5e91ex9qqF865ASTr1IXtIo0jJls6Hl3UzpH47uYChzsf6ThlBZ6tRC0atMEah0KO2nPmAVaZGhtsuCFhv7HvbiBIZD_1MDejtA56JnW0ECtNF4AHp5SlIHAvxvKD5Rx_0SUoiPcWESQWtIaldjDjJdPIeb20mKNmoTaIJXVseuYiE8xf3btDtZEE9oPoX4ftJy1_0MNeTGPs90_1_1sxeowbqGHovcYglTaPD9L7ZaJ4g





#include "./Web.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Web_Base
#define MY_OPERATOR Web$OP



#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cerrno>
#include <fstream>
#include <iomanip>
#include <getopt.h>
#include <sys/socket.h>
#include <netdb.h>
using namespace std;

#include <streams_boost/algorithm/string.hpp>
using namespace streams_boost;


#include <limits.h>
#include <stdlib.h>

/*
*******************************************************************************
* Copyright (C) 2009,2012-2014, International Business Machines Corporation. 
* All Rights Reserved. *
*******************************************************************************
*/

// This file contains the source for InetRetriever.
// As it references MY_OPERATOR, it's meant to be included in a cgt file.


MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::InetRetriever(const std::string& url, const int timer) throw(int) :
  _targetURL(url),
  _timeout(timer)
  {
    reset();
    _ignoreLastModTime = _incrementalFetch = false;

    _curlHandle = curl_easy_init();

    if (NULL == _curlHandle)
      {
        std::cerr << "InetRetriever: Init returned null curlHandle" << std::endl;
        throw 12;
      }

#if 0
    printf(">>>>>>>>>>>>>>>> retriever for URL %s, timeout=%d\n", _targetURL.c_str(), _timeout);
#endif

    // what to do with returned data - call the class' static callback method
    curl_easy_setopt(_curlHandle, CURLOPT_WRITEFUNCTION, consumeData_static);

    // Set the write function's user-data (state data).
    // Note that passing the "this" pointer allows the static callback method (set above)
    // to resolve the particular instance that the callback should be directed to.
    curl_easy_setopt(_curlHandle, CURLOPT_WRITEDATA, this);

    // Set the URL that we are fetching
    curl_easy_setopt(_curlHandle, CURLOPT_URL, _targetURL.c_str());

    // Tell curl to follow any redirects for the URL that the server returns
    curl_easy_setopt(_curlHandle, CURLOPT_FOLLOWLOCATION, 1L);

    // Tell curl to ask the server to provide the "last modified at" timestamp when fetching a file
    curl_easy_setopt(_curlHandle, CURLOPT_FILETIME, 1);

    // accept all supported built-in compression methods
#ifdef CURLOPT_ACCEPT_ENCODING
    curl_easy_setopt(_curlHandle, CURLOPT_ACCEPT_ENCODING, "");
#elseif CURLOPT_ENCODING
    curl_easy_setopt(_curlHandle, CURLOPT_ENCODING, "");
#endif

    // some servers insist on knowing who is asking
    curl_easy_setopt(_curlHandle, CURLOPT_USERAGENT, "IBMStreams/4.0");

    // set timeout, if specified
    if (_timeout) {
      curl_easy_setopt(_curlHandle, CURLOPT_NOSIGNAL, 1);
      curl_easy_setopt(_curlHandle, CURLOPT_TIMEOUT, _timeout);
    } 
  }

MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::~InetRetriever()
  {
    curl_easy_cleanup(_curlHandle);
  }

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::fetch() throw(CURLcode)
  {

    // function result will be stored here
    std::string result;

    // clear state variables for other results that can be assigned to output attributes
    _curlBuffer.clear();
    _dataCameBack = false;
    _bytesTransferredLastFetch = 0;
    _responseCode = 0;
    _fetchTime = 0;
    _effectiveURL.clear();
    _contentType.clear();

    // Unless requested, don't retrieve again if unmodified since last retrieval
    if (!_ignoreLastModTime && _lastModTime>0)
      {
        // Tell curl to not retrieve the file if it hasn't changed since our last retrieval
        curl_easy_setopt(_curlHandle, CURLOPT_TIMECONDITION, CURL_TIMECOND_IFMODSINCE);
        curl_easy_setopt(_curlHandle, CURLOPT_TIMEVALUE, _lastModTime);
      }
    else
      {
        // Tell curl to retrieve the file regardless of whether it has changed since our last
        // retrieval
        curl_easy_setopt(_curlHandle, CURLOPT_TIMECONDITION, CURL_TIMECOND_NONE);
      }

    // "Engage." - J.L. Picard
    CURLcode rc1 = curl_easy_perform(_curlHandle);

    if (CURLE_OK == rc1)
      {
        if (_dataCameBack) // data came back
          {
            CURLcode rc2;

            char* effectiveURL = NULL;
            rc2 = curl_easy_getinfo(_curlHandle, CURLINFO_EFFECTIVE_URL, &effectiveURL);
            if (rc2==CURLE_OK && effectiveURL) _effectiveURL = effectiveURL;

            char* contentType = NULL;
            rc2 = curl_easy_getinfo(_curlHandle, CURLINFO_CONTENT_TYPE, &contentType);
            if (rc2==CURLE_OK && contentType) _contentType = contentType;

            curl_easy_getinfo(_curlHandle, CURLINFO_RESPONSE_CODE, &_responseCode);

            curl_easy_getinfo(_curlHandle, CURLINFO_TOTAL_TIME, &_fetchTime);

#if 0
            printf(">>>>>>>>>>>>>>>>>>> target URL %s\n", _targetURL.c_str());
            printf(">>>>>>>>>>>>>>>> effective URL %s\n", _effectiveURL.c_str());
            printf(">>>>>>>>>>>>>>>> content type %s\n", _contentType.c_str());
            printf(">>>>>>>>>>>>>>>> response code is %d\n", _responseCode);
            printf(">>>>>>>>>>>>>>>> total time is %lf\n", _fetchTime);
#endif

            long lastModTime;
            rc2 = curl_easy_getinfo(_curlHandle, CURLINFO_FILETIME, &lastModTime);
            if (rc2==CURLE_OK)
              {
                if (_incrementalFetch) // incremental mode
                  {
                    //  If the retrieval buffer is a superset of the cached file,
                    //   return the portion that is a proper superset (may be empty)
                    //  Else return the retrieval buffer

                    size_t bufSize = _curlBuffer.size();
                    size_t cacheSize = _fileCache.size();

                    // If the cache is empty and the retrieval buffer is not, return the entire buffer.
                    if (cacheSize == 0 && bufSize > 0)
                      result = _curlBuffer;

                    // If the retrieval buffer is smaller than the cached file, we take that as
                    // a signal that the file was completely refreshed, so return the entire buffer.
                    else if (bufSize < cacheSize)
                      result = _curlBuffer;

                    // At this point, we know the buffer is the same size as the cached file,
                    // or it is larger.

                    else if (bufSize == cacheSize)
                    // Files are same size.
                      {

                        // If cache and buffer have the same content, return empty string
                        // Otherwise return retrieval buffer
                        if (_curlBuffer.compare(_fileCache) == 0)
                          result.clear();
                        else
                          result = _curlBuffer;
                      }

                    else
                    // The buffer is larger than the cached file.
                      {
                        if (_curlBuffer.substr(0, cacheSize).compare(_fileCache)
                            == 0)
                          result = _curlBuffer.substr(cacheSize);
                        else
                          result = _curlBuffer;
                      }
                  }

                else // not incremental mode, return the retrieval buffer
                  {
                    result = _curlBuffer;
                  }

                //   Replace the file cache with the retrieval buffer
                _fileCache = _curlBuffer;
                // Resync the last modified time
                _lastModTime = lastModTime;
              }
            else
            // rc from getting the last mod time was nonzero

              {
                throw rc2;
              }
          } // data came back

        else // no data came back

          {
            long lastModTime;
            CURLcode rc2 = curl_easy_getinfo(_curlHandle, CURLINFO_FILETIME, &lastModTime);
            if (CURLE_OK == rc2)
              {
                // Leave the cached version of the file as-is
                // If incremental mode, return an empty string
                // Otherwise return the complete file value (our cached version of the file)
                if (_incrementalFetch)
                  result.clear();
                else
                  result = _fileCache;

                // Resync the last modified time
                if (lastModTime > -1)
                  _lastModTime = lastModTime;

              }
            else
              {
                throw rc2;
              }
          }
      }
    else // rc from performing the fetch was nonzero

      {
        throw rc1;
      }
    return result;
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::reset()
  {
    _bytesTransferredTotal = _bytesTransferredLastFetch = 0;
    _curlBuffer.clear();
    _fileCache.clear();
    _lastModTime = -1;
    _dataCameBack = false;
    _responseCode = 0;
    _fetchTime = 0;
    _effectiveURL.clear();
    _contentType.clear();
  }

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::targetURL() const
  {
    return _targetURL;
  }

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::effectiveURL() const
  {
    return _effectiveURL;
  }

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::contentType() const
  {
    return _contentType;
  }

long MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::responseCode() const
  {
    return _responseCode;
  }

double MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::fetchTime() const
  {
    return _fetchTime;
  }

bool MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::updateURL(std::string newURL) {
    if (newURL != _targetURL) {
        reset();
        _targetURL = newURL;
        curl_easy_setopt(_curlHandle, CURLOPT_URL, newURL.c_str());
        return true;
    }
    return false;
  }

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::lastknownContents() const
  {
    return _fileCache;
  }

size_t MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::bytesTransferredTotal()
  {
    return _bytesTransferredTotal;
  }

size_t MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::bytesTransferredLastFetch()
  {
    return _bytesTransferredLastFetch;
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::enableCurlTrace()
  {
    curl_easy_setopt(_curlHandle, CURLOPT_VERBOSE, 1);
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::disableCurlTrace()
  {
    curl_easy_setopt(_curlHandle, CURLOPT_VERBOSE, 0);
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::incrementalFetch()
  {
    _incrementalFetch = true;
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::incrementalFetch(bool whether)
  {
    _incrementalFetch = whether;
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::ignoreLastModTime()
  {
    _ignoreLastModTime = true;
  }

void MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::ignoreLastModTime(bool whether)
  {
    _ignoreLastModTime = whether;
  }

CURL* MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::curlHandle()
  {
    return _curlHandle;
  }

size_t MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::consumeData_static(void* buffer, const size_t recSize,
    const size_t numRecs, void* objPtr)
  {
    // Adapt the static callback from cURL to a non-static member function of this object instance
    return static_cast<InetRetriever*> (objPtr)->consumeData(buffer, recSize,
        numRecs);
  }

size_t MY_OPERATOR_SCOPE::MY_OPERATOR::InetRetriever::consumeData(const void* data, const size_t recSize,
    const size_t numRecs)
// Note: this method might be invoked many times by curl during a single fetch.  Each invocation
// supplies a chunk of the fetched data, and this method must assemble all the chunks.

  {
    // Flag that some data came back
    _dataCameBack = true;

    // Compute # of bytes in this chunk and increment counters accordingly
    size_t chunkSize = recSize * numRecs;
    _bytesTransferredTotal += chunkSize;
    _bytesTransferredLastFetch += chunkSize;

    // Append the chunk to the curlBuffer
    _curlBuffer.append((char*) data, chunkSize);

    // Curl requires that this function return the # of bytes processed during this invocation
    return chunkSize;
  }
/*
*******************************************************************************
* Copyright (C) 2007, 2012-2014, International Business Machines Corporation. 
* All Rights Reserved. *
*******************************************************************************
*/

// This is the file containing the URIHelper code.
// The file is meant to be included in a CGT file (it references MY_OPERATOR)
// 


#include <iostream>
#include <cstring>
#include <regex.h>
#include <vector>
#include <sstream>


using namespace std;

//---- URIQueryComponents class

void MY_OPERATOR_SCOPE::MY_OPERATOR::URIQueryComponents::print(ostream& o) const {
  for(std::map<string, string>::const_iterator i=nameValuePairs.begin();
    i!=nameValuePairs.end();++i) {
    o << "name: '" << i->first
      << "' value: '" << i->second
      << "' ";
  }
}

ostream& operator<< (ostream& o, const MY_OPERATOR_SCOPE::MY_OPERATOR::URIQueryComponents& qc) {
  qc.print(o);
  return o;
}

//---- URIHelper class

// subset regex of URI defined in RFC 2396
const char* MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::URIREGEX=
  /* protocol (opt) */ \
  "^(([[:alpha:]][[:alnum:]+.-]*):)?" \
  /* userinfo (opt) */ \
  "//(([[:alnum:]@_.!~*\'();:&=+$,-]*)@)?" \
  /* hostname (opt) */ \
  "(((([[:alnum:]]|[[:alnum:]][[:alnum:]-]*[[:alnum:]])\\.)*" \
  "([[:alpha:]]|[[:alpha:]][[:alnum:]-]*[[:alnum:]]))\\.?|" \
  /* IPv4address */ \
  "([[:digit:]]+\\.[[:digit:]]+\\.[[:digit:]]+\\.[[:digit:]]+))?" \
  /* port (opt) */ \
  "(:([[:digit:]]+))?" \
  /* path (opt) */ \
  "/(([[:alnum:]_.!~*\'():@&=+$,-]|%[[:digit:]a-fA-F][[:digit:]a-fA-F])*" \
  "(;([[:alnum:]_.!~*\'():@&=+$,-]|%[[:digit:]a-fA-F][[:digit:]a-fA-F])*)*" \
  "(/([[:alnum:]_.!~*\'():@&=+$,-]|%[[:digit:]a-fA-F][[:digit:]a-fA-F])*" \
  "(;([[:alnum:]_.!~*\'():@&=+$,-]|%[[:digit:]a-fA-F][[:digit:]a-fA-F])*)*" ")*" ")" \
  /* query (opt) */ \
  "(\\?([[:alnum:]_.!~*\'():@&=+$,;/?:@&=+$,-]|%[[:digit:]a-fA-F][[:digit:]a-fA-F])*)?$";

MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::URIHelper(void) : proto(UNDEFINED), portnum(-1) {
}

MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::URIHelper(const string& uri) : proto(UNDEFINED), portnum(-1) {
  init(uri);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::init(const string& uri) {
  string str=trim(uri);
    if (!parseURI(str)) {
      ostringstream err;
      err << "URI is not syntatically correct '" << uri << "'";
      throw std::exception();
   }
  if (protocol == "file") {
    proto=FILE;
  }
  else if (protocol == "http" || protocol == "https") {
    proto=HTTP;
  }
  else if (protocol == "ftp" || protocol == "ftps") {
    proto=FTP;
  }
  else if (!protocol.empty()) {
    ostringstream err;
    err << "Protocol not supported: '" << protocol << "'";
    throw std::exception();
  }
  if (!port.empty())
    fromString<int>(portnum,port);
}

bool MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::parseURI(const string& uri) {
  regex_t reg;
  regmatch_t match[NMATCH];

  if(uri.empty())
    return false;

  int ret1=regcomp(&reg, URIREGEX, REG_EXTENDED);
  int ret2=regexec(&reg, uri.c_str(), NMATCH, match, 0);
  regfree(&reg);

  if(ret1 != 0 || ret2 != 0) {
    return false;
  }

  if (match[SCHEME_NUM].rm_so > -1) {
    char temp[match[SCHEME_NUM].rm_eo-match[SCHEME_NUM].rm_so+1];
    memset(temp,0,match[SCHEME_NUM].rm_eo-match[SCHEME_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[SCHEME_NUM].rm_so,
	     match[SCHEME_NUM].rm_eo-match[SCHEME_NUM].rm_so);
    protocol.assign(temp);
  }

  if (match[USERINFO_NUM].rm_so > -1) {
    char temp[match[USERINFO_NUM].rm_eo-match[USERINFO_NUM].rm_so+1];
    memset(temp,0,match[USERINFO_NUM].rm_eo-match[USERINFO_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[USERINFO_NUM].rm_so,
	     match[USERINFO_NUM].rm_eo-match[USERINFO_NUM].rm_so);
    userinfo.assign(temp);
  }

  if (match[HOST_NUM].rm_so > -1) {
    char temp[match[HOST_NUM].rm_eo-match[HOST_NUM].rm_so+1];
    memset(temp,0,match[HOST_NUM].rm_eo-match[HOST_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[HOST_NUM].rm_so,
	     match[HOST_NUM].rm_eo-match[HOST_NUM].rm_so);
    host.assign(temp);
  }

  if (match[PORT_NUM].rm_so > -1) {
    char temp[match[PORT_NUM].rm_eo-match[PORT_NUM].rm_so+1];
    memset(temp,0,match[PORT_NUM].rm_eo-match[PORT_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[PORT_NUM].rm_so,
	     match[PORT_NUM].rm_eo-match[PORT_NUM].rm_so);
    port.assign(temp);
  }

  if (match[PATH_NUM].rm_so > -1) {
    char temp[match[PATH_NUM].rm_eo-match[PATH_NUM].rm_so+1];
    memset(temp,0,match[PATH_NUM].rm_eo-match[PATH_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[PATH_NUM].rm_so,
	     match[PATH_NUM].rm_eo-match[PATH_NUM].rm_so);
    path.assign(temp);
  }

  if (match[QUERY_NUM].rm_so > -1) {
    char temp[match[QUERY_NUM].rm_eo-match[QUERY_NUM].rm_so+1];
    memset(temp,0,match[QUERY_NUM].rm_eo-match[QUERY_NUM].rm_so+1);
    strncpy(temp, uri.c_str() + match[QUERY_NUM].rm_so,
	     match[QUERY_NUM].rm_eo-match[QUERY_NUM].rm_so);
    query.assign(temp);
    retrieveQueryComponents();
  }

  return true;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::tokenize(const string& str, vector<string>& tokens,
              const string& delimiters, bool keepEmptyTokens) {
  // Cleanup
  tokens.clear();

  string::size_type lastPos=0;
  
  // Find first delimiter
  string::size_type pos=str.find_first_of(delimiters,lastPos);
  while (pos != string::npos) {
    // Found a token, add it to the vector
    if (pos!=lastPos) {
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      lastPos=pos+1;
    }
    else {
      if(keepEmptyTokens) 
        tokens.push_back("");
      lastPos++;
    }
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
  if (lastPos!=str.size()) {
    tokens.push_back(str.substr(lastPos));
  } else {
    if(keepEmptyTokens) 
      tokens.push_back("");
  }
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::retrieveQueryComponents(void) {
  size_t found=query.find_first_of("?");
  string parameters(query.substr(found+1));
  /*
  cout << "---> " << query << endl;
  cout << "---> " << parameters << endl;
  */
  vector<string> tokens;
  tokenize(parameters,tokens,"&",false);
  for(vector<string>::const_iterator i=tokens.begin(); i!=tokens.end(); ++i) {
    vector<string> nameValue;
    /*
    cout << "-----> " << *i << endl;
    */
    tokenize(*i,nameValue,"=",false);
    if (nameValue.size()==1)
      qc.nameValuePairs.insert(make_pair(trim(nameValue[0]),""));
    else if (nameValue.size()==2)
      qc.nameValuePairs.insert(make_pair(trim(nameValue[0]),trim(nameValue[1])));
  }
}

bool MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::isMulticastAddress(void) const {
  size_t found=host.find_first_of(".");
  if (found==string::npos)
    return false;
  string fstoctet(host.substr(0,found));
  /*
  cout << fstoctet << endl;
  */
  try {
    short octet;
    fromString(octet,fstoctet);
    if (octet>=224 && octet<=239)
      return true;
  }
  catch(...) {
    // whatever!
  }
  return false;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper::print(ostream& o) const {
  o << "protocol: '" << protocol
    << "' userinfo: '" << userinfo
    << "' host: '" << host
    << "' port: '" << port
    << "' path: '" << path
    << "' query: '" << query
    << "'";
}

ostream& operator<< (ostream& o, const MY_OPERATOR_SCOPE::MY_OPERATOR::URIHelper& uri) {
  uri.print(o);
  return o;
}



// This macro wraps the specified line of 'code' in an 'if' block that executes
// only if the application's tracing level is at least as high as the specified 'level'.
// Note that this macro should be defined in '.../system/impl/include/TRC/DistilleryDebug.h'
// or '.../include/SPL/Runtime/Common/RuntimeDebug.h'.

#define SPLAPPTRC_CODE(level, code) do { \
  int ilvl = Distillery::debug::EXTERNAL_DEBUG_LEVEL_MAP_TO_INTERNAL[level]; \
  if ( __builtin_expect( (ilvl <= Distillery::debug::app_trace_level) , 0 ) ) \
  { \
    code ; \
  } \
} while(0)


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), 
    relFileProtocol("file:///"),
    absFileProtocol("file:////"),
    retrievers_(),
    timeout_(0),
    retCodeCounts_(),
    inputLinesPerRecord_(1), 
    intraRecordPadValue_(" "), 
    fetchInterval_(lit$3), 
    punctPerFetch_(false), 
    iterations_(0), 
    iteration_(0), 

    emitTuplePerRecordCount_(1),

   dynamicURL_(false)
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::addRetriever(const std::string&  url, const int timeout) {

      SPLAPPTRC(L_DEBUG, "Using '" << url << "' as a target URL ...","InetSource");

      // allocate a curl object for this URL
      InetRetriever* retriever = new InetRetriever(url, timeout);

      // enable tracing in curl object if this operator is tracing
      SPLAPPTRC_CODE( L_TRACE, retriever->enableCurlTrace() );


      retriever->incrementalFetch(lit$2);


      std::pair<int, uint32_t> retcodeCount (0, 0);
      retrievers_.push_back(retriever);
      retCodeCounts_.push_back(retcodeCount);
     
}

std::string MY_OPERATOR_SCOPE::MY_OPERATOR::checkURI(const std::string & url) {
    URIHelper uri;
    try
    {
      // Ensure that the URI is correctly formatted
      uri.init(url);
    }
    catch(DistilleryException& e) 
    {
      // Malformed input URL -- log error and return empty string
      SPLAPPTRC(L_ERROR, "malformed URL " << url, "InetSource");
      return std::string();
    }
    catch(std::exception& e) 
    {
      // Malformed input URL -- log error and return empty string
      SPLAPPTRC(L_ERROR, "malformed URL " << url, "InetSource");
      return std::string();
    }

    if((url.compare(0, 8, relFileProtocol) == 0) && (url.compare(0, 9, absFileProtocol) != 0))
    // The URI was declared as a relative path/filename (relative to the PE's data directory).
    // Compute the absolute path/filename and assign it back to URL. 
    {
      string iFileName;
      iFileName.assign(uri.getPath());
      trim(iFileName);

      // get the real path (i.e. resolve any symlinks to actual filename)
      char* rp = new char[PATH_MAX+1];
      memset(rp, 0x00, PATH_MAX+1);

      string rn;
      if(realpath(iFileName.c_str(), rp))
      {
        rn = string(rp);
      }
      delete [] rp;

      string inputFileName;
      if(iFileName == rn)
      {
        inputFileName = rn;
      }
      else
      {
        inputFileName.append(getPE().getDataDirectory());
        inputFileName.append("/").append(iFileName);
      }

      std::string newURL(relFileProtocol);
      newURL.append(inputFileName);
      return newURL;
    }
    else {
        return url;
    }
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
  for(std::size_t i = 0; i < retrievers_.size(); i++)
  {
    InetRetriever* retriever = retrievers_.at(i);
    delete retriever;
  }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
  createThreads(1); // for now, single-threaded only
}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
  SPLAPPTRC(L_TRACE, "Shutdown Request event received by PE " << getContext().getName(), "InetSource");
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
  SPLAPPTRC(L_TRACE, "Processing...", "InetSource");

  bool ignoreURIcheckException = false;
  std::string fetchContent; // content fetched from URL
  std::istringstream fetchBuffer; // buffer of content fetched from URL






  // initial delay
  getPE().blockUntilShutdownRequest(lit$1);

  
  bool firstTime = true;
  while(!getPE().getShutdownRequested())
  {

    if (dynamicURL_ || firstTime) {
      firstTime = false;

      // Make the list with the checked uris to get the real number of required retrievers
      SPL::list<SPL::rstring> newURIChecked;
      {
        // get list or URIs
        SPL::list<SPL::rstring> newURI = lit$0;
        bool oops = false;
        for (std::size_t i = 0; i < newURI.size(); i++) {
          std::string uri = checkURI(newURI.at(i));
          if (uri.length()==0) {
            if (ignoreURIcheckException) {
              uri = newURI.at(i);
              SPLAPPTRC(L_WARN, "Use uri after failed uri check! URL=" << uri, "InetSource");
            } else {
              oops = true;
              SPLAPPTRC(L_ERROR, "ignoring malformed URL=" << newURI.at(i), "InetSource");
              continue;
            }
          }
          newURIChecked.push_back(uri);
        }
        // terminate if any of the URIs are invalid and won't change, otherwise continue with valid URIs
        if ( oops && !dynamicURL_ ) {
          SPLAPPTRC(L_ERROR, INET_MALFORMED_URI, "InetSource");
          SPL::Functions::Utility::abort(__FILE__, __LINE__);
        }
      }

      // delete retrievers we won't need.
      while (retrievers_.size() > newURIChecked.size()) {
        // save it so we can delete it.
        InetRetriever* last = retrievers_.back();
        retrievers_.erase(retrievers_.end() -1, retrievers_.end());
        retCodeCounts_.erase(retCodeCounts_.end() -1, retCodeCounts_.end());
        delete last;
      }

      // If there's a retriever, re-use it.
      for (std::size_t i = 0; i < retrievers_.size() ; i++)  {
        if (retrievers_.at(i)->updateURL(newURIChecked.at(i))) {
          SPLAPPTRC(L_INFO, "URL " << i << " updated to " << retrievers_.at(i)->targetURL(), "InetSource");
        }
        else {
          SPLAPPTRC(L_DEBUG,"URL " << i << " re-evaluated, but is unchanged ", "InetSource");
        }
      } // end -- check URLs in list of 'retrievers' 

      // add a retriever for a new URI
      for (std::size_t i = retrievers_.size(); i < newURIChecked.size(); i++) {
        addRetriever(newURIChecked.at(i), timeout_);
      }
    } // end -- if 'dynamicURL_' or 'firstTime'

    // now fetch content from each 'retriever' and emit zero or more tuples containing its data
    for(std::size_t i = 0; i < retrievers_.size() && !getPE().getShutdownRequested(); i++)
    {

      // point at the next 'retriever' object
      retriever_ = retrievers_.at(i);
      SPLAPPTRC(L_DEBUG, "getting URL " << retriever_->targetURL() << " ...","InetSource");

      // fetch content from this URL 
      try
      {
        fetchContent = retriever_->fetch();
      }
      catch(CURLcode rc)
      {
        std::pair<int,uint32_t> & retcodeCount = retCodeCounts_.at(i);
        // Keep track of how many times in a row a given retriever has issued the same return code
        // This avoids filling up the log with repetitive messages.
        if (retcodeCount.first == rc)
        {
          (retcodeCount.second)++;
        }
        else
        {
          retcodeCount.first = rc;
          retcodeCount.second = 1;
        }
        
        if (retcodeCount.second < 10)
        {
          SPLAPPLOG(L_ERROR, "URL " << retriever_->targetURL() << " failed, " << string(curl_easy_strerror(rc)) << " (libcurl error code " << rc << ")", "InetSource");
        }
        else if (retCodeCounts_.at(i).second % 10 == 0) {
          SPL::rstring msg = INET_NONZERO_LIBCURL_RC_REPEATED(retriever_->targetURL(), rc, string(curl_easy_strerror(rc)), retcodeCount.second);
          SPLAPPLOG(L_WARN, msg, "InetSource");
        }
        continue;
      }

      SPLAPPTRC(L_DEBUG, "got " << fetchContent.length() << " bytes from URL " << retriever_->targetURL() << " ...","InetSource");





        /*
         * Split retrieval buffer into separate "input records", each record containing
         * "inputlinesPerRecord" lines from the original file, separated by the "intraRecordPadValue"
         * value (default pad value is a single blank char)
         */
        
        // load fetched content into an 'std::istringstream' buffer, from which it will be parsed into lines

        fetchBuffer.clear(); // also clears eof bit
        fetchBuffer.str(fetchContent);

        // Start of loop here, one loop cycle per input record, until retrieval buffer is exhausted

          while(!fetchBuffer.eof())  {
              string record;
              getline(fetchBuffer,record);
      
              // if there's no data left, we should exit this loop
              if(fetchBuffer.eof() && record.size() == 0) {
                 break;
              }

           if(inputLinesPerRecord_ > 1)
            {
              /*
               * Here, the user asked for multiple lines per record, so append the contents of the additional
               * lines, interspersing a pad value before each append.  (Note, a value less than 1 means
               * "put all lines in a single record.")
               */
              string line;
              for(int lc=1; lc<inputLinesPerRecord_ && !fetchBuffer.eof(); ++lc)
              {
                getline(fetchBuffer, line);
                if(line.size() > 0 && !fetchBuffer.eof())
                {
                  if(record.size() > 0)  // append the pad value if and only if the previous line had content
                  {
                    record.append(intraRecordPadValue_);
                  }
                  record.append(line);
                }
              }
            }
            else if(inputLinesPerRecord_ == 0)
            {
              string line;
              while(!fetchBuffer.eof())
              {
                getline(fetchBuffer, line);
                if(line.size() > 0)
                {
                  if(record.size() > 0)  // append the pad value if and only if the previous line had content
                  {
                    record.append(intraRecordPadValue_);
                  }
                  record.append(line);
                }
              }
            }
    
            // Now that the record has been formed, do the following:
    




            /*
             * Here, the output attribute is a rstring, so assign the record to the rstring tuple
             * attribute and submit the tuple.  If the resulting attribute would exceed 2^31-1 in
             * length, fragment it into multiple tuples each 2^31-1 or less in length.  (This is to avoid
             * the SPL limit of (2^31 - 1) on string size in tuples.)
             */
            while(true)
            {
              outputTuple.clear();
              string limitStr = record.substr(0, 2147483647); // gets entire record if size < 2^31-1
              outputTuple.set_web_rec(limitStr);
              
 ;
              SPLAPPTRC(L_TRACE, "Submitting output tuple with 'rstring' data attribute " << outputTuple, "InetSource");
              submit(outputTuple, 0);
              if(limitStr.size() < record.size()) // did fragmentation occur?
              {
                record = record.substr(limitStr.size());
              }
              else break; // when there is no fragmentation, we are done
            }



          } // end -- split fetched content into records
















    } // end -- fetch content from list of 'retrievers'





    
    if(punctPerFetch_) {
      // punctPerFetch was requested -- so emit a punctuation here
      submit(Punctuation::WindowMarker, 0);
    }



    // if we are not iterating endlessly, increment iteration counter and break out of loop when limit is reached
    if ( iterations_ != 0 && ++iteration_ >= iterations_ ) break;

    // Now pause until it is time to perform the next fetch
    SPLAPPTRC(L_DEBUG, "waiting " << fetchInterval_ << " seconds before repeating fetches", "InetSource");
    getPE().blockUntilShutdownRequest(fetchInterval_);

  } // end -- while !getPE().getShutdownRequested()


  // emit final punctuation after last fetch iteration
  submit(Punctuation::FinalMarker, 0);

  SPLAPPTRC(L_TRACE, "Processing complete", "InetSource");
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Web",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    addParameterValue ("URIList", SPL::ConstValueHandle(lit$0));
    addParameterValue ("initDelay", SPL::ConstValueHandle(lit$1));
    addParameterValue ("incrementalFetch", SPL::ConstValueHandle(lit$2));
    addParameterValue ("fetchInterval", SPL::ConstValueHandle(lit$3));
    (void) getParameters(); // ensure thread safety by initializing here
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}



