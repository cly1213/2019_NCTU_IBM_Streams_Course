// eJyFk11vgjAUhnP_0iTG7cFkCLeDHuHPLTGbmsoTFW9PBmTZCadqibr9_0THAq1hFu6JOH90BfqmXqsIRJgyoMZ2gUj3XExRookPKi0HUc13xJdB9wulWzz2fyHgeb72ize52tdRSTyfgxn47nA2fVLR_04h5SbGwLR20sYKl3miSXsGbUwz8J8CwssrG9hg4pxYQZBRYYXZHRGwF3lGbqYFJ7nbnO11pLF6BJ_1kVWb4SbMMBC5QAIB1BD80xACXOaq_1GpniWYR54UwvVt42kmFWvNcXHe5wewf9bjoWSZ07jqXWWdhgmX4966HjaJ1Q2NTrj8KgxOFaFNou_0I1lAR1rLg05fArc_1320KBd6TcULrjhLJ2ztMBGObT_0MSyZp8KwTRg1BHqsspLbzgdwUPszBeDBvkKo8n_0Lq2_1JD831Bq1




#ifndef SPL_OPER_INSTANCE_METRICSSINK_1_H_
#define SPL_OPER_INSTANCE_METRICSSINK_1_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.h"


#define MY_OPERATOR MetricsSink_1$OP
#define MY_BASE_OPERATOR MetricsSink_1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6 IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Tuple const & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::rstring lit$4;
    SPL::rstring lit$5;
    SPL::int64 lit$6;
    SPL::int64 lit$7;
    SPL::int64 lit$8;
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR
{
  public:
    MY_OPERATOR();

    void process(Tuple const & tuple, uint32_t port);


 
  private:
    Mutex _mutex;
    Metric* _metrics[3];
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_METRICSSINK_1_H_

