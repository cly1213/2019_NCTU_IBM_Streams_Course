// eJy1Uk1PgzAYzvtXjAe9AGXTzN2YLsY5iLPs4mVpoGId0NoWC_1v1Fieb24x60PQCzfs87_1NRJXJH0pxoxkuSD4dBlkmaEU0BgWePD0eO4_0pGUHdEJ0aG2PNx0lcv2PjxoP_06wkq8MIOiy_0ebafMcYbyarMKBjJIcxeOB1rg2Mc6jmNWTeDYOtEjwaOI8HR3wKhSFZ5EM9nhmafN434vn_1etwdWWMuQhumkux5cTLQz3ZLJjdqofRvN3jWSc508ce4LvpcMhK3fMBwH3iBXVpWvm_0a7hcKkES6qL_0gnQJLIhxU6IJlLykLUsmeSVGjc3knUkqLVmZ2QVMcGkXOBnVi4Tp5uQUxrWQVCmb6rfDvCq13JtH26E19g_0DBwayTcRDmhW240_0RdCmtD8AZtFagE_14hdfMvuKjWzwaqNUERZLT7FuO0SmyGaXfRmuJfmPqP1qGwJs_0hIPXdgUgUktqKeZfwcbVbydaXbcVShJ9c_1QhuI2hhrNyFsfKXsMPcfsJuEJZgpzA0JUp30G_1f6n61v0F2D9f2_0gbXmVxh




#include "./B_Result.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR B_Result_Base
#define MY_OPERATOR B_Result$OP



#include <SPL/Toolkit/TumblingAggregate.h>
#include <SPL/Runtime/Window/TumblingWindowSummarizer.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>

#include <memory>

#define MY$OP MY_OPERATOR_SCOPE::MY_OPERATOR
struct MY_OPERATOR::Tumbling$B_Result$G {
    MY$OP& _oper;
    uint64_t _count;
    SPL::TumblingAggregate::Max<SPL::uint32, SPL::uint32 > Max$maxPopulation;
    SPL::TumblingAggregate::Max<SPL::uint32, SPL::uint32 > Max$maxMAge;
    SPL::TumblingAggregate::Min<SPL::uint32, SPL::uint32 > Min$minMAge;
    SPL::TumblingAggregate::Min<SPL::uint32, SPL::uint32 > Min$minpEducated;
    SPL::TumblingAggregate::Last<SPL::rstring, SPL::rstring > Last$city;
    SPL::TumblingAggregate::Last<SPL::rstring, SPL::rstring > Last$country;

    Tumbling$B_Result$G (MY$OP& oper) : _oper(oper) {
    _count = 0;
    }

    void onTupleInsertionEvent(MY$OP::IPort0Type const& tuple) {
        _count++;
        MY$OP::IPort0Type const & iport$0 = static_cast<MY$OP::IPort0Type const>(tuple);
        Max$maxPopulation.tupleInserted(iport$0.get_population());
        Max$maxMAge.tupleInserted(iport$0.get_mAge());
        Min$minMAge.tupleInserted(iport$0.get_mAge());
        Min$minpEducated.tupleInserted(iport$0.get_pEducated());
        Last$city.tupleInserted(iport$0.get_city());
        Last$country.tupleInserted(iport$0.get_country());
    }
};

   struct Tumbling$B_Result : public  SPL::TumblingWindowSummarizer<MY$OP::IPort0Type,MY$OP::PartitionByType> {
       typedef std::tr1::unordered_map<MY$OP::GroupByType,MY_OPERATOR::Tumbling$B_Result$G*> MapType;
       MapType _map;
       uint64_t _count;
       MY$OP& _oper;
       Tumbling$B_Result (SPL::Operator& oper)
           : _oper(static_cast<MY$OP&>(oper)) { _count = 0; }
       ~Tumbling$B_Result () { clearPartitions(); }
   
       void onTupleInsertionEvent(MY$OP::IPort0Type const& tuple) {
           _count++;
           MY$OP::IPort0Type const & iport$0 = tuple;
           MY$OP::GroupByType key(iport$0.get_city(), iport$0.get_country());
           MapType::iterator it = _map.find(key);
           if (it == _map.end()) {
               std::auto_ptr<MY_OPERATOR::Tumbling$B_Result$G> p(new MY_OPERATOR::Tumbling$B_Result$G(_oper));
               p->onTupleInsertionEvent(tuple);
               _map.insert(std::make_pair(key, p.release())); // nothrow
           }
           else {
               it->second->onTupleInsertionEvent(tuple);
           }
       }

    private:
       void clearPartitions() {
           for (MapType::iterator it = _map.begin(); it != _map.end(); it++) {
               delete it->second;
           }
           _map.clear();
       }
   };

   static SPL::list<SPL::int32> CountByGroup(Tumbling$B_Result::MapType& map)
   {
       SPL::list<SPL::int32> res;
       res.reserve (map.size());
       for (Tumbling$B_Result::MapType::const_iterator it = map.begin(); it != map.end(); it++)
           res.push_back (it->second->_count);
       return res;
   }
   

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::TimeWindowPolicy(lit$0)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions")) 
{

    _window.registerBeforeWindowFlushHandler(this);
    _window.registerWindowSummarizer<Tumbling$B_Result>();
    
    

    
    _partitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the window
     _window.deleteWindowObjects();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::drain() 
{
    SPLAPPTRC(L_DEBUG, "Before draining window", SPL_OPER_DBG);
    _window.drain();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_TRACE, "Before checkpoint window is: " << _window.toString(), SPL_OPER_DBG);
    _window.checkpoint(ckpt);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    _window.reset(ckpt);
    SPLAPPTRC(L_TRACE, "After reset window is: " << _window.toString(), SPL_OPER_DBG);

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "Resetting window to initial state", SPL_OPER_DBG);
    _window.resetToInitialState();

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{

    AutoPortMutex apm(_mutex, *this);

    IPort0Type const & iport$0 = static_cast<IPort0Type const &>(tuple);



    _window.insert(SPL::Creator<WindowType::TupleType>::create(iport$0));

    _partitionCount.setValueNoLock(_window.getWindowStorage().size());
}



void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeWindowFlushEvent(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
  SPLAPPTRC(L_DEBUG, window.toString() << " partition " << partition, SPL_OPER_DBG);
    aggregatePartition(window, partition);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::aggregatePartition(
        WindowEventType::WindowType & window, 
        WindowEventType::PartitionType const & partition) 
{
    
        WindowType& twindow = static_cast<WindowType&>(window);
        Tumbling$B_Result& summarizer =
            *static_cast<Tumbling$B_Result*>(twindow.getSummarizer(partition));
    



    
        if (summarizer._count == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }


    
        Tumbling$B_Result::MapType::iterator it;
        for (it = summarizer._map.begin(); it != summarizer._map.end(); it++) {
            Tumbling$B_Result$G& data = *it->second;
    


    
    

        // Populate the tuple
        
        
        SPL::BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU otuple(data.Max$maxPopulation(), data.Max$maxMAge(), data.Min$minMAge(), data.Min$minpEducated(), data.Last$city(), data.Last$country());
        submit (otuple, 0);

    }



    submit(Punctuation::WindowMarker, 0);
}





static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("B_Result",&initer));
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
    addParameterValue ("groupBy");
    addParameterValue ("groupBy");
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



