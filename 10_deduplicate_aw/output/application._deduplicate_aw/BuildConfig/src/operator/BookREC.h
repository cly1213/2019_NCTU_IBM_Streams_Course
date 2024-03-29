// eJy1U1FvmzAQll_17K6yqD7BEwZCklbx1Ulep0jaIWiV9jhziBRewqX0oYtP_0_0xyHoiTikcED3Hfc932_0O0xVTGoQhYCG0sfagCpRiIi9Q3Q9mQTQVDz4xn_1sdbIkUZzmpnnNYWFyszJKL3Jj4lR_0j5v3KH7MFo3Ff_0c7WL4l8DOpktXu9WF1N3t50JPs2jIaYMBvUglo_0RxTWgsJ0_0jsPUTWys0tunNPcsxpA1rIHXJY2INFPdi0B5sdsV_0FYgcxh83P9Fv5MwgFmSp5wLd1FAV7pXNTsZQHIVlvLVYVIrWnWrN9sGXAkFSSH_1tHkKiU7k4xQBdRibQbzp8rbK_1RqGvoZwe0evgeD6XoeW4OeIQpdZymKtYpM_1DltLtjfNIw_1JXSwxdeZ873x9jxhAPxRAPxTAfg6a1vN6ytd9HtrCNoS55qmYJQ0lCaMMisKpNbVXq_0jz9ht66_0f5yrqTelAOy18x277Nwm_114hNEcgoODoY9OF2cguYDVkSndhVW8KYTJ_0gmiRcvTxRxyWVv2Ppb00Sc5tkkujpMcquTBLrNt_1oU6CCo


#ifndef SPL_OPER_INSTANCE_BOOKREC_H_
#define SPL_OPER_INSTANCE_BOOKREC_H_

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

#define MY_OPERATOR BookREC$OP
#define MY_BASE_OPERATOR BookREC_Base
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
    
    
    
    SPL::rstring lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::float32 lit$4;
    SPL::uint32 lit$5;
    SPL::uint32 lit$6;
    
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
#endif // SPL_OPER_INSTANCE_BOOKREC_H_

