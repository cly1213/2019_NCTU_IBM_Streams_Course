// eJyFk11vgjAUhnP_0iTG7cFkCLeDHuHPLTGbmsoTFW9PBmTZCadqibr9_0THAq1hFu6JOH90BfqmXqsIRJgyoMZ2gUj3XExRookPKi0HUc13xJdB9wulWzz2fyHgeb72ize52tdRSTyfgxn47nA2fVLR_04h5SbGwLR20sYKl3miSXsGbUwz8J8CwssrG9hg4pxYQZBRYYXZHRGwF3lGbqYFJ7nbnO11pLF6BJ_1kVWb4SbMMBC5QAIB1BD80xACXOaq_1GpniWYR54UwvVt42kmFWvNcXHe5wewf9bjoWSZ07jqXWWdhgmX4966HjaJ1Q2NTrj8KgxOFaFNou_0I1lAR1rLg05fArc_1320KBd6TcULrjhLJ2ztMBGObT_0MSyZp8KwTRg1BHqsspLbzgdwUPszBeDBvkKo8n_0Lq2_1JD831Bq1




#include "./MetricsSink_1.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>


#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR MetricsSink_1_Base
#define MY_OPERATOR MetricsSink_1$OP


#include<SPL/Runtime/Operator/OperatorMetrics.h>


MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR() : MY_BASE_OPERATOR()
{
    SPLAPPTRC(L_DEBUG, "MetricsSink startup...", SPL_OPER_DBG);

    // Initialize all the metrics
    OperatorMetrics& om = getContext().getMetrics();
    
        _metrics[0] = &om.createCustomMetric(lit$0, lit$3, Metric::Gauge);
        
            _metrics[0]->setValueNoLock(lit$6);
        
        _metrics[1] = &om.createCustomMetric(lit$1, lit$4, Metric::Gauge);
        
            _metrics[1]->setValueNoLock(lit$7);
        
        _metrics[2] = &om.createCustomMetric(lit$2, lit$5, Metric::Gauge);
        
            _metrics[2]->setValueNoLock(lit$8);
        
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{

    AutoPortMutex am(_mutex, *this);


    // Update the metrics
    
        _metrics[0]->setValue(SPL::port_cast<IPort0Type>(tuple).get_count());
    
        _metrics[1]->setValue(SPL::port_cast<IPort0Type>(tuple).get_item());
    
        _metrics[2]->setValue(SPL::int64(SPL::port_cast<IPort0Type>(tuple).get_count() + SPL::port_cast<IPort0Type>(tuple).get_item()));
    
}



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("MetricsSink_1",&initer));
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
    addParameterValue ("metrics");
    addParameterValue ("metrics");
    addParameterValue ("metrics");
    addParameterValue ("names", SPL::ConstValueHandle(lit$0));
    addParameterValue ("names", SPL::ConstValueHandle(lit$1));
    addParameterValue ("names", SPL::ConstValueHandle(lit$2));
    addParameterValue ("descriptions", SPL::ConstValueHandle(lit$3));
    addParameterValue ("descriptions", SPL::ConstValueHandle(lit$4));
    addParameterValue ("descriptions", SPL::ConstValueHandle(lit$5));
    addParameterValue ("initialValues", SPL::ConstValueHandle(lit$6));
    addParameterValue ("initialValues", SPL::ConstValueHandle(lit$7));
    addParameterValue ("initialValues", SPL::ConstValueHandle(lit$8));
    (void) getParameters(); // ensure thread safety by initializing here
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
        process(punct, port);
        break;
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


