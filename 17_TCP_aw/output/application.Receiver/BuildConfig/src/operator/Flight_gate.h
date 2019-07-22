// eJytkM1uwjAQhLWvgnpOnEBVmlv4aVVCADXhwiVyky2kCbFlr4nC09euhAT3ypfZ1SfPzGrZerziklBFUT7fZcKoEiEAZl8II8_1zaZDoz3DVqzRjYT418iedqqvTrKFy2ejM6mEogiRPiyBNroeV3ZgkP6xmEzGLF2YfvxaBdxo9_1DeozYcYJ2xCSaMpbS7bYX_1dJP0y3u769_1nG8cwmaWt6YpDt1lFk6o7GIQD4J3FGHysThn4vVKMlL9EPXgpboeC9X3Hi0IkOXQklWtcoE2WD9OkGBhrVBRXMjSZxXte2Pm9BCkUOvLO62cdEqv4yhG8K8S8WA_0H4W7R_1OBCcQcEzfLdD0RmrtbXsjtaoQrnghHcboepj3T0gmu7G4wPOfgFfkpb8



#ifndef SPL_OPER_INSTANCE_FLIGHT_GATE_H_
#define SPL_OPER_INSTANCE_FLIGHT_GATE_H_

#include <SPL/Toolkit/TCPServer.h>
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

#include "../type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h"
#include "../type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h"


#define MY_OPERATOR Flight_gate$OP
#define MY_BASE_OPERATOR Flight_gate_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::uint32 lit$0;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$role$0;
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
  
    virtual void process(uint32_t index);
    
    virtual void allPortsReady();
 
    virtual void prepareToShutdown();
    
private:
   int _fd;
   uint64_t _tupleNumber;
   
   
   Metric& _numInvalidTuples;
   Metric& _numReconnects;
   Metric& _numConnections;
   Metric& _numWireFormatHandshakesFailed;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FLIGHT_GATE_H_


