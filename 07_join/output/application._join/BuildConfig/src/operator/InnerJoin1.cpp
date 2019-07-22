// eJyNU1FvsjAUzf0ny_1I96AtQdPmMyR7AwTaHRoNmj6TTBjugJaV_0CL9_0RdAM1O0LTz3tufeccy9ZGmuCxFhSznA8Hk85ZYDAUN8Q7jVNl0VKdJtMczHzI7NY_15utfAP560i_0TSJkP7wcEp_05bmQ_1L5xwYs2Xz1aRa7v7CzJHK0ORXtliNUlM68mjo8O0XOfu_0zAPl1cZ7XaWY02jtWu73beFmL9Gg3JTen5hFKU_1kr5vFqUTz98C5Lxky3xOP73VrLAzy_0If1sNTVaEyGFP5xwB_14Y3HlMmBCUcEXSDmBTJoIaDveEJ0st2bpp5zEWUp3hDd_0Bt8qjz1LZYYGGfEABMSLDc7aHp8cB4TzJSYHk25UGq0kMhgS1LZ6989Pt7VKDqjAd32_0n1wDqkgWaaGBjgOuaByl6ia1fSsOFTlKGNEwGSfSZ54VBKBY9Vb4XWXuvsvOQMFoSjIQBu_0ZxLQN8uoyU5d37qstwhUW4YTAiKTgrIQKhewPz1s_1LX1_1Lgpv6syf1I1OKtq4jxpUcegJbTSz6_1E9d9_1ASRK6RA6RRuvJ_0A8kuOIq7e9fiejhtGc24R6U7pebnE6e3TN8w15Z2Yj8ZjxF7wTETP




#include "./InnerJoin1.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR InnerJoin1_Base
#define MY_OPERATOR InnerJoin1$OP



#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>
#include <stdexcept>


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR(),
  _windowLHS(*this, 0, ::SPL::CountWindowPolicy(lit$0), ::SPL::CountWindowPolicy(lit$1)),
  _winLHSHandler (*this),
  _windowRHS(*this, 1, ::SPL::CountWindowPolicy(lit$2), ::SPL::CountWindowPolicy(lit$3)),
  _winRHSHandler (*this),
  _lhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsLHS")),
  _rhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsRHS"))

{
    resetSubmitted();

    _windowLHS.registerBeforeTupleEvictionHandler(&_winLHSHandler);
    _windowRHS.registerBeforeTupleEvictionHandler(&_winRHSHandler);

    
    
    
        
    
    
    
    _emptyCountLHS = (lit$0==0) && (_windowLHS.getEvictionPolicy().getType()==WindowPolicy::Count);
    _emptyCountRHS = (lit$2==0) && (_windowRHS.getEvictionPolicy().getType()==WindowPolicy::Count);
    _lhsPartitionCount.setValueNoLock(0);
    _rhsPartitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the windows
    _windowLHS.deleteWindowObjects();
    _windowRHS.deleteWindowObjects();
}





void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanLHS (WindowLHSTupleType & tuple)
{
    
    _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
    Allocator<WindowLHSTupleType>::deallocate(tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::evictLHS (WindowLHSTupleType & tuple)
{
    
    cleanLHS (tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanRHS (WindowRHSTupleType & tuple)
{
    
    _rhsPartitionCount.setValueNoLock (_windowRHS.getWindowStorage().size());
    Allocator<WindowRHSTupleType>::deallocate(tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::evictRHS (WindowRHSTupleType & tuple)
{
    
    cleanRHS (tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) {

    AutoPortMutex apm(_mutex, *this);


    bool match = false;
    resetSubmitted();

    if (port == 0) { // LHS
        SPLAPPTRC(L_DEBUG, "LHS process tuple " << tuple, SPL_OPER_DBG);

        const IPort0Type& iport$0 = static_cast<const IPort0Type&>(tuple);
        
        
        if (!_emptyCountRHS) {
            AutoWindowDataAcquirer<WindowRHSTupleType,PartitionByRHSType,WindowRHSType::DataType,WindowRHSType::StorageType> awda(_windowRHS);
            
                const WindowRHSType::StorageType& map = awda.getWindowStorage();
                WindowRHSType::StorageType::const_iterator it;
                for (it = map.begin(); it != map.end(); it++) {
                    const WindowRHSType::DataType& data = it->second;
                    WindowRHSType::DataType::const_iterator it2;
                    for (it2 = data.begin(); it2 != data.end(); it2++) {
                        const IPort1Type& iport$1 =
                            static_cast<const IPort1Type&>(**it2);
                        if ((iport$0.get_dept() == iport$1.get_dept_id())) {
                            match = true;
                            
                            OPort0Type otuple (iport$0.get_name(), iport$0.get_dept(), iport$1.get_dept_id(), iport$1.get_dep_name());
                            submit (otuple, 0);
                        }
                    }
                }
            
            _rhsPartitionCount.setValueNoLock (_windowRHS.getWindowStorage().size());
        }
        if (!_emptyCountLHS) {
            WindowLHSTupleType newTuple = Creator<WindowLHSTupleType>::create(tuple);
            
            
            _windowLHS.insert (newTuple);
            _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
        } else {
                        
        }
    } else { // RHS
        SPLAPPTRC(L_DEBUG, "RHS process tuple " << tuple, SPL_OPER_DBG);
        const IPort1Type& iport$1 = static_cast<const IPort1Type&>(tuple);
        
        
        if (!_emptyCountLHS) {
            AutoWindowDataAcquirer<WindowLHSTupleType,PartitionByLHSType,WindowLHSType::DataType,WindowLHSType::StorageType> awda(_windowLHS);
            
                const WindowLHSType::StorageType& map = awda.getWindowStorage();
                WindowLHSType::StorageType::const_iterator it;
                for (it = map.begin(); it != map.end(); it++) {
                    const WindowLHSType::DataType& data = it->second;
                    WindowLHSType::DataType::const_iterator it2;
                    for (it2 = data.begin(); it2 != data.end(); it2++) {
                        const IPort0Type& iport$0 = static_cast<const IPort0Type&>(**it2);
                        if ((iport$0.get_dept() == iport$1.get_dept_id())) {
                            match = true;
                            
                            OPort0Type otuple (iport$0.get_name(), iport$0.get_dept(), iport$1.get_dept_id(), iport$1.get_dep_name());
                            submit (otuple, 0);
                        }
                    }
                }
            
        }
        if (!_emptyCountRHS) {
            WindowRHSTupleType newTuple = Creator<WindowRHSTupleType>::create(tuple);
            
            
            _windowRHS.insert (newTuple);
        } else {
                 
        }
    }
    if (_submitted)
        submit(Punctuation::WindowMarker, 0);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::drain()
{
    SPLAPPTRC(L_DEBUG, "drain", SPL_OPER_DBG);
    _windowLHS.drain();
    _windowRHS.drain();	        
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "checkpoint " << ckpt.getSequenceId(), SPL_OPER_DBG);
    _windowLHS.checkpoint(ckpt);
    _windowRHS.checkpoint(ckpt);

     
    
}


void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "reset " << ckpt.getSequenceId(), SPL_OPER_DBG);
    _windowLHS.reset(ckpt);
    _windowRHS.reset(ckpt);

    
    

     
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);
    
    SPLAPPTRC(L_DEBUG, "resetToInitialState", SPL_OPER_DBG);
    _windowLHS.resetToInitialState();
    _windowRHS.resetToInitialState();    

    

    
}

// Serialization support for checkpoints.
// 
// The state for the Join operator contains pointers to tuples.  These
// pointers are created by this class, then inserted into one of the
// windows, and possibly into data structures owned by this class.  The
// same pointers are thus shared by the window and by this class.
// When we checkpoint the state of this operator, we want to store
// each tuple only once, and when the state is restored, restore the
// single instance of each tuple into a new tuple pointer.  To
// accomplish this, we allow the window to actually save the tuples,
// and to create the new pointers on reset.  We create mappings from
// tuple pointer to integer on checkpoint, and from integer to tuple
// pointer (implemented as a vector) on reset.  For each pointer
// referenced in the data structures owned by this class, we look up
// the corresponding integer value and serialize that on checkpoint,
// and on reset, deserialize the integers and look up tuple pointers.

template <typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::deserialize (SPL::Checkpoint & ckpt, std::deque<T> & value, std::vector<T> const & tupleVector) {

    typename std::deque<T>::size_type size = 0;
    ckpt >> size;
    for (typename std::deque<T>::size_type index = 0;
         index != size;
	 ++index) {
	uint64_t tupleIndex;
	ckpt >> tupleIndex;
        T const & tuple = tupleVector.at(tupleIndex);
	value.push_back(tuple);
    }
}


template <typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::serialize (SPL::Checkpoint & ckpt, std::deque<T> const & value, std::tr1::unordered_map<T, uint64_t> const & tupleMap) {
    typename std::deque<T>::size_type size = value.size();;
    ckpt << size;
    for (typename std::deque<T>::const_iterator valueIt = value.begin();
         valueIt != value.end();
         ++valueIt) {
	
        typename std::tr1::unordered_map<T, uint64_t>::const_iterator found = tupleMap.find(*valueIt);
	if (found == tupleMap.end()) {
	  throw std::out_of_range("Value not found in Join::serialize");
	}
	ckpt << found->second;
    }
}

template <typename Key, typename Value, typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::deserialize (SPL::Checkpoint & ckpt, std::tr1::unordered_map<Key, Value> & map, std::vector<T> const & tupleVector) {
    map.clear (); 
    typename Value::size_type size = 0;
    ckpt >> size;
    for (typename Value::size_type index = 0; index != size; ++index) {
        Key key;
        Value value;
        ckpt >> key;
        deserialize (ckpt, value, tupleVector);
        map[key] = value;
    }
}

template <typename Key, typename Value, typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::serialize (SPL::Checkpoint & ckpt, std::tr1::unordered_map<Key, Value> const & map, std::tr1::unordered_map<T, uint64_t> const & tupleMap) {
    ckpt << map.size();
    for (typename std::tr1::unordered_map<Key, Value>::const_iterator it = map.begin();
         it != map.end();
         ++it) {
        Key key = it->first;
        Value value = it->second;
        ckpt << key;
        serialize (ckpt, value, tupleMap);
    }
}

template <typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::deserializeMatches (SPL::Checkpoint& ckpt, std::tr1::unordered_set<T> & matches, std::vector<T> const & tupleVector) {
    typename std::tr1::unordered_set<T>::size_type size = 0;
    ckpt >> size;
    for (typename std::tr1::unordered_set<T>::size_type index = 0; index != size; ++index) {
        uint64_t tupleIndex = 0;
        ckpt >> tupleIndex;
        T const & tuple = tupleVector.at(tupleIndex);
        matches.insert (tuple);
    }
}

template <typename T>
void MY_OPERATOR_SCOPE::MY_OPERATOR::serializeMatches (SPL::Checkpoint& ckpt, std::tr1::unordered_set<T> const & matches, std::tr1::unordered_map<T, uint64_t> const & tupleMap) {
    ckpt << matches.size();
    for (typename std::tr1::unordered_set<T>::const_iterator matchIt = matches.begin(); matchIt != matches.end(); ++matchIt) {
        typename std::tr1::unordered_map<T, uint64_t>::const_iterator tuple = tupleMap.find(*matchIt);
        if (tuple == tupleMap.end()) {
            throw std::out_of_range("Value not found in Join::serializeMatches");
        }       
        ckpt << tuple->second;
    }
}

template<typename T, typename G, typename D, typename S>
void MY_OPERATOR_SCOPE::MY_OPERATOR::populateTupleMap (SPL::Window<T,G,D,S> & window, std::tr1::unordered_map<T, uint64_t> & tupleMap) {
    SPL::AutoWindowDataAcquirer<T,G,D,S> dataAcquirer(window);
    typename SPL::Window<T,G,D,S>::StorageType const & storage = dataAcquirer.getWindowStorage();

    uint64_t index = 0;

    for (typename SPL::Window<T,G,D,S>::StorageType::const_iterator storageIt = storage.begin(); storageIt != storage.end(); ++storageIt) {
        typename SPL::Window<T,G,D,S>::DataType const & data = storageIt->second;
        for (typename SPL::Window<T,G,D,S>::DataType::const_iterator dataIt = data.begin(); dataIt != data.end(); ++dataIt) {
            tupleMap[*dataIt] = index++;
        }
    }
}

template<typename T, typename G, typename D, typename S>
void MY_OPERATOR_SCOPE::MY_OPERATOR::populateTupleVector (SPL::Window<T,G,D,S> & window, std::vector<T> & tupleVector) {
    SPL::AutoWindowDataAcquirer<T,G,D,S> dataAcquirer(window);
    typename SPL::Window<T,G,D,S>::StorageType const & storage = dataAcquirer.getWindowStorage();
    for (typename SPL::Window<T,G,D,S>::StorageType::const_iterator storageIt = storage.begin(); storageIt != storage.end(); ++storageIt) {
        typename SPL::Window<T,G,D,S>::DataType const & data = storageIt->second;
        for (typename SPL::Window<T,G,D,S>::DataType::const_iterator dataIt = data.begin(); dataIt != data.end(); ++dataIt) {
            tupleVector.push_back(*dataIt);
        }
    }
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("InnerJoin1",&initer));
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
    addParameterValue ("match");
    param$algorithm$0 = "inner";
    addParameterValue ("algorithm", SPL::ConstValueHandle(param$algorithm$0));
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


