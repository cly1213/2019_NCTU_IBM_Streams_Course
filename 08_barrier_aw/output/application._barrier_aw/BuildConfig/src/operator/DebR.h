// eJylUdFqgzAU5f5JKXuwLxptGSL0Yevcw1rdQF_12JNGmGoyJxDg7v37RtY6uYzBGIHBv7jn3nJOmZqYkDCsqOGae99jyTAkJNiB9HJibpqXea2Ldk6dOBtHKjl_17l61r2wFynmMkgywOUOSzkJaJHfRRYofbzr_0rcrTdxGYxv2IoTwxIhTRBNd3oa_0cXX3xp4LtF2LvorY_1yB5d3y3LgQVoTo_0oGQfSy8zzZKEl5DgBWISpikX3rOFYnZNnUOCMWcpMUS0mJTHBn7bHCwAUnA8uBMkUGiyNRKgQjmOvSoLWQeoGZE5WoYzKoNhaz9Xo27l2Af6wlaRod1ZjPafyT5h_1ugIIc4wZYAU54W0FLuVo6cBIBZ7OZ9sTgwARWt6vhFVei5WrqDKrED6r_09mtQaT3LSyX2Oa5TPbkfwxpHjcU3fRPm3LgEjcMatCfptY9fkZNxY6EdfwBOqtew



#ifndef SPL_OPER_INSTANCE_DEBR_H_
#define SPL_OPER_INSTANCE_DEBR_H_

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

#include "../type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.h"
#include "../type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.h"

#include <bitset>

#define MY_OPERATOR DebR$OP
#define MY_BASE_OPERATOR DebR_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k IPort0Type;
    typedef SPL::BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT OPort0Type;
    
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
    
    
    
    SPL::rstring lit$0;
    
    
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
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_DEBR_H_

