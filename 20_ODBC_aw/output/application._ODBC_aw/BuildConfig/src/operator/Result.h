// eJzFlFtzojAUxyev_1RRMpw_16ws1LWzt9QOxFUHuhjq4vTBayygiEJmFdttPvvgEVAe3WnZ2dDQ_0Ew_09_1TpL_1ARr5IkE_0ZB4Ood_1p3MahwzABCpD5pYJTUZRYEiGpi4wVGTpUvkwuTctqJC_16Uh3d9_0OBdW78lGV2sfw_0fHFkedTv_1niamnfaeNoy4dQwJlpkJfN78_04Gjg1rFmpYe2VN2MXi4rSSnzrzv87fu32mN1HyPJnpXwPfsTjxZezj4UhbLceGPvNtuW1NjL6pDZq2rEOYLkMFlEGGzmy68KIIucB6HHQ6XsgaanGqAN9jZ60i7PLZGiGUES_0clx_1WijY4z_05yMVkWUfYiajlBFmvsUc0DVGuPalcoIC1wgCTkxqoqrTBZ0gg6SFJl_06HX1W24kvh2IAhxiFL70ybwIkzyhf_0DJgAeIFmvvZ0IfHjfhFqt7IVwfS1kh1evCxmTjrd8lo6qIOOVq4_0Y1LMNpO6g92yGfIr_0pErjmCrNYpX3EwDa4IG4iPRdsHZLjynjzpARDBDY2rUN5tQjwW7ssBK0iRUYz9m9TR3Eew7_0l88MBNzoi8q_0FVD6APJ2E_0eI2Ru0Vj98PLl2Gyiri5pCiuNK72guPXTsnxQvSHYJjiudw5mwbOYnNTnMRRbvvQCFzOKtGNOPSlb_1d_0md5_0ylv7PfFKz0N_0_0vX1oqOPV



#ifndef SPL_OPER_INSTANCE_RESULT_H_
#define SPL_OPER_INSTANCE_RESULT_H_

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

#include "../type/BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo.h"
#include "../type/BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa.h"

#include <bitset>

#define MY_OPERATOR Result$OP
#define MY_BASE_OPERATOR Result_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMcs09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZnAoAqt4aBo IPort0Type;
    typedef SPL::BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa OPort0Type;
    
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
    SPL::int32 lit$1;
    SPL::rstring lit$2;
    SPL::int32 lit$3;
    SPL::rstring lit$4;
    SPL::int32 lit$5;
    SPL::rstring lit$6;
    
    SPL::int32 state$_shipped;
    SPL::rstring state$_shipdate;
    
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_RESULT_H_

