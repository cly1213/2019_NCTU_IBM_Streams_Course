// eJytkUtvwjAQhLV_1BfUcPyhUyi28DglBSEa9ViZsi5Vgu86mEH59DUUV3JEPlkb2fLOzrW_0SjkxjqE_1TCerKWRDA4xEwSBJGvUc2wfwYSsVlMX4rN1VYq01JRenLjZGimJ5W5_0lPvizqlszRq_1qUL3XdqqmUah5vNczPc77IVjMxKUfJfhDNJUTiCwe1XqbpZ_0M0jV_1hqok_1rTOWhhIA2N4dkOGuk5IdXahbrytkUnzk2XvGdpo0WGfxYmmsoRk2ugfxaCxutIwomG1HuAiIYAiDJuNsC49QcQvy_0Jxfe3Hehf_1gz_0wFDAQYQdsftq6B0Ea0_1YpAH0yFcJ0kRuPw3WlLcVtwC8uBgt7hZU93v2IvSOZwJ_1FfDnyXBY

#include <SPL/Runtime/Utility/Mutex.h>

#ifndef SPL_OPER_INSTANCE_C_TICKER_H_
#define SPL_OPER_INSTANCE_C_TICKER_H_

#include <SPL/Runtime/Operator/State/StateHandler.h>
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

#include "../type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.h"


#define MY_OPERATOR C_ticker$OP
#define MY_BASE_OPERATOR C_ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple const & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::float64 lit$0;
    SPL::uint32 lit$1;
    
    
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
  , public StateHandler
{
public:
   MY_OPERATOR();
  
   void allPortsReady();
   void process(uint32_t index);
   virtual void getCheckpoint(NetworkByteBuffer & opstate);
   virtual void restoreCheckpoint(NetworkByteBuffer & opstate);

   virtual void checkpoint(Checkpoint & ckpt);
   virtual void reset(Checkpoint & ckpt);
   virtual void resetToInitialState();

private:
   SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 _tuple;
   SPL::uint32 _iters;
   Mutex _mutex;
   uint64_t _iterationCount;
   uint64_t IterationCount() const { return _iterationCount;}

   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_C_TICKER_H_


