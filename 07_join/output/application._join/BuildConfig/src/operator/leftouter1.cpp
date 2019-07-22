// eJytUt9PwjAQTl_15KxbCwxYM6wYGU8VEjD6wkUAGifpC5qhQfrR1vYpI_0N_1dCgxMfNCE60PvrnfX_0747JRc1DWzBYE3IvVYglshDODseKtdqLqwlddu0s0q7EfbW85WE_0USHUbPzhTEEs5dOFH12wsHzR9CVvWCIdfA6FOFDvRtczdV7v383SBr99lNtWs4qKoiBVhIOKOqFhDAOdf9U9VDWSKWOGubGp0_1G4_008qYKU8cnO5_1_1iq_1_1IRO5ULKlLx9r33ZVI50rGCXVxczQTjLvjGGLEBac71BgxKdLi9zNgRwylhtJNycqEvVm2XTBRrVqtlmXgOo5lAnLZFFouhJheHjVPgAmuCBkeZiYz1BAZ7CG3DUnOdZG8Lf0r3bb3oUouRkms4OaU2wvryKp1S0gecATiWFUDw8_0VP5Q5A7FFE_1uJOU4GfVtC6BKxMdK78SdmqWmKDhuSzZsWhkzFWCdQ2O865pAxc8jG3yXWPVW


#include "./leftouter1.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR leftouter1_Base
#define MY_OPERATOR leftouter1$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("leftouter1",&initer));
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
    state$cnt = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
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
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    if ((state$cnt++ == lit$0)) 
        {
            ::SPL::Functions::Utility::printStringLn(lit$1);
        }
    ::SPL::Functions::Utility::printStringLn(((::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(state$cnt) + lit$2) + ::SPL::spl_cast<SPL::rstring, SPL::BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX >::cast(iport$0)));
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
    opstate << state$cnt;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$cnt;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$cnt;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$cnt;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$cnt = lit$3;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
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



