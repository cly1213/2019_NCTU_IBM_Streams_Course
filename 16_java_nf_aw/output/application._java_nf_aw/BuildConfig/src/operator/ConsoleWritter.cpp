// eJzFk1trgzAYhsltf4WUXThW1GiPWSm0Y4OVrgxcr0NQ17rVKCaZc2P_1ffHQw6ajIJTFG3l9v_0Tx_1b6waKsJ7m99niJ0IxgPAwCBIR8LtDVN52nk6TNvnsQPdgKfbLr8IMbtdDbrTpdDbdMGY_1txgefL_0ztBHe6HlGEnDLB8FzhIs52Ztpmcdr1nLgNAC0iUCwNIP0I_05ZYJcgVWFLNQYsZjn64LzarRupXKXkXp19QNKq5hRRnV1MEa_0Co9_1I0P9E0YeLrnCtPUkzB_0ZRFxPB328Qt5I5g_0Y5LoLuEE0JB6WYOyNvlRGO_1j_0qtNwAdx3tLPliIXQrl73wqEVrsBiCQLt3OiBVXVPGblalfBoi12COPjY_1KOcvg1ZYJQZlDLguOGyy9hgFDWcoTKycht_0KeLuG5_0rtFR8pwu5bpuwG0duJtgrD2_0Yl6sNjy9f77U3utwHRGIaZlct0iu1zS50T_0yDwr2YVN2eMZxPQkPdzNbDu1XC8hL6oogSIEo7r7xDestLeL


#include "./ConsoleWritter.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR ConsoleWritter_Base
#define MY_OPERATOR ConsoleWritter$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("ConsoleWritter",&initer));
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
    initRTC(*this, lit$7, "lit$7");
    initRTC(*this, lit$8, "lit$8");
    initRTC(*this, lit$9, "lit$9");
    initRTC(*this, lit$10, "lit$10");
    initRTC(*this, lit$11, "lit$11");
    initRTC(*this, lit$12, "lit$12");
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
    ::SPL::Functions::Utility::printStringLn((lit$2 + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::JNIFunctions::com::nctu::myutils::SPL_JNIFunctions::add(lit$0, lit$1))));
    ::SPL::Functions::Utility::printStringLn((lit$3 + ::SPL::JNIFunctions::com::nctu::myutils::SPL_JNIFunctions::getUser()));
    ::SPL::Functions::Utility::printStringLn((lit$6 + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::JNIFunctions::com::nctu::myutilx::SPL_JNIFunctions::cumuAdd(lit$4, lit$5))));
    ::SPL::Functions::Utility::printStringLn((lit$9 + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::JNIFunctions::com::nctu::myutilx::SPL_JNIFunctions::cumuAdd(lit$7, lit$8))));
    ::SPL::Functions::Utility::printStringLn((lit$12 + ::SPL::spl_cast<SPL::rstring, SPL::int32 >::cast(::SPL::JNIFunctions::com::nctu::myutilx::SPL_JNIFunctions::cumuAdd(lit$10, lit$11))));
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



