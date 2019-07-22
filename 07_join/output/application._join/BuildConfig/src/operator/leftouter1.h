// eJytUt9PwjAQTl_15KxbCwxYM6wYGU8VEjD6wkUAGifpC5qhQfrR1vYpI_0N_1dCgxMfNCE60PvrnfX_0747JRc1DWzBYE3IvVYglshDODseKtdqLqwlddu0s0q7EfbW85WE_0USHUbPzhTEEs5dOFH12wsHzR9CVvWCIdfA6FOFDvRtczdV7v383SBr99lNtWs4qKoiBVhIOKOqFhDAOdf9U9VDWSKWOGubGp0_1G4_008qYKU8cnO5_1_1iq_1_1IRO5ULKlLx9r33ZVI50rGCXVxczQTjLvjGGLEBac71BgxKdLi9zNgRwylhtJNycqEvVm2XTBRrVqtlmXgOo5lAnLZFFouhJheHjVPgAmuCBkeZiYz1BAZ7CG3DUnOdZG8Lf0r3bb3oUouRkms4OaU2wvryKp1S0gecATiWFUDw8_0VP5Q5A7FFE_1uJOU4GfVtC6BKxMdK78SdmqWmKDhuSzZsWhkzFWCdQ2O865pAxc8jG3yXWPVW


#ifndef SPL_OPER_INSTANCE_LEFTOUTER1_H_
#define SPL_OPER_INSTANCE_LEFTOUTER1_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
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

#include "../type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h"


#define MY_OPERATOR leftouter1$OP
#define MY_BASE_OPERATOR leftouter1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX IPort0Type;
    
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
    
    
    
    SPL::int32 lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::int32 lit$3;
    
    SPL::int32 state$cnt;
    
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_LEFTOUTER1_H_

