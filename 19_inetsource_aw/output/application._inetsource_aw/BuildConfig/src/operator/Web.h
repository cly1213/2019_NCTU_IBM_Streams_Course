// eJx9kWFLwzAQhrl_1IsPPTdMNoUWEypxUq6jVD34qaXezwTQp6dW6f2_1WdoJFJRDCe_09xz5srTe3JovZasijq9tOTGimKEndnprMlAgffHQ4Lz2O0b5Bd4k1v77I_0SP3wXsrw9vnxNb5e91ex9qqF865ASTr1IXtIo0jJls6Hl3UzpH47uYChzsf6ThlBZ6tRC0atMEah0KO2nPmAVaZGhtsuCFhv7HvbiBIZD_1MDejtA56JnW0ECtNF4AHp5SlIHAvxvKD5Rx_0SUoiPcWESQWtIaldjDjJdPIeb20mKNmoTaIJXVseuYiE8xf3btDtZEE9oPoX4ftJy1_0MNeTGPs90_1_1sxeowbqGHovcYglTaPD9L7ZaJ4g

#include <vector>
#include<map>
#include<sstream>
#include <iostream>
#include <sstream>
#include <string>
#include <InetResource.h>

extern "C"
  {
#include<curl/curl.h>
  }





#ifndef SPL_OPER_INSTANCE_WEB_H_
#define SPL_OPER_INSTANCE_WEB_H_

#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSw2L09Nii9KTQYAGDwEAn.h"


#define MY_OPERATOR Web$OP
#define MY_BASE_OPERATOR Web_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw2L09Nii9KTQYAGDwEAn OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::list<SPL::rstring > lit$0;
    SPL::float64 lit$1;
    SPL::boolean lit$2;
    SPL::float64 lit$3;
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};





typedef std::map<std::string, std::string> URIQueryComponentsNVP_t;
typedef std::map<std::string, std::string>::iterator URIQueryComponentsNVP_it_t;
typedef std::map<std::string, std::string>::const_iterator URIQueryComponentsNVP_cit_t;

/// Return the input string with spaces suffixing it being removed
/// @param str input string
/// @param t character to be removed from right side of input string
/// @return input string without spaces suffixing it
inline std::string rtrim(const std::string& source,
  const std::string& t=" ") {
  std::string str=source;
  return str.erase(str.find_last_not_of(t)+1);
}

/// Return the input string with spaces prefixing it being removed
/// @param str input string
/// @param t character to be removed from left side of input string
/// @return input string without spaces prefixing it
inline std::string ltrim(const std::string& source,
  const std::string & t = " " ) {
  std::string str = source;
  return str.erase (0,source.find_first_not_of(t));
}

/// Return the input string with spaces suffixing and prefixing it being
/// removed
/// @param str input string
/// @param t character to be removed from left and right sides of input string
/// @return input string without spaces prefixing and suffixing it
inline std::string trim(const std::string& source,
  const std::string& t=" ") {
  std::string str=source;
  return ltrim(rtrim(str,t),t);
}



/// Converts a string to a different (numerical) type
/// @param t converted value
/// @param s input string
template <class T> void fromString(T& t, const std::string& s) {
  if (s.empty()) {
    t=static_cast<T>(0);
  }
  else {
    std::istringstream iss(s);
    iss >> t;
    if (iss.fail())
      //THROW(FailedConversion,"string '" << s << "' conversion failed");
      throw std::exception();
    if (!iss.eof())
      throw std::exception();
      //      THROW(SpuriousCharacterFound,"string '" << s << "' contains spurious character");
  }
}

class MY_OPERATOR : public MY_BASE_OPERATOR 
{
public:

/*
*******************************************************************************
* Copyright (C) 2009,2012-2014, International Business Machines Corporation. 
* All Rights Reserved. *
*******************************************************************************
*/

//
// Class Description:
//
// Mean to be included in CGT file.

  /*
   * This class interacts with the cURL library, holding the contents of the file being retrieved and providing
   * a callback function for cURL to invoke when data is available from the file retrieval
   *
   * Preconditions: curl_global_init() has already been called before constructing objects of this type
   *
   * Postconditions: curl_global_cleanup() must be called after all objects of this type are destructed
   *
   */
class InetRetriever
  {


public:
  /*
   *  Constructor
   *
   * url        The URL, including protocol designation, of the target to be retrieved.
   *            This value may not be altered after the object has been constructed.
   *
   * Throws:    An integer if there was a problem during the construction of this object.
   *            Typically, this indicates that an error occurred during initialization of the
   *            cURL library used by this object.
   *            If the constructor throws an exception, the results from further use of the
   *            object are unpredictable.
   */
  InetRetriever(const std::string& url, const int timer=0) throw(int);

  virtual ~InetRetriever();

  /*
   * Clear all internal buffers, and reset byte counters to zero.
   */
  void reset();

  /*
   * Retrieve the contents of the targURL previously supplied to the constructor, subject to
   * options previously set with the ignoreLastModTime() and/or incrementalFetch() methods.
   *
   * Returns:   A string containing the entire contents of the target, including any
   *            embedded newline characters.
   *
   * Throws:    The cURL return code from the fetch, if it is nonzero.
   */
  std::string fetch() throw(CURLcode);

  std::string lastknownContents() const;

  size_t bytesTransferredTotal();
  size_t bytesTransferredLastFetch();

  void enableCurlTrace();
  void disableCurlTrace();

  std::string targetURL() const;
  std::string effectiveURL() const;
  std::string contentType() const;
  long responseCode() const;
  double fetchTime() const;

  // Returns true if the URL was updated, false if it stayed the same.
  bool updateURL(std::string newURL);

  void ignoreLastModTime();
  void ignoreLastModTime(bool whether);

  void incrementalFetch();
  void incrementalFetch(bool whether);

  /*
   * To be used for calling certain curl_easy_setopt() and/or curl_easy_getinfo() functions ONLY.
   * In addition, the following curl_easy_setopt() options *shall not* be called by users; if they
   * are called, the results are unpredictable:
   * - Any whose name ends with FUNCTION or DATA (e.g. WRITEFUNCTION, WRITEDATA, and so on)
   * - CURLOPT_URL, CURLOPT_FILETIME, CURLOPT_TIMECONDITION, CURLOPT_TIMEVALUE
   *
   */
  CURL* curlHandle();

private:
  static
  size_t consumeData_static(void* buffer, const size_t recSize,
      const size_t numRecs, void* objPtr);

  /*
   *  Callback function -- called by cURL when it has data to supply
   */
  size_t consumeData(const void* data, const size_t recSize,
      const size_t numRecs);

  // Disallow copying and assignment of this object (it doesn't make sense semantically)
  InetRetriever(const InetRetriever& cr);

  InetRetriever& operator=(const InetRetriever& cr);

  /*
   *  Instance variables
   */

  size_t        _bytesTransferredTotal, _bytesTransferredLastFetch;
  std::string   _targetURL, _effectiveURL, _contentType, _curlBuffer, _fileCache;
  long          _lastModTime;
  int           _timeout, _responseCode;
  double        _fetchTime;
  bool          _ignoreLastModTime, _incrementalFetch, _dataCameBack;
  CURL*         _curlHandle;

  }; // Class InetRetriever

/*
*******************************************************************************
* Copyright (C) 2007,2012-2014, International Business Machines Corporation. 
* All Rights Reserved. *
*******************************************************************************
*/

// Class Description:
//
// Contains the code for URIHelper, which is used by the InetSource operator.  This
// file is meant to be included in a CGT file and cannot be compiled standalone.


class URIQueryComponents {
  public:
    URIQueryComponentsNVP_t nameValuePairs;
  public:
    /// Print internal state to an output stream
    /// @param o output stream
    void print(std::ostream& o) const;
  friend std::ostream& operator<< (std::ostream& o, const URIQueryComponents& qc);
};

class URIHelper {
  public:
    enum ProtocolType {
      UNDEFINED = -1,
      FILE = 8,
      HTTP = 9,
      FTP = 10
    };

    /// Default constructor
    URIHelper(void);

    /// Construct a valid URI
    /// @param uri a string with the URI
    URIHelper(const std::string& uri);

    /// Initialize an empty URI object
    /// @param uri a string with the URI
    void init(const std::string& uri);

    /// Retrieve the protocol specified as part of the URI
    /// @return the protocol
    inline ProtocolType getProtocol(void) const { return proto; };

    /// Retrieve the protocol specified as part of the URI
    /// @return the protocol
    inline const std::string& getProtocolName(void) const { return protocol; };

    /// Retrieve the host specified as part of the URI
    /// @return the host
    inline const std::string& getHost(void) const { return host; };

    /// Return whether the host is a multicast address
    /// @return true or false
    bool isMulticastAddress(void) const;

    /// Retrieve the user information specified as part of the URI
    /// @return the user info
    inline const std::string& getUserInfo(void) const { return userinfo; };

    /// Retrieve the port number specified as part of the URI
    /// @return the port number
    inline int getPort(void) const { return portnum; };

    /// Retrieve the path specified as part of the URI
    /// @return the path
    inline const std::string& getPath(void) const { return path; };

    /// Retrieve the query specified as part of the URI
    /// @return the query
    inline const std::string& getQuery(void) const { return query; };

    /// Retrieve a reference to the internal URIQueryComponents object
    /// @return a reference to the underlying URIQueryComponents object
    const URIQueryComponents& getQueryComponents(void) const {
      return qc;
    };

    /// Retrieve a reference to the name-value pairs in the underlying
    /// URIQueryComponents object
    /// @return a reference to the collection of name-value pairs
    const URIQueryComponentsNVP_t& getQCNameValuePairs(void) const {
      return qc.nameValuePairs;
    };


    /// Tokenize a string
    /// @param str string to be tokenized
    /// @param tokens vector with the list of tokens
    /// @param delimiters string with the characters delimiting each token
    /// @param keepEmptyTokens keep empty tokens
    void tokenize(const std::string& str, std::vector<std::string>& tokens,
              const std::string& delimiter, bool keepEmptyTokens) ;

    /// Destructor
    ~URIHelper(void) {};
  protected:
    enum {
      SCHEME_NUM = 2,
      USERINFO_NUM = 4,
      HOST_NUM = 5,
      HOSTNAME_NUM = 6,
      IPV4ADDR_NUM = 10,
      PORT_NUM = 12,
      PATH_NUM = 13,
      QUERY_NUM = 21,
      NMATCH = QUERY_NUM+1
    };

    /// Parse a URI into its components
    /// @param uri the string with the URI to be parsed
    /// @return true if the string was properly formatted as an URI
    bool parseURI(const std::string& uri);

    /// Retrieve the query components from the query string and
    /// build URIQueryComponents object
    void retrieveQueryComponents(void);

    /// Print internal state to an output stream
    /// @param o output stream
    public: 
    void print(std::ostream& o) const;
    protected: 
    ProtocolType proto;
    std::string protocol;
    std::string userinfo;
    std::string host;
    int portnum;
    std::string port;
    std::string path;
    std::string query;
    URIQueryComponents qc;

    static const char* URIREGEX;
    friend std::ostream& operator<< (std::ostream& o, const URIHelper& uri);
};


public:

  // ----------- standard operator methods ----------

  MY_OPERATOR();
  virtual ~MY_OPERATOR(); 
  void allPortsReady(); 
  void prepareToShutdown(); 
  void process(uint32_t idx);

  // ----------- ???? ----------

  //???MY_OPERATOR(const MY_OPERATOR& op);
  //???MY_OPERATOR& operator=(const MY_OPERATOR& op);

  // ----------- InetSource operator methods  ----------

  void addRetriever(const std::string & url, int timeout);
  std::string checkURI(const std::string & url);

private:

  // ----------- operator state variables ----------

  std::string relFileProtocol;
  std::string absFileProtocol;
  std::vector<InetRetriever*> retrievers_;
  InetRetriever* retriever_;
  int timeout_;
  std::vector<std::pair<int,uint32_t> > retCodeCounts_;
  uint32_t inputLinesPerRecord_;
  SPL::rstring intraRecordPadValue_;
  SPL::float64 fetchInterval_;
  bool punctPerFetch_;
  int32_t iterations_;
  int32_t iteration_;
  uint32_t emitTuplePerRecordCount_;
  bool dynamicURL_;

  // ----------- operator output tuple ----------

  OPort0Type outputTuple;

  // ----------- assignment functions for output attributes ----------

  SPL::rstring TargetURL() { return retriever_->targetURL(); }
  SPL::rstring EffectiveURL() { return retriever_->effectiveURL(); }
  SPL::rstring ContentType() { return retriever_->contentType(); }
  SPL::int32 ResponseCode() { return retriever_->responseCode(); }
  SPL::float64 FetchTime() { return retriever_->fetchTime(); }

}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_WEB_H_


