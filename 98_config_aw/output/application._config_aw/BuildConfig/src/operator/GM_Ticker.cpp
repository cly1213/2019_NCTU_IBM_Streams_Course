// eJzt0k1vgkAQBuDMXzE96IUvv7mhaZOqNCbYs0FcdQOy22Up0l_1fFRcSbNN00x43HMiSeYeZBzKaGDnHCeal6wZU3MEGS1w2dAzD5CVF5gwtCuYHsbMcjf1NxNbBxudLn_1ob7NjL_0eXlY_16_0WC3jjOOCBvFlsQrjLPBevedisJ55xqlT9RO9HywI1ivXZRlnOD0CgHkiZ2Sife44ZkFYnNEwQuZ0so1IesDHbViY_05CHkJIUWeDAASdI9Gp1qVt7XJx3OUdPDCGIUXlfaAGmhIlS44j4NivPO5J0e_1B4oQxlGSZptbusuUX_1uDtgYBUnwABuL4R6GspwhOCQkJD3HXjLw5SLrwA5Tq9nzsI9uvI39fa1D_1nv4b6MZf9SrT1_0k6oftFNVsQjdb9nE5LmdqqtF8BuOn_0dsAt2eXf1_0NzlbyynKOVLO0XKKcn0p19dyinIDKTfQcopyQyk31HKKciMpN9JyinJjKTfWcopyEyk30XKKclMpN9VyanKfzttlAp




#include "./GM_Ticker.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR GM_Ticker_Base
#define MY_OPERATOR GM_Ticker$OP



#include <SPL/Runtime/Common/ApplicationRuntimeMessage.h>


#include <SPL/Toolkit/MapFileParser.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>
#include <streams_boost/filesystem/path.hpp>


using namespace std;

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR()
{
    SPLAPPTRC(L_DEBUG, "Split startup...", SPL_OPER_DBG);

    namespace bf = streams_boost::filesystem;
    bf::path p(lit$0);
    if (!p.is_absolute()) {
        // getDataDirectory will throw an exception if there is no data directory
        p = getPE().getDataDirectory();
        p /= (std::string)lit$0;
    }
    _fileName = p.string();
    SPL::parseMapFile ("Split", getPE(), _fileName, _Map, _Default, _hasDefault);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
    // Send the punctuation everywhere
    forwardWindowPunctuation(punct);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    const IPort0Type& iport$0 = static_cast<const IPort0Type&>(tuple);

    MapType::const_iterator it = _Map.find (iport$0.get_symbol());
    const vector<int64_t> *list = &_Default;
    if (it == _Map.end()) {
        if (!_hasDefault) {
            stringstream key;
            key.imbue(locale::classic());
            key << iport$0.get_symbol();
            SPLTRACEMSGANDTHROW(SPLRuntimeSplitOperator, L_ERROR, SPL_APPLICATION_RUNTIME_SPLIT_NO_DEFAULT(key.str(), _fileName), SPL_OPER_DBG);
        }
    } else
        list = &it->second;

    // And submit the results
    for (uint32_t i = 0, n = list->size(); i < n; i++) {
        int64_t r = (*list)[i];
        if (r < 0)
            continue;
        submit (tuple, r % 10);
    }


}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("GM_Ticker",&initer));
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
    addParameterValue ("file", SPL::ConstValueHandle(lit$0));
    addParameterValue ("key");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
    $oportBitset.push_back(OPortBitsetType(std::string("01")));
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

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
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
            for (uint32_t i = 0; i < 10; ++i) {
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



