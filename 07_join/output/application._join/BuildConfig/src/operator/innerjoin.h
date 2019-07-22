// eJyVkt9PwjAQx9NX_1orG8LAFs19oTKqYABGMgsFMnpdlq1DH2ma9iQvhf3frYIzEB7k_09Hq96_0XzvSq5sXJgGwYFIeNcgUiRi5xyuejKsmwoJLVH9GWbzf3EK5bf8w_1fcf1lAq_1jxB3dPv_0kPp9MktF08bQaD9_1ep8Nia62vynIFIdBuxAH5ixkhjEPfa7suKrt2_0_0hG7077SkfcOpIpyBhf1THvj1j_1rBLZa5FSm8a559lbkSVKhhG1nbvgSzBuxyGEiAtOa0QHMSmypvuloIihTIu16_0DS2Cc2jAa718ODAdZspol1QmW7xquMEN14kvMImOCKkOVxGrJEBF_0DzrihFTHvm_0J956JywzikKrkJolDBQ1vIa3ySED8SUiWcQEzc0xhe5fzjmUtVbDoeZmGaJee_0g8qfwcOUouO0YyoB5fWcKz9gcesYnOU6v5wWNrp


#ifndef SPL_OPER_INSTANCE_INNERJOIN_H_
#define SPL_OPER_INSTANCE_INNERJOIN_H_

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

#include "../type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.h"


#define MY_OPERATOR innerjoin$OP
#define MY_BASE_OPERATOR innerjoin_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw IPort0Type;
    
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
    inline void submit(Tuple const & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::int32 lit$0;
    SPL::rstring lit$1;
    SPL::rstring lit$2;
    SPL::int32 lit$3;
    
    SPL::int32 state$cnt;
    
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_INNERJOIN_H_

