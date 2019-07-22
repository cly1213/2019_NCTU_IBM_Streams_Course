// eJylkEFvgkAQhTN_1xfQMy2pSw42ibSqittA06YVsYap0kSW7sxL89V2amOq5mcvMy8u8b8Z0jScq0RHqMMzjXaasLhECYK44TDzPp6FD_1wFXvU4zyfO57b7TuT5njOdMUrmUJnP9MBRBkqdFkCbnj5VTbPSykO8R495hcrNn0JtnNU3YjBJpKJWn7fB23iT9Mtru_0qd4M_1qZI2hqumOQ7dZhaOuWphwA_1IM6oo_0V5dzvlZamEyX6wX3h0AvR_05UgAa1qcYTXqhkvyVQpkV7HgYFBfUINsTWkjuvanS0a6JSm0XgVdYmPiHT9aQkfNeIvFgM1_0i9o_13gMHEHDDL6aoWit642LavcuoMJuIQivFKXrfd3eWAz9jewHE8eNCE




#include "./Flight.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Flight_Base
#define MY_OPERATOR Flight$OP



#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>


#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <streams_boost/iostreams/device/file_descriptor.hpp>

#include <SPL/Runtime/Common/ApplicationRuntimeMessage.h>
#include <SPL/Toolkit/IOHelper.h>
#include <SPL/Toolkit/RuntimeException.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>

using namespace std;
using namespace streams_boost::iostreams;


// defines for error checking conditions
#define CHECK_FAIL      \
    if (failedRead)                                   \
        _numInvalidTuples.incrementValueNoLock()

    #define DO_ERROR(msg)                             \
        do { \
         \
          _numInvalidTuples.incrementValueNoLock();   \
          SPLTRACEMSGANDTHROW(SPLRuntimeFileSourceOperator, L_ERROR, msg, SPL_OPER_DBG);  \
         \
        } while (0)
    #define DO_ERROR_FILESOURCE(msg) DO_ERROR(msg)
    #define CHECK_ERROR(msg)                          \
        if (fs.fail() && !getPE().getShutdownRequested()) \
            DO_ERROR(msg)


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
    : MY_BASE_OPERATOR(), _fd(0), _tupleNumber(0), 
        
        
        
        
        _numInvalidTuples( getContext().getMetrics().getCustomMetricByName("nInvalidTuples")),
        _numReconnects(getContext().getMetrics().getCustomMetricByName("nReconnections")),
        _numConnections(getContext().getMetrics().getCustomMetricByName("nConnections")),
        _numWireFormatHandshakesFailed(getContext().getMetrics().getCustomMetricByName("nConfirmWireFormatFailures"))
{
    _numInvalidTuples.setValueNoLock(0);
    _numReconnects.setValueNoLock(0);
    _numConnections.setValueNoLock(0);
    _numWireFormatHandshakesFailed.setValueNoLock(0);
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
{
    createThreads (1);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown()
{
    if (_fd) {
        shutdown (_fd, SHUT_RDWR); // try to clean things up nicely
        _fd = 0;
    }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t) 
{
    SPLAPPTRC(L_DEBUG, "TCPSource startup...", SPL_OPER_DBG);
    SPL::BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02 tuple$;
    
    
    try {
        SPL::TCPServer conn (getPE());
        
        
            
            
            
                conn.setup (lit$0);
            
        

        _fd = conn.fileDescriptor();
        SPLAPPTRC(L_DEBUG, "TCPSource connected.  File descriptor = " << _fd, SPL_OPER_DBG);
        _numConnections.setValueNoLock(1);

        
            while (!getPE().getShutdownRequested()) {
        
                // We might have failed due to handshake failure
                if (conn.connected()) {
                    _tupleNumber = 0; 
                    file_descriptor_source fd_src (_fd, never_close_handle);
                    filtering_streambuf<input> filt_str;
                    
                    filt_str.push (fd_src);
                    
                        istream fs (&filt_str);
                    
                    fs.imbue(locale::classic());






bool failedRead = false;
if (getPE().getShutdownRequested()) SPLAPPTRC(L_DEBUG, "shutdown requested", SPL_OPER_DBG);
while(!getPE().getShutdownRequested()) {
   

  


    _tupleNumber++;
  
    if (SPL::safePeek(fs) == EOF) {
      SPLAPPTRC(L_DEBUG, "Break at safePeek(fs) == EOF", SPL_OPER_DBG);
      break;
    }
  

    bool doSubmit = true;
    try {
        
            // ignore comments and empty lines
            fs >> SPL::skipSpaceTabReturnNewLines;
            while (fs.peek() == '#') {
                std::string dummy;
                std::getline (fs, dummy);
                fs >> SPL::skipSpaceTabReturnNewLines;
            }
            
              if (SPL::safePeek(fs)==EOF) break;
            
            failedRead = false;
            



                
                    unsigned char sep;
                
                    SPL::readCSV<SPL::rstring,','>(fs, tuple$.get_fly_num());
                    
                        fs >> SPL::skipSpaceTabs;
                         
                            sep = fs.peek();
                            if (sep != ',') {
                                DO_ERROR (SPL_APPLICATION_RUNTIME_FAILED_READ_CHAR (SPL::printableCharacter(','), SPL::printableCharacter(sep), _tupleNumber, "after reading the attribute fly_num"));
                            }
                            fs >> sep;
                        
                    SPL::readCSV<SPL::rstring,','>(fs, tuple$.get_depDate());
                    
                        fs >> SPL::skipSpaceTabs;
                         
                            sep = fs.peek();
                            if (sep != ',') {
                                DO_ERROR (SPL_APPLICATION_RUNTIME_FAILED_READ_CHAR (SPL::printableCharacter(','), SPL::printableCharacter(sep), _tupleNumber, "after reading the attribute depDate"));
                            }
                            fs >> sep;
                        
                    SPL::readCSV<SPL::rstring,','>(fs, tuple$.get_origin());
                    
                        fs >> SPL::skipSpaceTabs;
                         
                            sep = fs.peek();
                            if (sep != ',') {
                                DO_ERROR (SPL_APPLICATION_RUNTIME_FAILED_READ_CHAR (SPL::printableCharacter(','), SPL::printableCharacter(sep), _tupleNumber, "after reading the attribute origin"));
                            }
                            fs >> sep;
                        
                    SPL::readCSV<SPL::rstring,','>(fs, tuple$.get_dest());
                    
                CHECK_ERROR (SPL_APPLICATION_RUNTIME_FAILED_READ_TUPLE("tuple<rstring fly_num,rstring depDate,rstring origin,rstring dest>", _tupleNumber));
                CHECK_FAIL;
                
                 
                    // Check that we read a complete line

                    int eolSep = fs.get();
		    if (eolSep == EOF) {
		      
                    }
                    else if (eolSep != '\n' && eolSep != '\r') {
                        
                        DO_ERROR (SPL_APPLICATION_RUNTIME_FAILED_READ_CHAR ("\\n", SPL::printableCharacter(eolSep), _tupleNumber, "after reading the attribute dest"));
		    } 
                
            
        



    } catch (const std::exception& e) {
        DO_ERROR(SPL_APPLICATION_RUNTIME_EXCEPTION(e.what()));
        _numInvalidTuples.incrementValueNoLock();
        doSubmit = false;
    } catch (...) {
        DO_ERROR(SPL_APPLICATION_RUNTIME_UNKNOWN_EXCEPTION);
        _numInvalidTuples.incrementValueNoLock();
        doSubmit = false;
    }
    if (doSubmit) {
      
        submit (tuple$, 0);
        SPLAPPTRC(L_TRACE, "Submitted tuple " << _tupleNumber, SPL_OPER_DBG);
      
    }
  

}

                    
                        submit (Punctuation::WindowMarker, 0);
                    
                }
                _numConnections.setValueNoLock(0);

                
        
                _fd = conn.reconnect();
                _numConnections.setValueNoLock(1);
                _numReconnects.incrementValueNoLock();
            }
        
        conn.terminate();
    } catch (...) {
        // If we get here, we had an exception, and the throw will destruct conn.
        // Ensure that we don't try to do it twice.
        _fd = 0; // no longer using this
        throw;
    }
    _fd = 0; // no longer using this
    
    SPLAPPTRC(L_DEBUG, "TCPSource exiting...", SPL_OPER_DBG);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Flight",&initer));
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
    param$role$0 = "server";
    addParameterValue ("role", SPL::ConstValueHandle(param$role$0));
    addParameterValue ("port", SPL::ConstValueHandle(lit$0));
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


