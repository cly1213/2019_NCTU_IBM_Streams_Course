// eJy1kV1PwjAUhnNu_0RULwWQLZusGxmSGC_0RK3YgGuCZjFFb30dmehUzif7cUsjDQOz296DlvP87Tt7LM7ApZxrD2_1UklkefgAlHDha5tO1iX1HmkzzsRzogXxKmsFylOZSrnkotpKmUQF09B_1eEFk2RaK_10z3eLsPcSXsAzn28V4fj98Gws76aobJUZIe3GBMHsNfL9iBQ68Vu6CQukN4U7PpLWmJfda8q6lwbU0bEvgJDynDl1XnufsuEhlGcXUcclyrbQyY7FCXUY7Zx1hBAUv6NEUAqzkokH7A2sgB6Ed33cMFbJa5QwN89Tm1tBGWA96kW0M0zx7h9nvN54aN3qrZxmjkc5cyzL0qUPsm_0zXJoNTk0N8db46oH4BGWYUhETBii0wuSqaIqow4aIpy2qVMZnQM0WwmMIm49HxZwnw_17DuEpK0McklKPkBlVzAEkX7DTY4PQl


#ifndef SPL_OPER_INSTANCE_DBOOKREC_H_
#define SPL_OPER_INSTANCE_DBOOKREC_H_

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

#include "../type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.h"

#include <bitset>

#define MY_OPERATOR DBookREC$OP
#define MY_BASE_OPERATOR DBookREC_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr IPort0Type;
    typedef SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
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
    
    
    
    SPL::uint32 lit$0;
    SPL::uint32 lit$1;
    SPL::uint32 lit$2;
    SPL::uint32 lit$3;
    SPL::uint32 lit$4;
    
    SPL::uint32 state$cnt;
    
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_DBOOKREC_H_

