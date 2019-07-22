// eJy9VF1v2jAU1X3dr0DVHkCdkthUq5RNk1JWpJFkQgo87ClyExesBNuzTYH9_0jkBUj66bGjrlKdY99xzzvW51rJ0loaVzGx8_1_1OGkwXLhqw0VAECz34YrhzHNRtJ3Ts6Wqk4KXD4_1jaeZGqcTGITxjKeMIzCwfrrj8HTKAoLbdhKJsV6FJFCJ8E0_0LK6Gd8FzvzqrJdoeoUP33Q4lXGSYBndz4bBkA_0CeVGBKhFW4FsPknHk_00obxfgM6jN0cgbuXCyoS_1Mlxu5KqEJLklEXoTTfmksfa3cpWbk5MQS44NSDPhR0Y2mOmnnApFCW15lRk_0rN4kGU3R7cr6WiWjPB28qNIjmtrB4jSJ6Hv2ZClzGhNiZFF_0KJtpDhy8hwG1n_12f0W_1ZdZAQaqjh_1ADWwlwl6QVCyj8FgKYvoYvi8JNza9sGS8_0m8ENvVoP60jZb9NXiPB92vccMkzY71q35_1uF8ZK4SapaSLe7dYh7Vx3dggtyzQj2nw8nOe7zkUqOp98v_0rR3Xno9Xof3oC90pOhnNvG_03v7L7bRq9rGl9j2QPzrJJ5l0DtJoXeWQ_08FbV61JshKRDuJ6BUlIkB_19JwdG2lQz84OUXWxBZ26bWCN_00PUvtoCX1rPVp0HD85uej8BPnUmDF




#include "./M_Ticker.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR M_Ticker_Base
#define MY_OPERATOR M_Ticker$OP


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{  

    AutoPortMutex apm(_mutex, *this);


    switch (port) { 
    case 0:
        processKey(tuple);
        break;
    case 1:
        processAddKey(tuple);
        break;
    
    case 2:
        processRemoveKey(tuple);
        break;
    
    default: assert(!"cannot happen");
    }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::processKey(Tuple const & tuple)
{
    const IPort0Type & iport$0 = static_cast<const IPort0Type&>(tuple);
    KeyType key(iport$0.get_symbol(), iport$0.get_tradetype());
    if(set_.count(key))  
        submit(tuple, 0);

   else
       submit(tuple, 1);


}

void MY_OPERATOR_SCOPE::MY_OPERATOR::processAddKey(Tuple const & tuple)
{
    const IPort1Type & iport$1 = static_cast<const IPort1Type&>(tuple);
    KeyType addKey(iport$1.get_symbol(), iport$1.get_tradetype());
    set_.insert(addKey);
}


    void MY_OPERATOR_SCOPE::MY_OPERATOR::processRemoveKey(Tuple const & tuple)
    {
        const IPort2Type & iport$2 = static_cast<const IPort2Type&>(tuple);
        KeyType removeKey(iport$2.get_symbol(), iport$2.get_tradetype());
        set_.erase(removeKey);
    }


void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{

    AutoPortMutex apm(_mutex, *this);


    if(port==0 && punct==Punctuation::WindowMarker)
        forwardWindowPunctuation(punct);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    ckpt << set_;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    set_.clear();
    ckpt >> set_;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    set_.clear();
}


static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("M_Ticker",&initer));
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
    addParameterValue ("key");
    addParameterValue ("key");
    addParameterValue ("addKey");
    addParameterValue ("addKey");
    addParameterValue ("removeKey");
    addParameterValue ("removeKey");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset.push_back(OPortBitsetType(std::string("0111")));
    $oportBitset.push_back(OPortBitsetType(std::string("0111")));
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
        case 1:
        {
            IPort1Type const & iport$1 = static_cast<IPort1Type const  &>(tuple);
            AutoPortMutex $apm($svMutex, *this);
            
::SPL::Functions::Utility::printStringLn((lit$0 + ::SPL::spl_cast<SPL::rstring, SPL::BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk >::cast(iport$1)));

        }
        break;
        case 2:
        {
            IPort2Type const & iport$2 = static_cast<IPort2Type const  &>(tuple);
            AutoPortMutex $apm($svMutex, *this);
            
::SPL::Functions::Utility::printStringLn((lit$1 + ::SPL::spl_cast<SPL::rstring, SPL::BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk >::cast(iport$2)));

        }
        break;
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
            for (uint32_t i = 0; i < 2; ++i) {
                bool forward = false;
                {
                    AutoPortMutex $apm($fpMutex, *this);
                    $oportBitset[i].reset(port);
                    if ($oportBitset[i].none()) {
                        $oportBitset[i].set(3);
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
    case 1:
        punctNoPermitProcessRaw(punct, port);
        break;
    case 2:
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



