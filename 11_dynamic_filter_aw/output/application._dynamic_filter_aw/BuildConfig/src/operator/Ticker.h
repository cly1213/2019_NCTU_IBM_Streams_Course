// eJytVVtv2jAUll_17K6yqk5KpSuJAoQsDiSJNGpcJCfaM3MQUi9xmO6MM8d_0XOCZcDFvVkrxYx_0d8_0c53LuFpaGWChlSsPa_0XcZFEAAEnfxG4tSxbrFNiP5H_0io0mS3fQaI6mPhtPpiMxGKWjKXXRoPf640_1vd384WHJBV_0lk_0dof4iWfdH92v6_1q46eutbgFTcAFFuTOjwWYjIeel9FY1NyjMwI5jbuG8uTr6DkJeekRUi6_0yhPjgtH4BXYuX5Q4uy_0mjPpEg5mHCc6_1qcPsLxDwPGniaTjz8c7hjOs9PHfTqMMO7HheEWoUjB5NRelXhmNBBdVplUrorCp7mdsXBSQYDkhRovfLhJxTLBoH1MciYf8pFEIqkhGehaqsH2yV64A4V4ExTMsPCWaGCZArM3aOVChFAIcFL22u7lbTTXXd9KCbGrqpebmk8v7xbEsX3QhU81xqrl1D_1BsfoWNOwF4kEbFJkLmuvUrYkqfYJzZCs2Ad44j6szkNBWEzvLIDLDCIk5iUG8YBNE1YJexH6x4BJlfX5gbmT7VwYBseEDbOTnV5pwa5EkwN7y7kWxb7giYx97wRFotcGRwHSWSY8DOUypgm_1CRPjtmSHOgcGsal_0YLttnR28zDpXTyb6rTP4VyojKy1Ku_0tPJGQk_1dB1U_0hDmfbeiFiVi7kPNk2PNrQFhZGpbXKWwtWK299EL7fgm9CkHv8ILzc628KrZI_0CN_0vzj2ELo5CDBK4gddoUShIlFYcSootyLPniApoFJf3shoPZgtu4WpBQ2IUvbS9AaAOSsGBmkcgFQDqLwR2CgM1l1UylX8xb8m1501j5ZzwcjRmzhluTk7uL4xWK5E


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

