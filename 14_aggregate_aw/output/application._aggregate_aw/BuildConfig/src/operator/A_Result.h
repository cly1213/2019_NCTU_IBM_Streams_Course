// eJytkV1vgjAYhfP_0FbMLveFLTBx36MwiEaIrXpsGOqzyUUtZgV8_10OHHXOKSLb1p3_0Sc9zynOYsVTmIsaJbi2LLsKOIkwoKADlpzDOgpiioqRtQJcSR3kWagwMwPSBr_02PyoUc4OVOredDdfVDsPodqp3TH3glj3Z2MhUCl9FHs_0LR1_1NbMFC9DEUba9O9_097rkjj9vffFZh9f429Nfmq1u_1SCmf7Xk1ZTee4_0Xat7XWU2tSx1Q8aYCWC8uiqRgaAKBus4SoJCwMQ5UZ3_0cMB0TVzQ3uaDdYqiEWGNIsJdrRRwPKMn72_0kd6oMDbFZouaNIUfZW1i386ACMIqKiA54LTNIIgK1LBL2_0WseL0d1CcDBI7It2dzcIiaODCbtBCZT9A_1bV6SBogExJcLu8C6S4um8XHdV_0jc7NKRMTmwtAftBbuFcFDcYvbymh6K6PpL2X3HT3SnhX9QdPnJ3oAARF




#ifndef SPL_OPER_INSTANCE_A_RESULT_H_
#define SPL_OPER_INSTANCE_A_RESULT_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h"
#include "../type/BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.h"

#include <bitset>

#define MY_OPERATOR A_Result$OP
#define MY_BASE_OPERATOR A_Result_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ IPort0Type;
    typedef SPL::BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0 OPort0Type;
    
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
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::int32 lit$0;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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


class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public SPL::WindowEvent<SPL::BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ >,
                    public StateHandler
{
public:
    typedef int32_t GroupByType; 
    
    
    
    typedef int32_t PartitionByType; 
    typedef SPL::TumblingWindow<IPort0Type > WindowType;
    typedef SPL::WindowEvent<IPort0Type > WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 



    void beforeWindowFlushEvent(WindowEventType::WindowType & window,
                                WindowEventType::PartitionType const & partition);



    struct Tumbling$A_Result;

    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void aggregatePartition(WindowEventType::WindowType & window, 
                            WindowEventType::PartitionType const & partition);

    WindowType _window;
    Mutex    _mutex;

    Metric& _partitionCount;
    
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_A_RESULT_H_

