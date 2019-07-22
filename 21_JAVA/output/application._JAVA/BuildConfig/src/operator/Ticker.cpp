// eJy1VV1v2jAUlV_17K6yqk5KpSuxQaBcGEmXtAzRVpaC9Ije4xSJfi51SivjvSxwToIatqmh4wLofJ_0ce33vD09DKBQuZWLhuP_0ciiQAGqPhhcGpZtlik1L6mg3nm_0cgZti69UZA9_0CNPDL3UGzEHD_1uv92_19l8HdcMYFm6f_07HVwR2bc7zuOf1P8_043B2w267d3_1wtde05qegkvABRH0LIgF8B_1uXDdnsWg4O2cMCk5nLRXJF9FjEvIqImRc_1JSnjIuMxc_0we9hR4azfmGYsoBrMU5iQ4p06zMaBgetKE0_1DcUDWAXtCz_0E_0T_0sCdmHXdctUo2R0ZSpKf3ISCyaYTqtSQmdV26vafiggkZEJLe_1r8zJh9B6LxRMWEJFk_17kojFVmRnkeqms9Zt98ASI6PqZhWkFISWaYADtSGLQjVqUV2O6LyuboYQ3ddKGbmrqppZsuD9_089F_1t7fyyaYHqsUM9uO6bf_0NjvMsJ2NMkojad5I5jz5NsxlMSUNvB40Hvd8_0eEEFAnMS0WkQIsDTJai2P2gQRyOS6W57A4qn3EuzALcLG3uGvfGrea8HUjK9TbvM4ECyJuet6REwLZUg8SSLDhN_0hVMY04Td5QmZbcmBP0DAOjSHsdGSwU6TJ6PJZ1qdNDftSZWajXUev5ImGnH4O6uI91PYKsJ6pGFd7uyi2A3cWuUWEUWut6taS1WZcbKVvluWHEOS630qv1v_0HUuuit9I3G3YDoYujECcJXMKj9ysUNEprQhXfNuT5Y8QENErnubyaptmGKzifspAaZWOtTgBogkp9oIYTSDmA_0nKBtdxADWldWR1fjCUVLNoYytFMvnQ0Nc7oHWuk8UZ7mCOdOyrI_1wUzh80F


#include "./Ticker.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR Ticker_Base
#define MY_OPERATOR Ticker$OP




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("Ticker",&initer));
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
    state$cnt = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
    state$symbols = lit$7;
    SPLAPPTRC(L_DEBUG, "Variable: state$symbols Value: " << state$symbols,SPL_OPER_DBG);
    state$prices = ::SPL::spl_cast<SPL::list<SPL::float32 >, SPL::list<SPL::float64 > >::cast(lit$8);
    SPLAPPTRC(L_DEBUG, "Variable: state$prices Value: " << state$prices,SPL_OPER_DBG);
    state$quantities = lit$9;
    SPLAPPTRC(L_DEBUG, "Variable: state$quantities Value: " << state$quantities,SPL_OPER_DBG);
    state$tradetypes = lit$10;
    SPLAPPTRC(L_DEBUG, "Variable: state$tradetypes Value: " << state$tradetypes,SPL_OPER_DBG);
    state$tradetypeindicator = lit$11;
    SPLAPPTRC(L_DEBUG, "Variable: state$tradetypeindicator Value: " << state$tradetypeindicator,SPL_OPER_DBG);
    state$result = SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5().clear();
    SPLAPPTRC(L_DEBUG, "Variable: state$result Value: " << state$result,SPL_OPER_DBG);
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
    state$cnt = SPL::uint32(::SPL::spl_cast<SPL::uint32, SPL::float64 >::cast((::SPL::Functions::Math::random() * lit$1)) % lit$0);
    if ((state$tradetypeindicator == lit$2)) 
        {
            state$tradetypeindicator = lit$3;
        }
    else
        {
            state$tradetypeindicator = lit$4;
        }
    state$result.get_symbol() = state$symbols.at(state$cnt);
    state$result.get_quantity() = state$quantities.at(state$cnt);
    state$result.get_price() = state$prices.at(state$cnt);
    state$result.get_tradetype() = state$tradetypes.at(state$tradetypeindicator);
    do { SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 temp = state$result; submit (temp, lit$5); } while(0);
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
    opstate << state$symbols;
    opstate << state$prices;
    opstate << state$quantities;
    opstate << state$tradetypes;
    opstate << state$tradetypeindicator;
    opstate << state$result;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$cnt;
    opstate >> state$symbols;
    opstate >> state$prices;
    opstate >> state$quantities;
    opstate >> state$tradetypes;
    opstate >> state$tradetypeindicator;
    opstate >> state$result;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$cnt;
    ckpt << state$symbols;
    ckpt << state$prices;
    ckpt << state$quantities;
    ckpt << state$tradetypes;
    ckpt << state$tradetypeindicator;
    ckpt << state$result;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$cnt;
    ckpt >> state$symbols;
    ckpt >> state$prices;
    ckpt >> state$quantities;
    ckpt >> state$tradetypes;
    ckpt >> state$tradetypeindicator;
    ckpt >> state$result;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$cnt = lit$6;
    SPLAPPTRC(L_DEBUG, "Variable: state$cnt Value: " << state$cnt,SPL_OPER_DBG);
    state$symbols = lit$7;
    SPLAPPTRC(L_DEBUG, "Variable: state$symbols Value: " << state$symbols,SPL_OPER_DBG);
    state$prices = ::SPL::spl_cast<SPL::list<SPL::float32 >, SPL::list<SPL::float64 > >::cast(lit$8);
    SPLAPPTRC(L_DEBUG, "Variable: state$prices Value: " << state$prices,SPL_OPER_DBG);
    state$quantities = lit$9;
    SPLAPPTRC(L_DEBUG, "Variable: state$quantities Value: " << state$quantities,SPL_OPER_DBG);
    state$tradetypes = lit$10;
    SPLAPPTRC(L_DEBUG, "Variable: state$tradetypes Value: " << state$tradetypes,SPL_OPER_DBG);
    state$tradetypeindicator = lit$11;
    SPLAPPTRC(L_DEBUG, "Variable: state$tradetypeindicator Value: " << state$tradetypeindicator,SPL_OPER_DBG);
    state$result = SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5().clear();
    SPLAPPTRC(L_DEBUG, "Variable: state$result Value: " << state$result,SPL_OPER_DBG);
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



