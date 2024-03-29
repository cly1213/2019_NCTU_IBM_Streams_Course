// eJyVkV1PgzAUhnP_0yuKF3kApH4vcAZvEKYmR3RPCGugGlJQSwn697ZhoJkpML5q_0fXpO_07RtSo2TMhWU1Wnpuk9dnQnGwQAkB4aVpuliaIjuk13Po4yhc9Sjs_1fsbfw_0CDqtWN0wbdaPTMDwS2w1UR7v36tNHG6HNN_0W_0yg8hbsW_0QPPY69Q5xGsoaTiDkH89uq6vBWc1jlcMmMmwzOZOZNZM5k9kzk3GegFq4hODh3Ges_14qW3SjOjISjJWNbQkiaBy_15CKFGpWE2VK_0aIN49MrfvEFFPhFLUi5FGgtTAzH66yKsB9F_1icUKtngcSptwNXguJwuqeVEJPT_04VvvP8CjBKUdAz4dTfRXMP6gXOIlylCUuURhRVlLlKkoe4myFOUsUbai1kuUI3_1pA_1IePO0



#ifndef SPL_OPER_INSTANCE_FUNCTOR_STREAM_H_
#define SPL_OPER_INSTANCE_FUNCTOR_STREAM_H_

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

#include "../type/BeJwrMco0zMw0zAIADBwCCu.h"
#include "../type/BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh.h"

#include <bitset>

#define MY_OPERATOR Functor_stream$OP
#define MY_BASE_OPERATOR Functor_stream_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMco0zMw0zAIADBwCCu IPort0Type;
    typedef SPL::BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh OPort0Type;
    
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
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::rstring lit$4;
    SPL::rstring lit$5;
    SPL::rstring lit$6;
    
    
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


class MY_OPERATOR : public MY_BASE_OPERATOR
{
public:
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FUNCTOR_STREAM_H_

