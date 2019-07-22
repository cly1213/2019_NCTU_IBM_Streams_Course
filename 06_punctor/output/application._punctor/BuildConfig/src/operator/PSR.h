// eJydUtFugjAUzf0TY_1YgL1Bg2SKJS9TsYSqExJnszVTpsAItaYsO48evgLqp0WSDF_065p5xz76nMU1OQFCvKGU49LyzYUnEBNiD9OtA2TUuVObEGZLQV_1jRxytnGf18iVCa7UTBMxztfFoG0g53PN_1144LhxujZX7bOTpQjeuDtFeVCW3XEws_10xSlQ_17m_078cdzxUbwCClVDwim4cTzKFOuAzViXyHOFeKeIWCteEYsEhWOY225SGSOl8RCT_1O8mc6KsMLAOCPViDVYYEXgILXgPCWY6bKjH5pzoX2ZMVFzGnWMVq_1XqjWN1n7futl2jPt9_01b_1pW4jw4DXr1wQKXUykHNJq4i0p_1BgV1fhEUWwIJ9cEBgWUvFsQhUROK1DPPy_1mexPIQIFUd8C0NkwnBEQUgnKYqARNKsWmCWHzwyv9bU5Mipl_1n_1lTCtfaNrHdI7AabR6dRW3Y_1w4O9Gb8pxc7fm397vkiqfpl_1PddVOTO4bewjdB1geD



#ifndef SPL_OPER_INSTANCE_PSR_H_
#define SPL_OPER_INSTANCE_PSR_H_

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
#include "../type/BeJyrNIo3S0pNyy9KNU1MK0ktAgAw9gX7.h"

#include <bitset>

#define MY_OPERATOR PSR$OP
#define MY_BASE_OPERATOR PSR_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj IPort0Type;
    typedef SPL::BeJwrMSk2yUvMTc00ykzJNClKzMsuNs1NzMovAgB23glj OPort0Type;
    
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
    SPL::int32 lit$2;
    SPL::int32 lit$3;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    SPL::rstring param$position$0;
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
   
private:
   Mutex _mutex;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_PSR_H_

