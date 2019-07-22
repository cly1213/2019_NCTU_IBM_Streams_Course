// eJyFUGFrwjAQ5f5JET_1YOZq0ih_1CGNSBoKxj4NhXydITg21SkqvO_1frVWrcyNkY_0JHnv3d1756siqkkXmk5CzFEqayAG3pwYBlHE6FQhm_0Pq6LLtkr_0o6eFjfXh_1yvZ_0rfgifbCr9HUW7QaN3JMkHBpYPz8KoQ3Npv1nDM2MYQKT9uYXaltYeSZbLP4FS_1otANjOlsgwr5OEHa3b_00oqZHyyKZGcVp7lkiQYa_1Dsv0KnbQ4_1_0sadgZSakreacOEQ27wcbGXdl7n_1UoMGBwkoWxuCLmTql_1468ALx617GY9CE5d_1KGIRov74qNkp6uvsmb4N_0huBeiLNgNOoqFrVRpK3xQmSSdkI4aXJbjsLgJmhXG4b8E_0e_1I_13

#include <SPL/Runtime/Utility/Mutex.h>

#ifndef SPL_OPER_INSTANCE_BEAT_H_
#define SPL_OPER_INSTANCE_BEAT_H_

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

#include "../type/BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6.h"


#define MY_OPERATOR Beat$OP
#define MY_BASE_OPERATOR Beat_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6 OPort0Type;
    
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
    SPL::float64 lit$1;
    SPL::int64 lit$2;
    
    SPL::int64 state$n;
    
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
   SPL::BeJwrMfI0Tc4vzSvxNMksSc0FACoJAV6 _tuple;
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
#endif // SPL_OPER_INSTANCE_BEAT_H_


