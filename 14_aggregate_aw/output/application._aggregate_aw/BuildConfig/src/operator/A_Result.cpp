// eJytkV1vgjAYhfP_0FbMLveFLTBx36MwiEaIrXpsGOqzyUUtZgV8_10OHHXOKSLb1p3_0Sc9zynOYsVTmIsaJbi2LLsKOIkwoKADlpzDOgpiioqRtQJcSR3kWagwMwPSBr_02PyoUc4OVOredDdfVDsPodqp3TH3glj3Z2MhUCl9FHs_0LR1_1NbMFC9DEUba9O9_097rkjj9vffFZh9f429Nfmq1u_1SCmf7Xk1ZTee4_0Xat7XWU2tSx1Q8aYCWC8uiqRgaAKBus4SoJCwMQ5UZ3_0cMB0TVzQ3uaDdYqiEWGNIsJdrRRwPKMn72_0kd6oMDbFZouaNIUfZW1i386ACMIqKiA54LTNIIgK1LBL2_0WseL0d1CcDBI7It2dzcIiaODCbtBCZT9A_1bV6SBogExJcLu8C6S4um8XHdV_0jc7NKRMTmwtAftBbuFcFDcYvbymh6K6PpL2X3HT3SnhX9QdPnJ3oAARF




#include "./A_Result.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR A_Result_Base
#define MY_OPERATOR A_Result$OP



#include <SPL/Toolkit/TumblingAggregate.h>
#include <SPL/Runtime/Window/TumblingWindowSummarizer.h>

#include <SPL/Runtime/Operator/OperatorMetrics.h>



#define MY$OP MY_OPERATOR_SCOPE::MY_OPERATOR
struct MY_OPERATOR::Tumbling$A_Result :
	public  SPL::TumblingWindowSummarizer<MY$OP::IPort0Type,MY$OP::PartitionByType> {
    MY$OP& _oper;
    uint64_t _count;
    SPL::TumblingAggregate::Max<SPL::uint32, SPL::uint32 > Max$maxPopulation;
    SPL::TumblingAggregate::Max<SPL::uint32, SPL::uint32 > Max$maxMAge;
    SPL::TumblingAggregate::Min<SPL::uint32, SPL::uint32 > Min$minMAge;
    SPL::TumblingAggregate::Min<SPL::uint32, SPL::uint32 > Min$minpEducated;

    Tumbling$A_Result (SPL::Operator& oper)
        : _oper(static_cast<MY$OP&>(oper)) {
    _count = 0;
    }

    void onTupleInsertionEvent(MY$OP::IPort0Type const& tuple) {
        _count++;
        MY$OP::IPort0Type const & iport$0 = static_cast<MY$OP::IPort0Type const>(tuple);
        Max$maxPopulation.tupleInserted(iport$0.get_population());
        Max$maxMAge.tupleInserted(iport$0.get_mAge());
        Min$minMAge.tupleInserted(iport$0.get_mAge());
        Min$minpEducated.tupleInserted(iport$0.get_pEducated());
    }
};


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::TimeWindowPolicy(lit$0)),
  _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions")) 
{

    _window.registerBeforeWindowFlushHandler(this);
    _window.registerWindowSummarizer<MY_OPERATOR::Tumbling$A_Result>();
    
    

    
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
        MY_OPERATOR::Tumbling$A_Result& summarizer =
            *static_cast<MY_OPERATOR::Tumbling$A_Result*>(twindow.getSummarizer(partition));
    



    
        if (summarizer._count == 0) {
    
            submit(Punctuation::WindowMarker, 0);
            return;
        }



    
    

        // Populate the tuple
        
        
        SPL::BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0 otuple(summarizer.Max$maxPopulation(), summarizer.Max$maxMAge(), summarizer.Min$minMAge(), summarizer.Min$minpEducated());
        submit (otuple, 0);



    submit(Punctuation::WindowMarker, 0);
}





static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("A_Result",&initer));
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



