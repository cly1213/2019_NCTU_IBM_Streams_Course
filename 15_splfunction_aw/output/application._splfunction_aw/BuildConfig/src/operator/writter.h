// eJy1VF1rwjAUJa_1_0iiB7aEEaWxVGNgdu4GDo2HTba8naqpltkzWpIuJ_1X1LbUsXNbWL6cu_1l3OTcj1PBQyuVNKRyhfFdKiSLgA2a6uuAumWhSRp7krIYEc5D6pGt7ftUG9as_1j3IpwsqjoGiNJS0dH_0EivRdJsSr4uSKB_0g2eFgmw_1HcWdFL9ui1F8Pe82j0_0RaNSNznL_1Owd7_0Y9T6YTmqCNlClXjTB_0GmAcSJkQuMpyGL2gZhzINbaiwE0Y1GAAj91HLRkyVxw4gXI7riCh0UlLlkin0gCYhYHuru6x5SzpOTy2zJABJJsPusaVIdOoGHkF1nTQLqMGybsdmFWpmnCDKXPurSyvEpKEgg1Bp0GMa60XDn5oPdesA2zAXdDjmGaV_0ULm_0Pc7FO5VfbhDPScU_0ntbvYZGLZOZVgI9H_1cMM7Wtp8vuMD4tfiNcCUMOc7kMYiNHKjE4HpEyOuqehrwT7sPbzDWdxSMNatNDShRMw4KQaoKQKoItBxlOoW5bUPhNb8A9xuCAc


#ifndef SPL_OPER_INSTANCE_WRITTER_H_
#define SPL_OPER_INSTANCE_WRITTER_H_

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

#include "../function/application/addition.h"
#include "../function/application/division.h"
#include "../function/application/multiplication.h"
#include "../function/application/subtraction.h"
#include "../type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.h"


#define MY_OPERATOR writter$OP
#define MY_BASE_OPERATOR writter_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo IPort0Type;
    
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
    inline void submit(Tuple const & tuple, uint32_t port)
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
    
{
public:
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_WRITTER_H_

