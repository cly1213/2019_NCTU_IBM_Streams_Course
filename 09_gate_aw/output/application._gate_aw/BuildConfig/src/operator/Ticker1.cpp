// eJytU11v2jAUlV_15FVbVh0RU5ANKNbNOSpkmFUiHlvCM3MQFKx_12YqcpRfz3OSYgWNj6sNkPsU7OvT73nmvB014paUrlBqFxKSTLgANstV1w1etZcsOJ9UAmVeEHiTsd3vlhVMyD0JdTn_1shdZ3p_0O3pffw6mU0TIWnFg_0Rt8hUnIvAW3iMbzL1Vb33VylU54eL9e5jYD563dFzv6bFmuUBILMm1LHlKxA8SEfpKYhDMZwiVNJd99_0zsAKX7_0rYJinL5AXMI7vTXPvunIacNNRkKIQuar_1ZYf4_19sYg9a9BOdtuGhucQsNYsIxaJS9e1KlYkguOIWPan5UpVt8SVFWOJQc5yUttTm0Q5K47V_1KNJIAOF9n3bgWrRF2gY3e4lO_0D9PdRdNE2oufXaHk_11uhymo5zRGRMhLf5bmUeSslwgtDhMI1dtl4Fu_1iw3jIYpeLqMsJCfT825gSethF8QqhlH_0WowTNjVt7umeX5_1zOAW_1t1TKEnGG_1X9ERTlc0YlNGr0RoMDcwR3sFrTlBj2Sf5dZ9cBYADEJntmKTgMkqorIuAlZbj2_1WeJc6nqBc0cyALHJFQv5ch3lSnsfzvdUmX_1pstuKbMvaLMdPYp7ec5Hj6O_02AE4StSbPiRVCX4BEb5aBh


#include "./Ticker1.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Ticker1_Base
#define MY_OPERATOR Ticker1$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Ticker1",&initer));
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
    state$tuplesReceived = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$tuplesReceived Value: " << state$tuplesReceived,SPL_OPER_DBG);
    state$cnt = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
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
    if ((++state$tuplesReceived == lit$0)) 
        {
            state$tuplesReceived = lit$1;
            ::SPL::Functions::Utility::printStringLn((::SPL::spl_cast<SPL::rstring, SPL::uint32 >::cast(++state$cnt) + lit$2));
            do { SPL::BeJwrMSw1TUzOTk0BAA_12ANI temp = lit$3; submit (temp, lit$4); } while(0);
        }
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
            for (uint32_t i = 0; i < 2; ++i) {
                bool forward = false;
                {
                    AutoPortMutex $apm($fpMutex, *this);
                    $oportBitset[i].reset(port);
                    if ($oportBitset[i].none()) {
                        $oportBitset[i].set(1);
                        forward=true;
                    }
                }
                if(forward)
                    submit(punct, i);
            }
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
    opstate << state$tuplesReceived;
    opstate << state$cnt;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$tuplesReceived;
    opstate >> state$cnt;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$tuplesReceived;
    ckpt << state$cnt;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$tuplesReceived;
    ckpt >> state$cnt;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$tuplesReceived = lit$5;
    SPLAPPTRC(L_DEBUG, "Variable: state$tuplesReceived Value: " << state$tuplesReceived,SPL_OPER_DBG);
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



