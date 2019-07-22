// eJzFlFtzojAUxyev_1RRMpw_16ws1LWzt9QOxFUHuhjq4vTBayygiEJmFdttPvvgEVAe3WnZ2dDQ_0Ew_09_1TpL_1ARr5IkE_0ZB4Ood_1p3MahwzABCpD5pYJTUZRYEiGpi4wVGTpUvkwuTctqJC_16Uh3d9_0OBdW78lGV2sfw_0fHFkedTv_1niamnfaeNoy4dQwJlpkJfN78_04Gjg1rFmpYe2VN2MXi4rSSnzrzv87fu32mN1HyPJnpXwPfsTjxZezj4UhbLceGPvNtuW1NjL6pDZq2rEOYLkMFlEGGzmy68KIIucB6HHQ6XsgaanGqAN9jZ60i7PLZGiGUES_0clx_1WijY4z_05yMVkWUfYiajlBFmvsUc0DVGuPalcoIC1wgCTkxqoqrTBZ0gg6SFJl_06HX1W24kvh2IAhxiFL70ybwIkzyhf_0DJgAeIFmvvZ0IfHjfhFqt7IVwfS1kh1evCxmTjrd8lo6qIOOVq4_0Y1LMNpO6g92yGfIr_0pErjmCrNYpX3EwDa4IG4iPRdsHZLjynjzpARDBDY2rUN5tQjwW7ssBK0iRUYz9m9TR3Eew7_0l88MBNzoi8q_0FVD6APJ2E_0eI2Ru0Vj98PLl2Gyiri5pCiuNK72guPXTsnxQvSHYJjiudw5mwbOYnNTnMRRbvvQCFzOKtGNOPSlb_1d_0md5_0ylv7PfFKz0N_0_0vX1oqOPV


#include "./Result.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Result_Base
#define MY_OPERATOR Result$OP





void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! (1) ) 
       return;
   { OPort0Type otuple(iport$0.get_OrderId(), iport$0.get_CustomerName(), iport$0.get_CustomerId(), iport$0.get_ProductName(), iport$0.get_ProductId(), iport$0.get_Price(), state$_shipped, state$_shipdate); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Result",&initer));
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
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    state$_shipped = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$_shipped Value: " << state$_shipped,SPL_OPER_DBG);
    state$_shipdate = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$_shipdate Value: " << state$_shipdate,SPL_OPER_DBG);
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
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
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    if ((state$_shipped == lit$0)) 
        {
            state$_shipped = lit$1;
            state$_shipdate = lit$2;
        }
    else
        {
            state$_shipped = lit$3;
            state$_shipdate = lit$4;
        }
}

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
        {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(1);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
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
    opstate << state$_shipped;
    opstate << state$_shipdate;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$_shipped;
    opstate >> state$_shipdate;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$_shipped;
    ckpt << state$_shipdate;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$_shipped;
    ckpt >> state$_shipdate;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$_shipped = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$_shipped Value: " << state$_shipped,SPL_OPER_DBG);
    state$_shipdate = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$_shipdate Value: " << state$_shipdate,SPL_OPER_DBG);
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



