// eJytVVtv2jAUll_17K6yqk5Kpyg0KNAwkWmlSgUxIsGfkBgMWSZzFzihD_1PcljgkXh61qSV6s43O_0fOc7l7A4MFJOAsI3rvucMk5DYAMre21waxgm38TYfML9deKNV86g0fQmfjIaTzw_08GJvQhx78Pz248_1z7_15wsGKcrOPx6q0_1RCs27v3svazro6eesbwFTcA44vjOjzgYj4aum5KI15yTsw0yGncN6ck24SsNWOEREMa_1iVPCeEKiBexevihw9l_0ME_0JjBWYeUJR9U4U5XNjAdYWJxcHUR3uHCtd7WHXTqMMu7LpuHqrljFq6pPQrRREnnKi0CiVUVqW9yO1RAvEEzXBeoo_1LZFvnWCSaER9xmvynULYtIxPM0kCW9ZOtch0Q6yowmm74AUaJpgPbERlbJyoUIoDjghc2R3Wrqaa6anpQTQ3V1LxcUnHfqmzpvBuBbJ5LzbVviH_1j2_1YpJ2AuaYhNPEsdx1zTZMVi5GPzsTX1aTQniylamzPEEYhohIvNYgES06QU9LP1DkEiVtb2BmZPuWhgBx4R1SqnubiTA1wKJYd2H_1I9jXxOaMRc10N8mSmCohkNNR1_0hUIRXYdfxMnS24IDmUNNuzRXsNMRzk4WJrzzZ1ueDjlUhYrIWrv03okTDhj_0GFT9HOp4po0F5tNiEWfJduDJZjYQ10qtZd5KsFx1m6Pww_1Z7F4LY30fhxT5_1V2iZ9FH4YWUeIFRxJOKMwi28RotCjsO45FBQbEOWvoaEQy2_1vBfVeNDbcAfXSxJgLe_0l3Q0AdVAIDuQcAqEAkH8fsFcYyHkskyn983mj1543hZV1xstSmFkV3KyM3F8TBKr_1


#ifndef SPL_OPER_INSTANCE_TICKER_H_
#define SPL_OPER_INSTANCE_TICKER_H_

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

#include "../type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.h"

#include <bitset>

#define MY_OPERATOR Ticker$OP
#define MY_BASE_OPERATOR Ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA IPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort0Type;
    
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
    SPL::float64 lit$1;
    SPL::uint32 lit$2;
    SPL::uint32 lit$3;
    SPL::uint32 lit$4;
    SPL::uint32 lit$5;
    SPL::uint32 lit$6;
    SPL::list<SPL::rstring > lit$7;
    SPL::list<SPL::float64 > lit$8;
    SPL::list<SPL::uint32 > lit$9;
    SPL::list<SPL::rstring > lit$10;
    SPL::uint32 lit$11;
    
    SPL::uint32 state$cnt;
    SPL::list<SPL::rstring > state$symbols;
    SPL::list<SPL::float32 > state$prices;
    SPL::list<SPL::uint32 > state$quantities;
    SPL::list<SPL::rstring > state$tradetypes;
    SPL::uint32 state$tradetypeindicator;
    SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA state$result;
    
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
#endif // SPL_OPER_INSTANCE_TICKER_H_

