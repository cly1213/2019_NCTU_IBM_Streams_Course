// eJylkUFPwzAMheW_1MnFuklIN0Vu3CYl2RZNazlPWmS1ql4TEpSu_1nlAm0HZFvj3Z73u2ve2inlSnaEzTBcrGaBDAQwmYRRGj0SJbYD64smrjYv5Q1o3bVHVJRWnLWsWiWJ5fPpcf_0bpoPanBVu05X8nWV9lr9mySTXaIjrPgF0OA3HGoNus07ZWm_0xgmSfxIb52RNE8AgB3NCRnu_0zhmg3Gtt7JBxh_03B0m4lQPbS5KgjcZvV0XoJCmjPYgrc3EBZkRO7XrCJ4cISitaYSdHuOGKS5jrdj5dw1jjfrP_18xqgwEECfjztTAfOB5o_0BIZ1qkGY0oTwHN57qSm8BS7rcCAn91iHh_1xN8S9sBYvM



#include "./Ticker_T.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Ticker_T_Base
#define MY_OPERATOR Ticker_T$OP



// batchSize 1

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: _iterationCount(0)
  
{
    _tuple.clear();
    
        _iters = lit$0;
    
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
{
    createThreads (1);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t) 
{
    SPLAPPTRC(L_DEBUG, "Beacon startup...", SPL_OPER_DBG);
    ProcessingElement& pe = getPE();
    
    
        pe.blockUntilShutdownRequest(lit$1);
    
    uint32_t batchSize = 1;
    while(!pe.getShutdownRequested()) {
        
                
                {
                    AutoMutex am (_mutex);
                
                
                    if (_iters != 0) {
                        _iters--;
                
                
                submit (_tuple, 0);
                
                
                
                    }
                    if (_iters == 0) {
                        

                        SPLAPPTRC(L_DEBUG, "Submit window marker", SPL_OPER_DBG);
                        submit(Punctuation::WindowMarker, 0);
                        
                            submit(Punctuation::FinalMarker, 0);
                            goto exit;
                        
                        
                    }
                
                
                } 
                
	
        
    }
exit:
    SPLAPPTRC(L_DEBUG, "Beacon exiting...", SPL_OPER_DBG);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::getCheckpoint(NetworkByteBuffer & opstate)
{
    AutoMutex am (_mutex);
    
    
        opstate.addUInt32(_iters);
    
    
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::restoreCheckpoint(NetworkByteBuffer & opstate)
{
    AutoMutex am (_mutex);
    
    
        _iters = opstate.getUInt32();
    
    
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Executing checkpoint()", SPL_OPER_DBG);

    
        ckpt << _iters;
    
    
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    
        ckpt >> _iters;
    
    
    

    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    _iterationCount = 0;
    _tuple.clear();
    
        _iters = lit$0;
    

    
    
    
    return;
}


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Ticker_T",&initer));
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
    addParameterValue ("iterations", SPL::ConstValueHandle(lit$0));
    addParameterValue ("initDelay", SPL::ConstValueHandle(lit$1));
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


