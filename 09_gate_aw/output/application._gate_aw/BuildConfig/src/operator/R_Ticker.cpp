// eJytkV9vgjAUxXO_1ivFhe4HCzJbxhu5PFHEm1GdSocMGaLu2DPTTD4g6J3vb0rfm3HN_0514tC6syrGBm73mvxFBwALXPhZFl2WYvqT2li1qFUe4G9w8hTtQ6wqEJQhli5jrBrFkdZp_0LZZBrw2oZ5c3iieQ68jf_0XEzWfmbtRgOv2sGbwxvO0dT3Y8f1V_1NOhdrsFmSMIFovPa9i3Ny5AGDvREltmlaua9dC5VqShNroMc5a3pjUdkoMAS447bhL0mw4SXKa4koWdCYqblrjS8tTjG_0MYtvK0BdFKfCq7Cc0Fn6SX40gYFIoM3asjJq4t7_05hedGKqo1Exy_0JUf8P64NGKj_0EgAT0PtyKwpQuuXlGUjFEgrvhSAd2kdFuGnvB0dUo0hKcbvts945wf8gGx7hItOBviOcN4ZA_1He7QS901QwNuqFf2qHu2_1kCLdfdDD




#include "./R_Ticker.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR R_Ticker_Base
#define MY_OPERATOR R_Ticker$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR(), _maxUnackedTupleCount (lit$0), 
  _unackedCount(0), _done(false), _numWaiting(0)
{
    if (_maxUnackedTupleCount == 0)
        _maxUnackedTupleCount = 1;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
    if (port != 0)
        return;
    if (punct == Punctuation::WindowMarker) {
        AutoMutex am(_mutex);
        assert (_unackedCount <= _maxUnackedTupleCount);
        if (_unackedCount == _maxUnackedTupleCount) {
            // Have to wait until we have an opening
            while (!_done) {
                _numWaiting++;
                _waitForACKs.wait(_mutex);
                _numWaiting--;
                if (_done)
                    return;
                if (_unackedCount < _maxUnackedTupleCount)
                    break;
            }
        }
    } else if (punct == Punctuation::FinalMarker) {
        AutoMutex am(_mutex);
        _done = true;
        _waitForACKs.broadcast();
    }

    // Submit after we release the mutex
    submit (punct, 0);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    switch (port) {
        case 0:
            {
                AutoMutex am(_mutex);
                assert (_unackedCount <= _maxUnackedTupleCount);
                if (_unackedCount == _maxUnackedTupleCount) {
                    // Have to wait until we have an opening
                    while (!_done) {
                        _numWaiting++;
                        _waitForACKs.wait(_mutex);
                        _numWaiting--;
                        if (_done)
                            return;
                        if (_unackedCount < _maxUnackedTupleCount) 
                            break;
                    }
                }
                _unackedCount++;
            }
            // After the mutex is released
            submit (tuple, 0);
            break;
        case 1:
            {
                const SPL::BeJwrMSw1TUzOTk0BAA_12ANI& iport$1 =
                    static_cast<const SPL::BeJwrMSw1TUzOTk0BAA_12ANI&>(tuple);
                AutoMutex am(_mutex);
                uint32_t numTuplesToAck = iport$1.get_acked();
                _unackedCount -= numTuplesToAck;
                assert (_unackedCount < _maxUnackedTupleCount);
                if (_numWaiting) {
                    if (_numWaiting == 1 || numTuplesToAck == 1)
                        _waitForACKs.signal();
                    else 
                        _waitForACKs.broadcast(); // let them all fight for it
                }
            }
            break;
    }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::prepareToShutdown()
{
    AutoMutex am(_mutex);
    _done = true;
    _waitForACKs.broadcast();
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("R_Ticker",&initer));
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
    addParameterValue ("maxUnackedTupleCount", SPL::ConstValueHandle(lit$0));
    addParameterValue ("numTuplesToAck");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("011"));
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
    switch(port) {
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
                    $oportBitset.set(2);
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
    case 1:
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



