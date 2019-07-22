// eJylkD9PwzAQxXVfperQLrGdMGVrpQ6EBCElSDBVVmNaK45t2Q5p_0PQ4_1yiFARDyYp_1fe_1e7s1oEhgnquJJUxHGujAMC2B8CiyBArtMMbVnSmiyvwu7xNStyTLqq1fc8StJMJEWRmcKek_1RO7Ta3b88b_1RScFkOA4G6JIX9I45hLF4UAgE6qZoiVTRiiVpnKanpgiER76zujkjoKUknWu_1vKtvOXIcBYZ7g8_0lyu_1ccSB0fm9pLWbLWG3VkbZq0fYoCfFKPxr_1DAwfT0mBxUI_102PvHPI40H4AZ6AJjZeAnNKHTciUvdUkFNBy9C0TEFg_1oXYu0Rv_1Qmv1rUhfBDP72v5bz04ushfmgwiL3p26yTay5cu0b1au1X8g4Q_1sZ4




#include "./SortByName.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR SortByName_Base
#define MY_OPERATOR SortByName$OP



#include <SPL/Runtime/Common/ApplicationRuntimeMessage.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Utility/LogTraceMessage.h>

MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
  : MY_BASE_OPERATOR(), _window(*this, 0, ::SPL::CountWindowPolicy(lit$0)),
    _partitionCount(getContext().getMetrics().getCustomMetricByName("nCurrentPartitions"))
{


    _window.registerBeforeWindowFlushHandler(this);
    


    _partitionCount.setValueNoLock(0);
}

MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{

    _window.deleteWindowObjects();

}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{

    AutoPortMutex apm(_mutex, *this);

    IPort0Type const & iport$0 = 
        static_cast<IPort0Type const&>(tuple);   

    _window.insert(Creator<WindowType::TupleType>::create(iport$0));

    _partitionCount.setValueNoLock (_window.getWindowStorage().size());

}



void MY_OPERATOR_SCOPE::MY_OPERATOR::beforeWindowFlushEvent(WindowEventType::WindowType & window,
                                         WindowEventType::PartitionType const & partition)


{
     WindowType::DataType & gdata = window.getWindowData(partition);
     TupleComparer comparer(*this);
     std::sort(gdata.begin(), gdata.end(), comparer);
     for(size_t i=0, iu=gdata.size(); i<iu; ++i) {
         submit(*gdata[i], 0);     
         Allocator<WindowType::TupleType>::deallocate(gdata[i]);
     }
     submit(Punctuation::WindowMarker, 0);
     _partitionCount.setValueNoLock(0);
}





bool MY_OPERATOR_SCOPE::MY_OPERATOR::compareTuples(WindowType::TupleType const & l,
                                WindowType::TupleType const & r)
{
    IPort0Type const & lhs = Referencer<WindowType::TupleType>::dereference(l);
    IPort0Type const & rhs = Referencer<WindowType::TupleType>::dereference(r);
    

    SPL::rstring lhs_0;
    SPL::rstring rhs_0;


    {
        MY_BASE_OPERATOR::IPort0Type const & iport$0 = lhs;

        lhs_0 = iport$0.get_name();

    }

    {
        MY_BASE_OPERATOR::IPort0Type const & iport$0 = rhs;

        rhs_0 = iport$0.get_name();

    }


    if(lhs_0 < rhs_0) {
        return true;
    } else if(lhs_0 > rhs_0) {
        return false;
    }

    return true;
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::drain() 
{
    SPLAPPTRC(L_DEBUG, "drain", SPL_OPER_DBG);
    _window.drain();
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::checkpoint(Checkpoint & ckpt) 
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "checkpoint " << ckpt.getSequenceId(), SPL_OPER_DBG);
    _window.checkpoint(ckpt);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::reset(Checkpoint & ckpt)
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "reset " << ckpt.getSequenceId(), SPL_OPER_DBG);
    _window.reset(ckpt);
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::resetToInitialState()
{
    AutoMutex am(_mutex);

    SPLAPPTRC(L_DEBUG, "resetToInitialState", SPL_OPER_DBG);
    _window.resetToInitialState();
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("SortByName",&initer));
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
    addParameterValue ("sortBy");
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



