// eJy1VNFyojAUnfxJp7MP7YskaFvXmT6gddsKsnWjnbYvDoUsRoGkIRTx6zdYrCDa7s7uDk9cck7uOedeYh40BAkcSVnkBJ3OgNEIIADV0wLHjYYmM060LhmkYoghyhYplws_1sfDFYAWhNOdPA4yXA2v8_0GoO_0Z05gYn5PGFWvzk024v4ZTQyxm5r1H1ozI5rfAtk93yWLdp8jM8VX8rtOe67ryl2kW1ZI271p8g2h4oHwtSic3M8Sa8d2r3x6nQxTv_08PYWxb3vmcnR3f73kve8P54PECTj377_0Fbsj502MqJ49G4huzq97unZmwbxfNlbuycAazFW5LjPVs1Q9sc4r6N_1EotencGg_0zbmwY7Nk4u8oZIDgDAZVfIMB3VqeT0Eg2dbAuoXpJfyuVKs1apVWpAG3GQqIRL9F1LWViEXPHJRq8mM5VtprnSAdELCJ5wE7gM0HlLFSR58kbga_16o1FEBOglsWShRSURTgBCR7ozUDT4zFhAnHxOTihnQjXe8ImccsG8xJVT6p2cHl1eHq1VnoL_0kgsSx2rAAHlR7lKZWTd4wyViKWi0vnZNBctUJ3vRPw6jK43YTkiqDPr2mjf8PxhsQIFQtAgijwTKW1TOEBW5VopVqblbALksiWRxrAzV16sI1MxQDxR4d52MimijXmVK3l8K8e_1vyrRIKtfAe0uFVRUH_1mIVtwZIGpI9Gpr510MCW4XAFtiOz6bVUo4H5XBBXQJ_0Bsx544SA1QL_0_178GECoPvpYyQqC6zHsyr8WIPt6JzXkFrQT_0CSw_1qyC7Y_1EJaruA9fn5SNnm9PbG6eem1H8fe6M_12PK_0rd_0diwK6KexC1eGSVv33Ot6Kzb_0gX58_1E2W




#include "./InnerJoin2.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR InnerJoin2_Base
#define MY_OPERATOR InnerJoin2$OP



#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>
#include <stdexcept>


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR(),
  _windowLHS(*this, 0, ::SPL::DeltaWindowPolicy<IPort0Type*,SPL::uint32,&IPort0Type::get_id>(lit$1), ::SPL::CountWindowPolicy(lit$2)),
  _winLHSHandler (*this),
  _windowRHS(*this, 1, ::SPL::TimeWindowPolicy(lit$3), ::SPL::CountWindowPolicy(lit$4)),
  _winRHSHandler (*this),
  _lhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsLHS")),
  _rhsPartitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitionsRHS"))

{
    resetSubmitted();

    _windowLHS.registerBeforeTupleEvictionHandler(&_winLHSHandler);
    _windowRHS.registerBeforeTupleEvictionHandler(&_winRHSHandler);

    
    
    
        
    
    
    
    _emptyCountLHS = (lit$1==0) && (_windowLHS.getEvictionPolicy().getType()==WindowPolicy::Count);
    _emptyCountRHS = (lit$3==0) && (_windowRHS.getEvictionPolicy().getType()==WindowPolicy::Count);
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
    
        IPort0Type const & iport$0 = Referencer<WindowLHSTupleType>::dereference(tuple);

        EqualityKeyType key (iport$0.get_product());
        LHSEqMapType::iterator eqIt = _LHSEq.find (key);
        assert (eqIt != _LHSEq.end());
        LHSEqType& data = eqIt->second;
        
            if (data.front() == tuple)
                data.pop_front();
            else {
                std::deque<WindowLHSTupleType>::iterator it =
                    std::find (data.begin(), data.end(), tuple);
                assert (it != data.end());
                data.erase(it);
            }
            if (data.size() == 0)
                _LHSEq.erase(eqIt);
        
    
    _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
    Allocator<WindowLHSTupleType>::deallocate(tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::evictLHS (WindowLHSTupleType & tuple)
{
    
    cleanLHS (tuple);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::cleanRHS (WindowRHSTupleType & tuple)
{
    
        IPort1Type const & iport$1 = Referencer<WindowRHSTupleType>::dereference(tuple);
        EqualityKeyType key (iport$1.get_productName());
        RHSEqMapType::iterator eqIt = _RHSEq.find (key);
        assert (eqIt != _RHSEq.end());
        RHSEqType& data = eqIt->second;
        
            if (data.front() == tuple)
                data.pop_front();
            else {
                RHSEqType::iterator it =
                    std::find (data.begin(), data.end(), tuple);
                assert (it != data.end());
                data.erase(it);
            }
            if (data.size() == 0)
                _RHSEq.erase(eqIt);
        
    
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
        
        
            EqualityKeyType key (iport$0.get_product());
        
        if (!_emptyCountRHS) {
            AutoWindowDataAcquirer<WindowRHSTupleType,PartitionByRHSType,WindowRHSType::DataType,WindowRHSType::StorageType> awda(_windowRHS);
            
                RHSEqMapType::const_iterator it = _RHSEq.find (key);
                if (it != _RHSEq.end()) {
                    const RHSEqType& data = it->second;
                    
                        for (RHSEqType::const_iterator it2 = data.begin();
                                it2 != data.end(); it2++) {
                            const IPort1Type& iport$1 =
                                static_cast<const IPort1Type&>(**it2);
                            if ((iport$1.get_product_id() == lit$0)) {
                                match = true;
                                
                                OPort0Type otuple (iport$0.get_id(), iport$0.get_customer(), iport$0.get_date(), iport$0.get_product(), iport$0.get_quantity(), iport$1.get_product_id(), iport$1.get_productName(), iport$1.get_price(), iport$1.get_quantity());
                                submit (otuple, 0);
                            }
                        }
                    
                }
            
            _rhsPartitionCount.setValueNoLock (_windowRHS.getWindowStorage().size());
        }
        if (!_emptyCountLHS) {
            WindowLHSTupleType newTuple = Creator<WindowLHSTupleType>::create(tuple);
            
              {
                AutoWindowDataAcquirer<WindowLHSTupleType,PartitionByLHSType,WindowLHSType::DataType,WindowLHSType::StorageType> awda(_windowLHS);
                LHSEqMapType::iterator eqIt = _LHSEq.find(key);
                if (eqIt == _LHSEq.end())
                    eqIt = _LHSEq.insert (
                        LHSEqMapType::value_type(key, LHSEqType())).first;
                
                    eqIt->second.push_back(newTuple);
                
              }
            
            
            _windowLHS.insert (newTuple);
            _lhsPartitionCount.setValueNoLock (_windowLHS.getWindowStorage().size());
        } else {
                        
        }
    } else { // RHS
        SPLAPPTRC(L_DEBUG, "RHS process tuple " << tuple, SPL_OPER_DBG);
        const IPort1Type& iport$1 = static_cast<const IPort1Type&>(tuple);
        
        
            EqualityKeyType key (iport$1.get_productName());
        
        if (!_emptyCountLHS) {
            AutoWindowDataAcquirer<WindowLHSTupleType,PartitionByLHSType,WindowLHSType::DataType,WindowLHSType::StorageType> awda(_windowLHS);
            
                LHSEqMapType::const_iterator it = _LHSEq.find (key);
                if (it != _LHSEq.end()) {
                    const LHSEqType& data = it->second;
                    
                        for (LHSEqType::const_iterator it2 = data.begin();
                                it2 != data.end(); it2++) {
                            const IPort0Type& iport$0 =
                                static_cast<const IPort0Type&>(**it2);
                            if ((iport$1.get_product_id() == lit$0)) {
                                match = true;
                                
                                OPort0Type otuple (iport$0.get_id(), iport$0.get_customer(), iport$0.get_date(), iport$0.get_product(), iport$0.get_quantity(), iport$1.get_product_id(), iport$1.get_productName(), iport$1.get_price(), iport$1.get_quantity());
                                submit (otuple, 0);
                            }
                        }
                    
                }
            
        }
        if (!_emptyCountRHS) {
            WindowRHSTupleType newTuple = Creator<WindowRHSTupleType>::create(tuple);
            
              {
                AutoWindowDataAcquirer<WindowRHSTupleType, PartitionByRHSType,WindowRHSType::DataType,WindowRHSType::StorageType> awda(_windowRHS);
                RHSEqMapType::iterator eqIt = _RHSEq.find(key);
                if (eqIt == _RHSEq.end())
                    eqIt = _RHSEq.insert (
                        RHSEqMapType::value_type(key, RHSEqType())).first;
                
                    eqIt->second.push_back(newTuple);
                
              }
            
            
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

    
    {
        _LHSEq.clear();
        if (!_emptyCountLHS) {
            SPL::AutoWindowDataAcquirer<WindowLHSTupleType,PartitionByLHSType,WindowLHSType::DataType,WindowLHSType::StorageType> dataAcquirer(_windowLHS);
            WindowLHSType::StorageType const & storage = dataAcquirer.getWindowStorage();
            for (WindowLHSType::StorageType::const_iterator storageIt = storage.begin(); storageIt != storage.end(); ++storageIt) {
                WindowLHSType::DataType const & data = storageIt->second;
                for (WindowLHSType::DataType::const_iterator dataIt = data.begin(); dataIt != data.end(); ++dataIt) {
                    WindowLHSTupleType const& tuple = *dataIt;
                    IPort0Type const & iport$0 = Referencer<WindowLHSTupleType>::dereference(tuple);
                    
                    EqualityKeyType key (iport$0.get_product());
                    LHSEqMapType::iterator eqIt = _LHSEq.find(key);
                    if (eqIt == _LHSEq.end())
                        eqIt = _LHSEq.insert(LHSEqMapType::value_type(key, LHSEqType())).first;
                    
                    eqIt->second.push_back(tuple);
                    
                }
            }
        }
    }
    
    
    {
        _RHSEq.clear();
        if (!_emptyCountRHS) {
            SPL::AutoWindowDataAcquirer<WindowRHSTupleType,PartitionByRHSType,WindowRHSType::DataType,WindowRHSType::StorageType> dataAcquirer(_windowRHS);
            WindowRHSType::StorageType const & storage = dataAcquirer.getWindowStorage();
            for (WindowRHSType::StorageType::const_iterator storageIt = storage.begin(); storageIt != storage.end(); ++storageIt) {
                WindowRHSType::DataType const & data = storageIt->second;
                for (WindowRHSType::DataType::const_iterator dataIt = data.begin(); dataIt != data.end(); ++dataIt) {
                    WindowRHSTupleType const & tuple = *dataIt;
                    IPort1Type const & iport$1 = Referencer<WindowRHSTupleType>::dereference(tuple);
                    
                    EqualityKeyType key (iport$1.get_productName());
                    RHSEqMapType::iterator eqIt = _RHSEq.find(key);
                    if (eqIt == _RHSEq.end())
                        eqIt = _RHSEq.insert(RHSEqMapType::value_type(key, RHSEqType())).first;
                    
                    eqIt->second.push_back(tuple);
                    
                }
            }
        }
    }
    

     
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);
    
    SPLAPPTRC(L_DEBUG, "resetToInitialState", SPL_OPER_DBG);
    _windowLHS.resetToInitialState();
    _windowRHS.resetToInitialState();    

    
      _LHSEq.clear();
      _RHSEq.clear();

    

    
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
    instantiators_.insert(std::make_pair("InnerJoin2",&initer));
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
    param$algorithm$0 = "inner";
    addParameterValue ("algorithm", SPL::ConstValueHandle(param$algorithm$0));
    addParameterValue ("match");
    addParameterValue ("equalityLHS");
    addParameterValue ("equalityRHS");
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


