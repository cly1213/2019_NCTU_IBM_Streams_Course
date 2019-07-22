// eJyFUGFrwjAQ5f5JET_1YOZq0ih_1CGNSBoKxj4NhXydITg21SkqvO_1frVWrcyNkY_0JHnv3d1756siqkkXmk5CzFEqayAG3pwYBlHE6FQhm_0Pq6LLtkr_0o6eFjfXh_1yvZ_0rfgifbCr9HUW7QaN3JMkHBpYPz8KoQ3Npv1nDM2MYQKT9uYXaltYeSZbLP4FS_1otANjOlsgwr5OEHa3b_00oqZHyyKZGcVp7lkiQYa_1Dsv0KnbQ4_1_0sadgZSakreacOEQ27wcbGXdl7n_1UoMGBwkoWxuCLmTql_1468ALx617GY9CE5d_1KGIRov74qNkp6uvsmb4N_0huBeiLNgNOoqFrVRpK3xQmSSdkI4aXJbjsLgJmhXG4b8E_0e_1I_13



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
    
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::allPortsReady()
{
    createThreads (1);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(uint32_t) 
{
    SPLAPPTRC(L_DEBUG, "Beacon startup...", SPL_OPER_DBG);
    ProcessingElement& pe = getPE();
    
        const double period = lit$0;
    
    
    uint32_t batchSize = 1;
    while(!pe.getShutdownRequested()) {
        
                
                {
                    AutoMutex am (_mutex);
                
                
                _tuple.set_count(state$n++); _tuple.set_item(::SPL::spl_cast<SPL::int64, SPL::float64 >::cast((::SPL::Functions::Math::random() * lit$1))); 
                submit (_tuple, 0);
                
                
                
                
                } 
                
	
        
            pe.blockUntilShutdownRequest(period);
        
    }
exit:
    SPLAPPTRC(L_DEBUG, "Beacon exiting...", SPL_OPER_DBG);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::getCheckpoint(NetworkByteBuffer & opstate)
{
    AutoMutex am (_mutex);
    
        checkpointStateVariables(opstate);
    
    
    
    
        opstate << _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::restoreCheckpoint(NetworkByteBuffer & opstate)
{
    AutoMutex am (_mutex);
    
        restoreStateVariables(opstate);
    
    
    
    
        opstate >> _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Executing checkpoint()", SPL_OPER_DBG);

    
    
    
        ckpt << _tuple;
    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    
    
    
        ckpt >> _tuple;
    

    
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    _iterationCount = 0;
    _tuple.clear();
    

    
    
    
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
    state$n = lit$2;
    SPLAPPTRC(L_DEBUG, "Variable: state$n Value: " << state$n,SPL_OPER_DBG);
    addParameterValue ("period", SPL::ConstValueHandle(lit$0));
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
    opstate << state$n;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$n;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$n;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$n;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
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


