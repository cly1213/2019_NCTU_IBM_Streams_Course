// eJylkUFPwzAMheW_1MnFuklIN0Vu3CYl2RZNazlPWmS1ql4TEpSu_1nlAm0HZFvj3Z73u2ve2inlSnaEzTBcrGaBDAQwmYRRGj0SJbYD64smrjYv5Q1o3bVHVJRWnLWsWiWJ5fPpcf_0bpoPanBVu05X8nWV9lr9mySTXaIjrPgF0OA3HGoNus07ZWm_0xgmSfxIb52RNE8AgB3NCRnu_0zhmg3Gtt7JBxh_03B0m4lQPbS5KgjcZvV0XoJCmjPYgrc3EBZkRO7XrCJ4cISitaYSdHuOGKS5jrdj5dw1jjfrP_18xqgwEECfjztTAfOB5o_0BIZ1qkGY0oTwHN57qSm8BS7rcCAn91iHh_1xN8S9sBYvM

#include <SPL/Runtime/Utility/Mutex.h>

#ifndef SPL_OPER_INSTANCE_TICKER_T_H_
#define SPL_OPER_INSTANCE_TICKER_T_H_

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

#include "../type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.h"


#define MY_OPERATOR Ticker_T$OP
#define MY_BASE_OPERATOR Ticker_T_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg OPort0Type;
    
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
    
    
    
    SPL::uint32 lit$0;
    SPL::float64 lit$1;
    
    
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
   SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg _tuple;
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
#endif // SPL_OPER_INSTANCE_TICKER_T_H_


