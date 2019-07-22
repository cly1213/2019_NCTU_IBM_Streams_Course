// eJzFkU9z2jAQxUdfhekhvdiKSduEm7HzBxtIimCgXBhZ3gENtqSR1nXcT19BSSCnHDs6aff33rydJ3QdyKIOHFrgtQvKYjB4TodJbAyoklwT6t816QVBiJ2BcAhZa53Y0rvuLmes382TfTR9GjVj9iP7Qyne7n9P5oLS6Wj4_0nOVP8aL1becr7JsGRvWbZ_1yx3u_0yNg6fZi5e9PNluukqCvBPPFrUenJNG73iyxZVxv6nS2zUR6PbzY04TzY9Y5hSLjTNYRQNlEUttruneECwohuDrk3vA1LjpworYCSPhFaKRAotUq1aGpQ6M9hL_0PBwPqbpdp6y8vvVe_0oD1Pe3YRnsQte66r3lcToqaJBeLAAF_0afmU665J31Nv7jkPssXAhw7jN1ayXCXD_1bEuwMXFOhm_1OigkunQ1XSaItfTur_1VxWRxP7ritySY_0hRSaTCfkSSxqGvz055DeTt3LfhO_1ViddkI_1ACdZheMFOct20lzKJchx8adkMPQ_0G3K8UzSv3LpPXR



#include <SPL/Runtime/Type/SPLType.h>
#include <sqlcli.h>
#include <sqlcli1.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Common/Metric.h>
#include "DatabaseToolkitResource.h"


#ifndef SPL_OPER_INSTANCE_ODBCAPPEND_3_H_
#define SPL_OPER_INSTANCE_ODBCAPPEND_3_H_

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

#include "../type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.h"


#define MY_OPERATOR ODBCAppend_3$OP
#define MY_BASE_OPERATOR ODBCAppend_3_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Tuple const & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$connectionDocument$0;
    SPL::rstring param$connection$0;
    SPL::rstring param$access$0;
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


class MY_OPERATOR : public MY_BASE_OPERATOR 
  
{
public:
  // constructor
  MY_OPERATOR();

  // destructor
  virtual ~MY_OPERATOR(); 

  // notify port readiness
  void allPortsReady(); 

  // notify termination
  void prepareToShutdown(); 

  // processing for source and threaded operators   
  void process(uint32_t idx);
    
  // tuple procressing for mutating ports 
  void process(Tuple & tuple, uint32_t port);
    
  // tuple processing for non-mutating ports
  void process(Tuple const & tuple, uint32_t port);

  // punctuation processing
  void process(Punctuation const & punct, uint32_t port);

private:
  // methods

  bool attemptODBCConnection();
  bool establishODBCConnection();
  bool resetODBCConnection();

  
  // members

      
  // SQL Environment and Statement handles
  SQLHDBC     hdbc;
  SQLHENV     henv;
  SQLHSTMT    hstmt[1];
  SQLSMALLINT stmtcols;
  RETCODE     rc;
  // SQL Connection Information variables
  std::string connectionDatabase;
  std::string connectionUser;
  std::string connectionPassword;

  // Metrics
  Metric *droppedTuples_;



  // SQL Bind Parameter declarations
  SQLINTEGER orderidParam1 [1][1];
  SQLINTEGER customernameParam2Length[1][1];
  SQLCHAR customernameParam2 [1][51];
  SQLINTEGER customeridParam3 [1][1];
  SQLINTEGER productnameParam4Length[1][1];
  SQLCHAR productnameParam4 [1][51];
  SQLINTEGER productidParam5 [1][1];
  SQLINTEGER priceParam6Length[1][1];
  SQLCHAR priceParam6 [1][11];
  SQLINTEGER shipmentstatusParam7 [1][1];
  SQLINTEGER shippingdateParam8Length[1][1];
  SQLCHAR shippingdateParam8 [1][51];


  // DB Toolkit Exception Definition
  class ODBCOperatorShutdownException : public std::exception
  {
    public:
    const char* what() const throw() { return "Unable to connect to database"; }
  };
  // Inline Helper Functions
  
  // Generic SQL Function Return Code Handler
  const bool handleSQLRC(SQLSMALLINT htype, SQLHANDLE hndl, RETCODE rc)
  {
    switch (rc)
    {
      case SQL_SUCCESS:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_SUCCESS", SPL_OPER_DBG);
        return true;
      case SQL_SUCCESS_WITH_INFO:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_SUCCESS_WITH_INFO", SPL_OPER_DBG);
        logSQLError(htype, hndl);
        return true;
      case SQL_STILL_EXECUTING:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_STILL_EXECUTING", SPL_OPER_DBG);
        return true;
        case SQL_NEED_DATA:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_NEED_DATA", SPL_OPER_DBG);
        return true;
      case SQL_NO_DATA_FOUND:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_NO_DATA_FOUND", SPL_OPER_DBG);
        return true;
      case SQL_INVALID_HANDLE:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: INVALID_HANDLE", SPL_OPER_DBG);
        return false;
      case SQL_ERROR:
        SPLAPPTRC(L_DEBUG, "CLI Return Code: SQL_ERROR", SPL_OPER_DBG);
        logSQLError(htype, hndl);
        SPLAPPLOG(L_ERROR, DB_ODBC_FAILURE, SPL_OPER_DBG);
        return false;
      default:
        SPLAPPTRC(L_DEBUG, "UNKNOWN RETURN CODE: " << rc , SPL_OPER_DBG);
        return false;
      }
    }
    
    // Generic SQL Function Diagnostic Record Processor
    void logSQLError(SQLSMALLINT htype, SQLHANDLE hndl)
    {
      SQLCHAR message[SQL_MAX_MESSAGE_LENGTH + 1];
      SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
      SQLINTEGER sqlcode;
      SQLSMALLINT length, i;

      i = 1;
      while (SQLGetDiagRec(htype,
                           hndl,
                           i,
                           sqlstate,
                           &sqlcode,
                           message,
                           SQL_MAX_MESSAGE_LENGTH + 1,
                           &length) == SQL_SUCCESS)
      {
        std::string msg = DB_ODBC_ERROR((const char*)sqlstate, (int32_t) sqlcode, (const char*)message);
        SPLAPPLOG(L_ERROR, msg, SPL_OPER_DBG);
        i++;
      }
    }


}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_ODBCAPPEND_3_H_


