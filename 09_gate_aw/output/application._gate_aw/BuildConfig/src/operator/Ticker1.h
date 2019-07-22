// eJytU11v2jAUlV_15FVbVh0RU5ANKNbNOSpkmFUiHlvCM3MQFKx_12YqcpRfz3OSYgWNj6sNkPsU7OvT73nmvB014paUrlBqFxKSTLgANstV1w1etZcsOJ9UAmVeEHiTsd3vlhVMyD0JdTn_1shdZ3p_0O3pffw6mU0TIWnFg_0Rt8hUnIvAW3iMbzL1Vb33VylU54eL9e5jYD563dFzv6bFmuUBILMm1LHlKxA8SEfpKYhDMZwiVNJd99_0zsAKX7_0rYJinL5AXMI7vTXPvunIacNNRkKIQuar_1ZYf4_19sYg9a9BOdtuGhucQsNYsIxaJS9e1KlYkguOIWPan5UpVt8SVFWOJQc5yUttTm0Q5K47V_1KNJIAOF9n3bgWrRF2gY3e4lO_0D9PdRdNE2oufXaHk_11uhymo5zRGRMhLf5bmUeSslwgtDhMI1dtl4Fu_1iw3jIYpeLqMsJCfT825gSethF8QqhlH_0WowTNjVt7umeX5_1zOAW_1t1TKEnGG_1X9ERTlc0YlNGr0RoMDcwR3sFrTlBj2Sf5dZ9cBYADEJntmKTgMkqorIuAlZbj2_1WeJc6nqBc0cyALHJFQv5ch3lSnsfzvdUmX_1pstuKbMvaLMdPYp7ec5Hj6O_02AE4StSbPiRVCX4BEb5aBh


#ifndef SPL_OPER_INSTANCE_TICKER1_H_
#define SPL_OPER_INSTANCE_TICKER1_H_

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

#include "../type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.h"
#include "../type/BeJwrMSw1TUzOTk0BAA_12ANI.h"

#include <bitset>
#include <vector>

#define MY_OPERATOR Ticker1$OP
#define MY_BASE_OPERATOR Ticker1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg IPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg OPort0Type;
    typedef SPL::BeJwrMSw1TUzOTk0BAA_12ANI OPort1Type;
    
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
    SPL::rstring lit$2;
    SPL::BeJwrMSw1TUzOTk0BAA_12ANI lit$3;
    SPL::uint32 lit$4;
    SPL::uint32 lit$5;
    SPL::uint32 lit$6;
    
    SPL::uint32 state$tuplesReceived;
    SPL::uint32 state$cnt;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    std::vector<OPortBitsetType> $oportBitset;
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
#endif // SPL_OPER_INSTANCE_TICKER1_H_

