// eJyVkl1rwjAUhjm3_1oogXrRM7KdexG0wBS_0clYHzWjKNGq1JSVKljv331bRWZTIwhTR5c77ynKgkbqWaxUxnGPdTpcUOPHDzz4N6q_0XoLKFOjw4PMpps_1Wy6jz7nrpttj8NxP34_1RiodK298jMT_0bdXzg1W8aa3r4IPSRNNGMiMSJh8jjL_0EiCnhtxsP8ryNsDSmsrRlXAf_09bKwa0PH_1N3bIEbzCk0qLRlfFVoZIs1jdMJCCu64hne09nV2AGctdtShi9T3nYOQW5WQOXXczixJ_0VwL6SyIJsAFpwU4F1giZFXpQ_1iAgTT82RJZF4o2qqF8fJv5NC5H6AUZLN3qDGOTd3CqjgmuMJ6eW5zkfPTEUBpxyzLs0NPZQyXxbE6Ufr6m2USP3wK9YnwKZJUgbNv_0r7wBiynGy2WcqrWpyW_0i6lGUnj81_0HPnoFuDEDjZUTi3ni2gaJskfFsud2QjZGXh_1gKjoOYr


#ifndef SPL_OPER_INSTANCE_CUSTOM_4_H_
#define SPL_OPER_INSTANCE_CUSTOM_4_H_

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

#include "../type/BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj.h"


#define MY_OPERATOR Custom_4$OP
#define MY_BASE_OPERATOR Custom_4_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj IPort0Type;
    
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
    
    
    
    SPL::boolean lit$0;
    SPL::rstring lit$1;
    SPL::uint64 lit$2;
    SPL::boolean lit$3;
    SPL::boolean lit$4;
    SPL::int32 lit$5;
    
    SPL::boolean state$p_ar;
    SPL::int32 state$err;
    
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
#endif // SPL_OPER_INSTANCE_CUSTOM_4_H_

