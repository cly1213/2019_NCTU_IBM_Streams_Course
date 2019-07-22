// eJytkk9Pg0AQxTNfpfHQXmCXVk24VauJClVDe24oHWGFsuvukIqf3i39E0FjLw2nXd6bfe_0XMapwKhKFoNr3JzipVCGSmBA4MPtx6DmOS7VC9wYfNzqMmBckuannOU1NbmZG6mluTJCUD0H94QW32bS29195StF7SE_0hCmfpfDy7Hr2OtZP1mpn2tQsG0Uvg_02_0FjOlqBABuJtfo4qryPHcjdW5UnKDL2WJl7_1apFvHGXcUUQylLZOABiTU_0V2RntqYdnhgTabGsCO81IuRYH4Ta2B9latMIJbWVOinSQphl2R_1A3afSaIyQZUNhr9gZz0ABBOgGLsClLUAFwiHONsDxEFeUSX08qmpZCJPhjxstEoSm89CzMBjIc0dd26jdkPx_1iI3YUmx1OeHZg_080PmHaqa3tN5kTzqNha25B5K1NGnpd41bcH_1Bmi3ew_0Xn3ogubtTmyLiP2R3vWKcVs3m9TN0Ti




#include "./vBook.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR vBook_Base
#define MY_OPERATOR vBook$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
:
        
            _diff (lit$0)
        
{
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{

    AutoPortMutex apm(_mutex, *this);


    const IPort0Type& iport$0 = static_cast<const IPort0Type&>(tuple);

    // Check to see if this tuple has been seen recently - create the key
    
        double newVal = SPL::Functions::Time::getTimestampInSecs();
    
    ListDataType newValue(KeyType(iport$0.get_isbn()), newVal);
    
    TupleMapType::iterator it = _map.find(newValue._key);
    if (it != _map.end()) {
        // We found an old one - Is it still valid?
        if ((newVal - it->second->_value) > _diff) {
            // long enough ago....
            OPort0Type otuple(iport$0); submit (otuple, 0);
 
            _list.push_front(newValue);
            _list.erase(it->second);
            it->second = _list.begin();  // restart the counter
        } else {
            
                // else suppress this one and reset the value
                _list.push_front(newValue);
                _list.erase(it->second);
                it->second = _list.begin();
            
            
                submit (tuple, 1);
            
        }
    } else {
        // Haven't seen this one
        OPort0Type otuple(iport$0); submit (otuple, 0);

        _list.push_front(newValue);
        _map.insert(make_pair(newValue._key, _list.begin()));
    }

    // Keep the map a reasonable size by cleaning up elements that have expired
    while (!_list.empty()) {
        ListDataType & oldest = *_list.rbegin();
        // Look at the list to see if we should remove it
        if ((newVal - oldest._value) < _diff) 
            break; // list is ordered, no need to continue
        // Remove from the map and the list
        TupleMapType::iterator it = _map.find(oldest._key);
        assert(it != _map.end()); 
        _map.erase(it);  
        _list.pop_back();
    }

    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port)
{
    
    forwardWindowPunctuation(punct);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetCommon()
{
    _list.clear();
    _map.clear();
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);
    resetCommon();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    
    uint32_t listSize = _list.size();
    ckpt << listSize;

    for (TupleListType::reverse_iterator rit = _list.rbegin(); 
         rit != _list.rend(); rit++) {
        ListDataType & item = *rit;
        item.checkpoint(ckpt);
    }
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    resetCommon();

    
    uint32_t listSize = 0;
    ckpt >> listSize;

    ListDataType item;
    for (uint32_t i = 0; i < listSize; i++) {
        item.reset(ckpt);
        _list.push_front(item);
        _map.insert(make_pair(item._key, _list.begin()));
    }
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("vBook",&initer));
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
    addParameterValue ("timeOut", SPL::ConstValueHandle(lit$0));
    addParameterValue ("key");
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



