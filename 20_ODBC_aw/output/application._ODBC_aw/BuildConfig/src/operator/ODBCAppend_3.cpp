// eJzFkU9z2jAQxUdfhekhvdiKSduEm7HzBxtIimCgXBhZ3gENtqSR1nXcT19BSSCnHDs6aff33rydJ3QdyKIOHFrgtQvKYjB4TodJbAyoklwT6t816QVBiJ2BcAhZa53Y0rvuLmes382TfTR9GjVj9iP7Qyne7n9P5oLS6Wj4_0nOVP8aL1becr7JsGRvWbZ_1yx3u_0yNg6fZi5e9PNluukqCvBPPFrUenJNG73iyxZVxv6nS2zUR6PbzY04TzY9Y5hSLjTNYRQNlEUttruneECwohuDrk3vA1LjpworYCSPhFaKRAotUq1aGpQ6M9hL_0PBwPqbpdp6y8vvVe_0oD1Pe3YRnsQte66r3lcToqaJBeLAAF_0afmU665J31Nv7jkPssXAhw7jN1ayXCXD_1bEuwMXFOhm_1OigkunQ1XSaItfTur_1VxWRxP7ritySY_0hRSaTCfkSSxqGvz055DeTt3LfhO_1ViddkI_1ACdZheMFOct20lzKJchx8adkMPQ_0G3K8UzSv3LpPXR




#include "./ODBCAppend_3.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR ODBCAppend_3_Base
#define MY_OPERATOR ODBCAppend_3$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR()
{
  SPLAPPTRC(L_DEBUG, "Constructor", SPL_OPER_DBG);  


  // Init variables for Metrics
  OperatorMetrics &opm = getContext().getMetrics();
  droppedTuples_ = &opm.getCustomMetricByName("droppedTuples");

    
  // Init variables for SQL handles
  henv = SQL_NULL_HENV;
  hstmt[0] = SQL_NULL_HSTMT;
  hdbc = SQL_NULL_HDBC;
  // Init variables for SQL Connection Information
  connectionDatabase = "streams";
  connectionUser = "db2inst1";
  connectionPassword = "db2expr1";
  // Attempt to connect to the DB
  if (!attemptODBCConnection())
  {
    std::string msg = DB_OPERATOR_SHUTDOWN;
    SPLAPPLOG(L_ERROR, msg, SPL_OPER_DBG);
    throw ODBCOperatorShutdownException();
  }


SPLAPPTRC(L_DEBUG, "register ODBCAppend for governance", SPL_OPER_DBG);
       std::map<std::string,std::string> props;
       props["outputOperatorType"]="ODBCAppend";
       props["srcName"]=connectionDatabase;
       props["srcType"]="database";
       props["registerType"] = "output";
      setTagData("OperatorIGC", props);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR() 
{
  SPLAPPTRC(L_DEBUG, "Destructor", SPL_OPER_DBG);
  rc = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_COMMIT);
  handleSQLRC(SQL_HANDLE_DBC, hdbc, rc);
  if (hstmt[0] != SQL_NULL_HSTMT)
  {
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_UNBIND)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_UNBIND);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_RESET_PARAMS)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_RESET_PARAMS);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_CLOSE)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_CLOSE);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_STMT)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt[0]);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
  }
  hstmt[0] = SQL_NULL_HSTMT;
  if (hdbc != SQL_NULL_HDBC)
  {
    SPLAPPTRC(L_DEBUG, "SQLDisconnect", SPL_OPER_DBG);
    rc = SQLDisconnect(hdbc);
    handleSQLRC(SQL_HANDLE_DBC, hdbc, rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_DBC)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    handleSQLRC(SQL_HANDLE_DBC, hdbc, rc);
    hdbc = SQL_NULL_HDBC;
  }
  if (henv != SQL_NULL_HENV)
  {
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_ENV)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_ENV, henv);
    handleSQLRC(SQL_HANDLE_ENV, henv, rc);
    henv = SQL_NULL_HENV;
  }

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady() 
{
  SPLAPPTRC(L_DEBUG, "allPortsReady", SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
  SPLAPPTRC(L_DEBUG, "prepareToShutdown", SPL_OPER_DBG);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
  SPLAPPTRC(L_DEBUG, "Process Thread (" << idx << ")", SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
  // No mutable input streams
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
  SPLAPPTRC(L_TRACE, "Process Tuple " << tuple, SPL_OPER_DBG);
  const IPort0Type & iport$0 = static_cast<const IPort0Type &>(tuple);
  // Bind tuple attributes to columns
  orderidParam1[0][0] = (SQLINTEGER) iport$0.get_OrderId();
  customernameParam2Length[0][0] = (iport$0.get_CustomerName().size() > 50) ? 50 : (int)iport$0.get_CustomerName().size();
  strncpy( (char *) customernameParam2[0], ((std::string) iport$0.get_CustomerName()).c_str(), 50);
  customeridParam3[0][0] = (SQLINTEGER) iport$0.get_CustomerId();
  productnameParam4Length[0][0] = (iport$0.get_ProductName().size() > 50) ? 50 : (int)iport$0.get_ProductName().size();
  strncpy( (char *) productnameParam4[0], ((std::string) iport$0.get_ProductName()).c_str(), 50);
  productidParam5[0][0] = (SQLINTEGER) iport$0.get_ProductId();
  priceParam6Length[0][0] = (iport$0.get_Price().size() > 10) ? 10 : (int)iport$0.get_Price().size();
  strncpy( (char *) priceParam6[0], ((std::string) iport$0.get_Price()).c_str(), 10);
  shipmentstatusParam7[0][0] = (SQLINTEGER) iport$0.get_ShipmentStatus();
  shippingdateParam8Length[0][0] = (iport$0.get_ShippingDate().size() > 50) ? 50 : (int)iport$0.get_ShippingDate().size();
  strncpy( (char *) shippingdateParam8[0], ((std::string) iport$0.get_ShippingDate()).c_str(), 50);
  if (hstmt[0] == SQL_NULL_HSTMT)
  {
    SPLAPPTRC(L_INFO, "Attempting connection", SPL_OPER_DBG);
    if (!attemptODBCConnection())
    {
      std::string msg = DB_OPERATOR_SHUTDOWN;
      SPLAPPLOG(L_ERROR, msg, SPL_OPER_DBG);
      SPL::Functions::Utility::shutdownPE();
    }
  }
  if (hstmt[0] != SQL_NULL_HSTMT)
  {
    rc = SQLExecute(hstmt[0]);
    SPLAPPLOG(L_INFO, DB_ODBC_RUN_STATEMENT, SPL_OPER_DBG);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      droppedTuples_->incrementValue(1);
      // Determine whether the connection has failed
      bool badConnection = false;
      SQLUINTEGER state = SQL_CD_FALSE;
      rc = SQLGetConnectAttr(hdbc, SQL_ATTR_CONNECTION_DEAD, &state, SQL_IS_UINTEGER, 0);
      if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
      {
        badConnection = (state == SQL_CD_TRUE);
      }
      else 
      {
        SPLAPPTRC(L_DEBUG, "SQLGetConnectAttr failed", SPL_OPER_DBG);
      }
      if (badConnection)
      {
        SPLAPPTRC(L_DEBUG, "Bad connection", SPL_OPER_DBG);
        resetODBCConnection();
      }
    }
  }
  else
  {
    SPLAPPTRC(L_ERROR, "SQL Statement not run because statement is not allocated.  This could be due to a connection error.", SPL_OPER_DBG);
  }

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
  SPLAPPTRC(L_TRACE, "Process Punctuation " << punct, SPL_OPER_DBG);

}




bool MY_OPERATOR::attemptODBCConnection()
{
  SPLAPPTRC(L_DEBUG, "attemptODBCConnection", SPL_OPER_DBG);
  while (!establishODBCConnection())
  {
    // Reset connection for next attempt
    resetODBCConnection();
    // Sleep for 10.0 seconds and retry connection attempt
    std::string msg = DB_CONNECTION_RETRY(10.0);
    SPLAPPLOG(L_INFO, msg, SPL_OPER_DBG);
    if (getPE().blockUntilShutdownRequest((double) 10.0))
    {
      break;
    }
  }
  
  if (!getPE().getShutdownRequested())
  {
    std::string msg = DB_CONNECTION_SUCCESSFUL;
    SPLAPPLOG(L_INFO, msg, SPL_OPER_DBG);
  }
  return true;
}

bool MY_OPERATOR::establishODBCConnection()
{
  SPLAPPTRC(L_DEBUG, "establishODBCConnection", SPL_OPER_DBG);
  
  // Allocate the environment handle
  rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  if (handleSQLRC(SQL_HANDLE_ENV, henv, rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to allocate environment handle", SPL_OPER_DBG);
    return false;
  }
  rc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);
  if (handleSQLRC(SQL_HANDLE_ENV, henv, rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to set ODBC version environment attribute", SPL_OPER_DBG);
    return false;
  }
  // Allocate the connection handle
  if (henv != SQL_NULL_HENV)
  {
    rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
    if (handleSQLRC(SQL_HANDLE_ENV, henv, rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to allocate connection handle", SPL_OPER_DBG);
      return false;
    }
  }
  // Connect to database
  if (hdbc != SQL_NULL_HDBC)
  {
    rc = SQLConnect(hdbc,
                    (UCHAR*) connectionDatabase.c_str(),
                    SQL_NTS,
                    (UCHAR*) connectionUser.c_str(),
                    SQL_NTS,
                    (UCHAR *) connectionPassword.c_str(),
                    SQL_NTS);
    if (handleSQLRC(SQL_HANDLE_DBC, hdbc, rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to connect to database", SPL_OPER_DBG);
      return false;
    }
  }
  // Allocate statement handle(s)
  if (hdbc != SQL_NULL_HDBC)
  {
    rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt[0]);
    if (handleSQLRC(SQL_HANDLE_DBC, hdbc, rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to allocate statement for hstmt[0]", SPL_OPER_DBG);
      return false;
    }
  }
  rc = SQLSetConnectAttr(hdbc,
                         SQL_ATTR_AUTOCOMMIT,
                         (SQLPOINTER) SQL_AUTOCOMMIT_ON,
                         SQL_IS_UINTEGER);
  if (handleSQLRC(SQL_HANDLE_DBC, hdbc, rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to SetAutoCommit.", SPL_OPER_DBG);
    return false;
  }
  // Prepare statement
  rc = SQLPrepare(hstmt[0], (SQLCHAR *) "INSERT INTO OrderResults (OrderId,CustomerName,CustomerId,ProductName,ProductId,Price,ShipmentStatus,ShippingDate) VALUES(?,?,?,?,?,?,?,?)", SQL_NTS);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to prepare query for hstmt[0]", SPL_OPER_DBG);
    return false;
  }
  // Determine number of result columns for the statement
  if (hstmt[0] != SQL_NULL_HSTMT)
  {
    rc = SQLNumResultCols(hstmt[0], &stmtcols);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to retrieve number of result columns for statement", SPL_OPER_DBG);
      return false;
    }
  }
  // Initialize string buffers
  for (int i = 50; i < 51; i += 51 )
  {
    customernameParam2[0][i] = '\0';
  }
  for (int i = 50; i < 51; i += 51 )
  {
    productnameParam4[0][i] = '\0';
  }
  for (int i = 10; i < 11; i += 11 )
  {
    priceParam6[0][i] = '\0';
  }
  for (int i = 50; i < 51; i += 51 )
  {
    shippingdateParam8[0][i] = '\0';
  }
  // Bind parameters for hstmt[0]
  
  rc = SQLBindParameter(hstmt[0],
                        1,
                        SQL_PARAM_INPUT,
                        SQL_C_LONG,
                        SQL_INTEGER,
                        0,
                        0,
                        orderidParam1[0],
                        0,
                        NULL);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter orderidParam1[0] in position 1", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        2,
                        SQL_PARAM_INPUT,
                        SQL_C_CHAR,
                        SQL_CHAR,
                        50,
                        0,
                        customernameParam2[0],
                        51,
                        customernameParam2Length[0]);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter customernameParam2[0] in position 2", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        3,
                        SQL_PARAM_INPUT,
                        SQL_C_LONG,
                        SQL_INTEGER,
                        0,
                        0,
                        customeridParam3[0],
                        0,
                        NULL);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter customeridParam3[0] in position 3", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        4,
                        SQL_PARAM_INPUT,
                        SQL_C_CHAR,
                        SQL_CHAR,
                        50,
                        0,
                        productnameParam4[0],
                        51,
                        productnameParam4Length[0]);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter productnameParam4[0] in position 4", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        5,
                        SQL_PARAM_INPUT,
                        SQL_C_LONG,
                        SQL_INTEGER,
                        0,
                        0,
                        productidParam5[0],
                        0,
                        NULL);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter productidParam5[0] in position 5", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        6,
                        SQL_PARAM_INPUT,
                        SQL_C_CHAR,
                        SQL_CHAR,
                        10,
                        0,
                        priceParam6[0],
                        11,
                        priceParam6Length[0]);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter priceParam6[0] in position 6", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        7,
                        SQL_PARAM_INPUT,
                        SQL_C_LONG,
                        SQL_INTEGER,
                        0,
                        0,
                        shipmentstatusParam7[0],
                        0,
                        NULL);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter shipmentstatusParam7[0] in position 7", SPL_OPER_DBG);
    return false;
  }
  rc = SQLBindParameter(hstmt[0],
                        8,
                        SQL_PARAM_INPUT,
                        SQL_C_CHAR,
                        SQL_CHAR,
                        50,
                        0,
                        shippingdateParam8[0],
                        51,
                        shippingdateParam8Length[0]);
  if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to bind parameter shippingdateParam8[0] in position 8", SPL_OPER_DBG);
    return false;
  }
  
  SPLAPPTRC(L_DEBUG, "establishODBCConnection completed", SPL_OPER_DBG);
  return true;
}
bool MY_OPERATOR::resetODBCConnection()
{
  SPLAPPTRC(L_DEBUG, "resetODBCConnection", SPL_OPER_DBG);
  rc = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_COMMIT);
  if (handleSQLRC(SQL_HANDLE_DBC, hdbc, rc) == false)
  {
    SPLAPPTRC(L_ERROR, "Failed to commit transaction.", SPL_OPER_DBG);
  }
  if (hstmt[0] != SQL_NULL_HSTMT)
  {
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_UNBIND)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_UNBIND);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_RESET_PARAMS)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_RESET_PARAMS);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeStmt(SQL_CLOSE)", SPL_OPER_DBG);
    rc = SQLFreeStmt(hstmt[0], SQL_CLOSE);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_STMT)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt[0]);
    handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc);
  }
  hstmt[0] = SQL_NULL_HSTMT;
  if (hdbc != SQL_NULL_HDBC)
  {
    SPLAPPTRC(L_DEBUG, "SQLDisconnect", SPL_OPER_DBG);
    rc = SQLDisconnect(hdbc);
    handleSQLRC(SQL_HANDLE_DBC, hdbc, rc);
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_DBC)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    handleSQLRC(SQL_HANDLE_DBC, hdbc, rc);
    hdbc = SQL_NULL_HDBC;
  }
  if (henv != SQL_NULL_HENV)
  {
    SPLAPPTRC(L_DEBUG, "SQLFreeHandle(SQL_HANDLE_ENV)", SPL_OPER_DBG);
    rc = SQLFreeHandle(SQL_HANDLE_ENV, henv);
    handleSQLRC(SQL_HANDLE_ENV, henv, rc);
    henv = SQL_NULL_HENV;
  }
  
  SPLAPPTRC(L_DEBUG, "resetODBCConnection completed", SPL_OPER_DBG);
  return true;
}


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("ODBCAppend_3",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    param$connectionDocument$0 = SPL::rstring("/data/Day4/connections.xml");
    addParameterValue ("connectionDocument", SPL::ConstValueHandle(param$connectionDocument$0));
    param$connection$0 = SPL::rstring("MyConnection");
    addParameterValue ("connection", SPL::ConstValueHandle(param$connection$0));
    param$access$0 = SPL::rstring("writeToOrderResultsTable");
    addParameterValue ("access", SPL::ConstValueHandle(param$access$0));
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

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    case Punctuation::WatermarkMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
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



