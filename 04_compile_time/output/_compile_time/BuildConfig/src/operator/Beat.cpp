// eJyNkN2KwjAQhZlXEe_0E5se96l3rIigKgg8g2TrguG0SkglFn96uzUr3YpclFxPmfJyZOdG3RWJqiW9lWaNpnAUFcngKZkUh_0OZR1Ljtw75x8r7v5b3aVO91v1ql4jIDDZEN47yD42FXlmR5qadfBYP1XGXK_1klpWD6rHKU0atlgQmd42gFxcR0KPCetRe_1CZ_1SmQSHfTo3rPLV4Yhr0s2ED1ln8Oo8Yg2FyNoL6MVHlLSrmQB_0JcR0Qn4lIcN6F14a_15AIEYQiGINtVcfMaMbYkLBbfuV3_1g1n5AMweHoV



#include "./Beat.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Beat_Base
#define MY_OPERATOR Beat$OP



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
    
    
    uint32_t batchSize = 1;
    while(!pe.getShutdownRequested()) {
        
                
                {
                    AutoMutex am (_mutex);
                
                
                    if (_iters != 0) {
                        _iters--;
                
                _tuple.set_i(++state$m); _tuple.set_j(++state$n); 
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
    
        checkpointStateVariables(opstate);
    
    
        opstate.addUInt32(_iters);
    
    
    
        opstate << _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::restoreCheckpoint(NetworkByteBuffer & opstate)
{
    AutoMutex am (_mutex);
    
        restoreStateVariables(opstate);
    
    
        _iters = opstate.getUInt32();
    
    
    
        opstate >> _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Executing checkpoint()", SPL_OPER_DBG);

    
        ckpt << _iters;
    
    
    
        ckpt << _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    
        ckpt >> _iters;
    
    
    
        ckpt >> _tuple;
    

    
    
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
    instantiators_.insert(std::make_pair("Beat",&initer));
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
    state$m = lit$1;
    SPLAPPTRC(L_DEBUG, "Variable: state$m Value: " << state$m,SPL_OPER_DBG);
    state$n = lit$2;
    SPLAPPTRC(L_DEBUG, "Variable: state$n Value: " << state$n,SPL_OPER_DBG);
    addParameterValue ("iterations", SPL::ConstValueHandle(lit$0));
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
    opstate << state$m;
    opstate << state$n;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$m;
    opstate >> state$n;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$m;
    ckpt << state$n;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$m;
    ckpt >> state$n;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$m = lit$1;
    SPLAPPTRC(L_DEBUG, "Variable: state$m Value: " << state$m,SPL_OPER_DBG);
    state$n = lit$2;
    SPLAPPTRC(L_DEBUG, "Variable: state$n Value: " << state$n,SPL_OPER_DBG);
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return true;
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


