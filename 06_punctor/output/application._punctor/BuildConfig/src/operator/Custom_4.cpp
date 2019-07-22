// eJyVkl1rwjAUhjm3_1oogXrRM7KdexG0wBS_0clYHzWjKNGq1JSVKljv331bRWZTIwhTR5c77ynKgkbqWaxUxnGPdTpcUOPHDzz4N6q_0XoLKFOjw4PMpps_1Wy6jz7nrpttj8NxP34_1RiodK298jMT_0bdXzg1W8aa3r4IPSRNNGMiMSJh8jjL_0EiCnhtxsP8ryNsDSmsrRlXAf_09bKwa0PH_1N3bIEbzCk0qLRlfFVoZIs1jdMJCCu64hne09nV2AGctdtShi9T3nYOQW5WQOXXczixJ_0VwL6SyIJsAFpwU4F1giZFXpQ_1iAgTT82RJZF4o2qqF8fJv5NC5H6AUZLN3qDGOTd3CqjgmuMJ6eW5zkfPTEUBpxyzLs0NPZQyXxbE6Ufr6m2USP3wK9YnwKZJUgbNv_0r7wBiynGy2WcqrWpyW_0i6lGUnj81_0HPnoFuDEDjZUTi3ni2gaJskfFsud2QjZGXh_1gKjoOYr


#include "./Custom_4.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Custom_4_Base
#define MY_OPERATOR Custom_4$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Custom_4",&initer));
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
    state$p_ar = lit$4;
    SPLAPPTRC(L_DEBUG, "Variable: state$p_ar Value: " << state$p_ar,SPL_OPER_DBG);
    state$err = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$err Value: " << state$err,SPL_OPER_DBG);
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
    
if (state$p_ar) 
    {
        state$p_ar = lit$0;
        ::SPL::Functions::Utility::printStringLn((lit$1 + ::SPL::spl_cast<SPL::rstring, SPL::BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj >::cast(iport$0)));
        ::SPL::Functions::File::fflush(lit$2, state$err);
    }

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
    AutoPortMutex $apm($svMutex, *this);
    
state$p_ar = lit$3;

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
    opstate << state$p_ar;
    opstate << state$err;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$p_ar;
    opstate >> state$err;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$p_ar;
    ckpt << state$err;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$p_ar;
    ckpt >> state$err;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$p_ar = lit$4;
    SPLAPPTRC(L_DEBUG, "Variable: state$p_ar Value: " << state$p_ar,SPL_OPER_DBG);
    state$err = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$err Value: " << state$err,SPL_OPER_DBG);
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



