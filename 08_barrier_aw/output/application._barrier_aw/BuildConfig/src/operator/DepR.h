// eJylUdFqgzAU5f5JKXvQF422DBH6sHXuYa3dwL7sKaQ2rcGYSIyz8_0sXnXV0HYMxAoF7c8_0555xUJXcU5UQzKQgPw8dapFoq8ACZ48PUcVz9XlL3nj41Kk7m3va1fVkFnhcj_13mLVJxuY5REuWYR9uI2wd5m1UR3hUCrZeZk0yuGfGBAesMwKtnSXOso_0_0LbxVGQbdoAvbXJ8SEQzSzveJDRxJm_0QZC8rMNQVVoxcQQAN5MFdem_09n23kSqvSpJSFwV4R5RiVGHSuHuiCQgpaMdyYFzTzmJPtJOSUyJMabFSKrPAOVKN9Ql3qi17slhM_0r02RKdS0aoyUfX5DOOfNP9wBwxUHzfAHAgWdQE1E3rmwyACzmZT44nDgUuib_0fdKylkLfTY6VTJH1T97degMHpml0q8c1xDPbrvw_0pHLfubvhFzblyC_0mED2tPy2sevyNG4ZRvHH6LwNfy



#ifndef SPL_OPER_INSTANCE_DEPR_H_
#define SPL_OPER_INSTANCE_DEPR_H_

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

#include "../type/BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh.h"
#include "../type/BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k.h"

#include <bitset>

#define MY_OPERATOR DepR$OP
#define MY_BASE_OPERATOR DepR_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk1TYzPK80tNi_0piC_0pLEh1M02OT0rMcbME8hNz80vzSgD8nw3k IPort0Type;
    typedef SPL::BeJwrMS41TYzPK811M02OT0rMcTM0SEktiE_1MzS_1NKwEAmn0KCh OPort0Type;
    
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
#endif // SPL_OPER_INSTANCE_DEPR_H_

