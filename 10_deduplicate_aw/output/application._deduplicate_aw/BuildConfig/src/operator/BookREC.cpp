// eJy1U1FvmzAQll_17K6yqD7BEwZCklbx1Ulep0jaIWiV9jhziBRewqX0oYtP_0_0xyHoiTikcED3Hfc932_0O0xVTGoQhYCG0sfagCpRiIi9Q3Q9mQTQVDz4xn_1sdbIkUZzmpnnNYWFyszJKL3Jj4lR_0j5v3KH7MFo3Ff_0c7WL4l8DOpktXu9WF1N3t50JPs2jIaYMBvUglo_0RxTWgsJ0_0jsPUTWys0tunNPcsxpA1rIHXJY2INFPdi0B5sdsV_0FYgcxh83P9Fv5MwgFmSp5wLd1FAV7pXNTsZQHIVlvLVYVIrWnWrN9sGXAkFSSH_1tHkKiU7k4xQBdRibQbzp8rbK_1RqGvoZwe0evgeD6XoeW4OeIQpdZymKtYpM_1DltLtjfNIw_1JXSwxdeZ873x9jxhAPxRAPxTAfg6a1vN6ytd9HtrCNoS55qmYJQ0lCaMMisKpNbVXq_0jz9ht66_0f5yrqTelAOy18x277Nwm_114hNEcgoODoY9OF2cguYDVkSndhVW8KYTJ_0gmiRcvTxRxyWVv2Ppb00Sc5tkkujpMcquTBLrNt_1oU6CCo


#include "./BookREC.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR BookREC_Base
#define MY_OPERATOR BookREC$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("BookREC",&initer));
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
    state$cnt = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
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

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    ++state$cnt;
    iport$0 = SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr((lit$0 + ::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(state$cnt)), (lit$1 + ::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(state$cnt)), (lit$2 + ::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(state$cnt)), (lit$3 + ::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(state$cnt)), (::SPL::spl_cast<SPL::float32, SPL::float64 >::cast(::SPL::Functions::Math::random()) * lit$4));
    submit (iport$0, lit$5);
}

}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
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
    state$cnt = lit$6;
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



