// eJy1VF1rwjAUJa_1_0iiB7aEEaWxVGNgdu4GDo2HTba8naqpltkzWpIuJ_1X1LbUsXNbWL6cu_1l3OTcj1PBQyuVNKRyhfFdKiSLgA2a6uuAumWhSRp7krIYEc5D6pGt7ftUG9as_1j3IpwsqjoGiNJS0dH_0EivRdJsSr4uSKB_0g2eFgmw_1HcWdFL9ui1F8Pe82j0_0RaNSNznL_1Owd7_0Y9T6YTmqCNlClXjTB_0GmAcSJkQuMpyGL2gZhzINbaiwE0Y1GAAj91HLRkyVxw4gXI7riCh0UlLlkin0gCYhYHuru6x5SzpOTy2zJABJJsPusaVIdOoGHkF1nTQLqMGybsdmFWpmnCDKXPurSyvEpKEgg1Bp0GMa60XDn5oPdesA2zAXdDjmGaV_0ULm_0Pc7FO5VfbhDPScU_0ntbvYZGLZOZVgI9H_1cMM7Wtp8vuMD4tfiNcCUMOc7kMYiNHKjE4HpEyOuqehrwT7sPbzDWdxSMNatNDShRMw4KQaoKQKoItBxlOoW5bUPhNb8A9xuCAc


#include "./writter.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR writter_Base
#define MY_OPERATOR writter$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("writter",&initer));
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

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    if ((iport$0.get_op() == lit$0)) 
        {
            iport$0.get_result() = ::application::addition(iport$0.get_op1(), iport$0.get_op2());
        }
    if ((iport$0.get_op() == lit$1)) 
        {
            iport$0.get_result() = ::application::subtraction(iport$0.get_op1(), iport$0.get_op2());
        }
    if ((iport$0.get_op() == lit$2)) 
        {
            iport$0.get_result() = ::application::multiplication(iport$0.get_op1(), iport$0.get_op2());
        }
    if ((iport$0.get_op() == lit$3)) 
        {
            iport$0.get_result() = ::application::division(iport$0.get_op1(), iport$0.get_op2());
        }
    ::SPL::Functions::Utility::printStringLn(::SPL::spl_cast<SPL::rstring, SPL::BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo >::cast(iport$0));
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



