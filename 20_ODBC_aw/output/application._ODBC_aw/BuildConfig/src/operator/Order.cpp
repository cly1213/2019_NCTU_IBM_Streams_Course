// eJy1kU1TwjAQhmf_1CuNBL00oiMKtgCjl0ymMjBcmpCt0aBJMUqH_0emOVLy_0cnJw28_06z7_07LlfCShfCM1ciE8eJFozFqN1uRyjRHKAN1rwwlzyM23yBpYrjVA25oPa_13oqiST1prf_1jUzfrRXfhJqb1ffwwmnNJht7l7nvUeg_0nstsdmYfgSbKJ8_0dR7fGDTMHqVgQrebZU1lbcqFTPSxF5RiMb9RuMtVczWqgBAVkogwTjzfbJVem02jCPx6fzb5JxtScwsA6kkUqgCV1Iit4mSbcUzgdI6bkHUbsFELoGeldelop_00WV4lx2bj7URauoHAOtUis9jRiCfwS9BB3jpoHcYVxjLnhXGOxlzqdkHEHa3ESMeoJ2yRYkfpnzxOYYlMbBtTlu95_06PtL3nunhZZqo3Shyv_1Q5YgQEMNCuvd2Hm0Fd_0NbWXGuhz1kAmE49777xPlWKs44_1aP8Pf3TJfwEwX9AoBcONH




#include "./Order.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Order_Base
#define MY_OPERATOR Order$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR() : MY_BASE_OPERATOR() 
{  
  SPLAPPTRC(L_DEBUG, "Constructor", SPL_OPER_DBG);

  numberOfReplays_ = 1;
  infiniteReplays_ = false;

  // Init variables for Metrics
  OperatorMetrics &opm = getContext().getMetrics();

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


SPLAPPTRC(L_DEBUG, "register ODBCSource for governance", SPL_OPER_DBG);
       std::map<std::string,std::string> props;
       props["inputOperatorType"]="ODBCSource";
       props["srcName"]=connectionDatabase;
       props["srcType"]="database";
       props["registerType"] = "input";
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
  createThreads(1);

}
 
void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown() 
{
  SPLAPPTRC(L_DEBUG, "prepareToShutdown", SPL_OPER_DBG);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t idx)
{
  SPLAPPTRC(L_DEBUG, "Process Thread (" << idx << ")", SPL_OPER_DBG);
  if (idx == 0)
  {
    SPLAPPTRC(L_DEBUG, "initDelay of " << (lit$0) << " seconds requested ...", SPL_OPER_DBG);
    if (!getPE().blockUntilShutdownRequest((double) lit$0))
    {
      // Loop for <numberOfReplays>, or forever...
      bool done=false;
      while(!done)
      {
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
        
        // Fetch rows from result set and emit output tuples
        if (hstmt[0] != SQL_NULL_HSTMT)
        {
          SPLAPPTRC(L_INFO, "Beginning of result set processing.", SPL_OPER_DBG);
          while (1) {
            rc = SQLFetch(hstmt[0]);
            if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
            {
              std::string msg = DB_ODBC_FETCH_FAILURE(rc);
              SPLAPPLOG(L_ERROR, msg, SPL_OPER_DBG);
              // fail current cut if there is any
              break;
            }
            else
            {
              if (rc == SQL_NO_DATA_FOUND) {
                SPLAPPTRC(L_INFO, "End of result set processing", SPL_OPER_DBG);
                rc = SQLFreeStmt(hstmt[0], SQL_CLOSE);
                if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
                {
                  SPLAPPTRC(L_ERROR, "Failed to close query cursor", SPL_OPER_DBG);
                }
                break;
              }
              else {
                OPort0Type otuple;
                boolean tupleIsOk = true;
                if (orderidcolLength == SQL_NULL_DATA) {
                  otuple.set_OrderId(0);
                }
                else {
                  otuple.set_OrderId(orderidCol);
                }
                if (customernamecolLength == SQL_NULL_DATA) {
                  otuple.set_CustomerName("\0");
                }
                else {
                  otuple.set_CustomerName((const char *) customernameCol);
                }
                if (customeridcolLength == SQL_NULL_DATA) {
                  otuple.set_CustomerId(0);
                }
                else {
                  otuple.set_CustomerId(customeridCol);
                }
                if (productnamecolLength == SQL_NULL_DATA) {
                  otuple.set_ProductName("\0");
                }
                else {
                  otuple.set_ProductName((const char *) productnameCol);
                }
                if (productidcolLength == SQL_NULL_DATA) {
                  otuple.set_ProductId(0);
                }
                else {
                  otuple.set_ProductId(productidCol);
                }
                if (pricecolLength == SQL_NULL_DATA) {
                  otuple.set_Price("\0");
                }
                else {
                  otuple.set_Price((const char *) priceCol);
                }
                if (tupleIsOk) {
                  submit(otuple, 0);
                }
              }
            }
          }
        }
        
        // After retrieving all the result tuples, output a punctuation
        submit(Punctuation::WindowMarker, 0);
        
        if (!infiniteReplays_)
        {
          done = (--numberOfReplays_ <= 0);
          SPLAPPTRC(L_DEBUG, "number of replays remaining " << numberOfReplays_, SPL_OPER_DBG);
        }
      }
    }
  }

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple & tuple, uint32_t port)
{
  // no mutable input ports
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
  SPLAPPTRC(L_DEBUG, "Process Tuple " << tuple, SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
  // no punctuation-aware input ports
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
  // Set Isolation Level
  if (hdbc != SQL_NULL_HDBC)
  {
    rc = SQLSetConnectAttr(hdbc, SQL_ATTR_TXN_ISOLATION, (SQLPOINTER) SQL_TXN_READ_UNCOMMITTED, SQL_NTS);
    if (handleSQLRC(SQL_HANDLE_DBC, hdbc, rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to set isolation level", SPL_OPER_DBG);
      return false;
    }
  }
  // Prepare statement
  rc = SQLPrepare(hstmt[0], (SQLCHAR *) "select OrderId, CustomerName, CustomerId, ProductName, ProductId, Price from Order", SQL_NTS);
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
  // Bind tuple attributes to columns
  // Bind parameters for hstmt[0]
  
  // Bind the query results to local variables
  if (hstmt[0] != SQL_NULL_HSTMT)
  {
    // Column binding for OrderId
    rc = SQLBindCol(hstmt[0],
                    1,
                    SQL_C_LONG,
                    &orderidCol,
                    0,
                    &orderidcolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column orderidCol", SPL_OPER_DBG);
      return false;
    }
    // Column binding for CustomerName
    rc = SQLBindCol(hstmt[0],
                    2,
                    SQL_C_CHAR,
                    customernameCol,
                    sizeof(customernameCol),
                    &customernamecolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column customernameCol", SPL_OPER_DBG);
      return false;
    }
    // Column binding for CustomerId
    rc = SQLBindCol(hstmt[0],
                    3,
                    SQL_C_LONG,
                    &customeridCol,
                    0,
                    &customeridcolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column customeridCol", SPL_OPER_DBG);
      return false;
    }
    // Column binding for ProductName
    rc = SQLBindCol(hstmt[0],
                    4,
                    SQL_C_CHAR,
                    productnameCol,
                    sizeof(productnameCol),
                    &productnamecolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column productnameCol", SPL_OPER_DBG);
      return false;
    }
    // Column binding for ProductId
    rc = SQLBindCol(hstmt[0],
                    5,
                    SQL_C_LONG,
                    &productidCol,
                    0,
                    &productidcolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column productidCol", SPL_OPER_DBG);
      return false;
    }
    // Column binding for Price
    rc = SQLBindCol(hstmt[0],
                    6,
                    SQL_C_CHAR,
                    priceCol,
                    sizeof(priceCol),
                    &pricecolLength);
    if (handleSQLRC(SQL_HANDLE_STMT, hstmt[0], rc) == false)
    {
      SPLAPPTRC(L_ERROR, "Failed to bind column priceCol", SPL_OPER_DBG);
      return false;
    }
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
    instantiators_.insert(std::make_pair("Order",&initer));
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
    param$connectionDocument$0 = SPL::rstring("/data/Day4/connections.xml");
    addParameterValue ("connectionDocument", SPL::ConstValueHandle(param$connectionDocument$0));
    param$connection$0 = SPL::rstring("MyConnection");
    addParameterValue ("connection", SPL::ConstValueHandle(param$connection$0));
    param$access$0 = SPL::rstring("readFromOrderTableForSource");
    addParameterValue ("access", SPL::ConstValueHandle(param$access$0));
    addParameterValue ("initDelay", SPL::ConstValueHandle(lit$0));
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



