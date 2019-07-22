// eJylkEFvgkAQhTN_1xfQMy2pSw42ibSqittA06YVsYap0kSW7sxL89V2amOq5mcvMy8u8b8Z0jScq0RHqMMzjXaasLhECYK44TDzPp6FD_1wFXvU4zyfO57b7TuT5njOdMUrmUJnP9MBRBkqdFkCbnj5VTbPSykO8R495hcrNn0JtnNU3YjBJpKJWn7fB23iT9Mtru_0qd4M_1qZI2hqumOQ7dZhaOuWphwA_1IM6oo_0V5dzvlZamEyX6wX3h0AvR_05UgAa1qcYTXqhkvyVQpkV7HgYFBfUINsTWkjuvanS0a6JSm0XgVdYmPiHT9aQkfNeIvFgM1_0i9o_13gMHEHDDL6aoWit642LavcuoMJuIQivFKXrfd3eWAz9jewHE8eNCE



#ifndef SPL_OPER_INSTANCE_FLIGHT_H_
#define SPL_OPER_INSTANCE_FLIGHT_H_

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

#include "../type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.h"
#include "../type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h"


#define MY_OPERATOR Flight$OP
#define MY_BASE_OPERATOR Flight_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02 OPort0Type;
    
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
#endif // SPL_OPER_INSTANCE_FLIGHT_H_


