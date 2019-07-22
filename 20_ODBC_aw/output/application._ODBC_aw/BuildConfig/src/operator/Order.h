// eJy1kU1TwjAQhmf_1CuNBL00oiMKtgCjl0ymMjBcmpCt0aBJMUqH_0emOVLy_0cnJw28_06z7_07LlfCShfCM1ciE8eJFozFqN1uRyjRHKAN1rwwlzyM23yBpYrjVA25oPa_13oqiST1prf_1jUzfrRXfhJqb1ffwwmnNJht7l7nvUeg_0nstsdmYfgSbKJ8_0dR7fGDTMHqVgQrebZU1lbcqFTPSxF5RiMb9RuMtVczWqgBAVkogwTjzfbJVem02jCPx6fzb5JxtScwsA6kkUqgCV1Iit4mSbcUzgdI6bkHUbsFELoGeldelop_00WV4lx2bj7URauoHAOtUis9jRiCfwS9BB3jpoHcYVxjLnhXGOxlzqdkHEHa3ESMeoJ2yRYkfpnzxOYYlMbBtTlu95_06PtL3nunhZZqo3Shyv_1Q5YgQEMNCuvd2Hm0Fd_0NbWXGuhz1kAmE49777xPlWKs44_1aP8Pf3TJfwEwX9AoBcONH



#include <SPL/Runtime/Type/SPLType.h>
#include <sqlcli.h>
#include <sqlcli1.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Common/Metric.h>
#include "DatabaseToolkitResource.h"


#ifndef SPL_OPER_INSTANCE_ORDER_H_
#define SPL_OPER_INSTANCE_ORDER_H_

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

#include "../type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.h"


#define MY_OPERATOR Order$OP
#define MY_BASE_OPERATOR Order_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo OPort0Type;
    
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
    
    
    
    SPL::float64 lit$0;
    
    
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
  // members
  // The number of replays of the source query
  int numberOfReplays_;
  bool infiniteReplays_;

  


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


  // SQL Bind Column declarations
  SQLINTEGER orderidCol;
  SQLINTEGER orderidcolLength;
  SQLCHAR customernameCol[51];
  SQLINTEGER customernamecolLength;
  SQLINTEGER customeridCol;
  SQLINTEGER customeridcolLength;
  SQLCHAR productnameCol[51];
  SQLINTEGER productnamecolLength;
  SQLINTEGER productidCol;
  SQLINTEGER productidcolLength;
  SQLCHAR priceCol[11];
  SQLINTEGER pricecolLength;


  // methods
  bool attemptODBCConnection();
  bool establishODBCConnection();
  bool resetODBCConnection();

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
#endif // SPL_OPER_INSTANCE_ORDER_H_


