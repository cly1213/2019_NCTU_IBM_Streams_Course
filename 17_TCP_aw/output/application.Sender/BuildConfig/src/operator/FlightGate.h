// eJytUk1vgkAUzF79FcR4gKSBhdrUYnpA7UVrYiNNEy9kK1vc8rFkP2Kw8b8XECkWPTR297I77Myb9xieRroUJCIis_02x5ILGwAQw3xbo6rohshQbIzzdsvkSWu5App_1zAdsVZxiK9VPIl_1k5yzxz5s49cz7braY5Imfuajrq05Ezka_1Og2fqm25LL_1yDnvMyCd8caBU6hbfccA_0C5eLZthkXjCQBKDHzgEmSiFsLAGBsaIwN7EvLMraUhTxFa2yY9547Xnhoa_1hIIJDQBBctF42TlLJa_0gqjIAasnONXR8lXU_06aOSrE71FXphFW_10tS1fR1hBFTNW1Yej04LlZdTA_0w8HzMhaopj0o1owY4vEChjAQkaZGO8CXaR5R5iYxbvBq_1RPRxOkECn3FZ4T9E2y4HiDgnQbJAWUSRr9ZqN0d6xdh32sWCY6UyjId3XL7HRChNoTKWucy_0A0AfVC2AY2orZ_1X9MJrGZy7qS5FPeiaf1_1z9Mqd3LVuwZQz_0tgZPzUEQnDzPzX4DvChWA9


#ifndef SPL_OPER_INSTANCE_FLIGHTGATE_H_
#define SPL_OPER_INSTANCE_FLIGHTGATE_H_

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

#include "../type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h"
#include "../type/BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02.h"

#include <bitset>

#define MY_OPERATOR FlightGate$OP
#define MY_BASE_OPERATOR FlightGate_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uAQDkWA02 IPort0Type;
    typedef SPL::BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1 OPort0Type;
    
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
    SPL::uint32 lit$1;
    
    
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
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FLIGHTGATE_H_

