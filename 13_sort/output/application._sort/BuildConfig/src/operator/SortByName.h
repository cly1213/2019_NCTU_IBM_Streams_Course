// eJylkD9PwzAQxXVfperQLrGdMGVrpQ6EBCElSDBVVmNaK45t2Q5p_0PQ4_1yiFARDyYp_1fe_1e7s1oEhgnquJJUxHGujAMC2B8CiyBArtMMbVnSmiyvwu7xNStyTLqq1fc8StJMJEWRmcKek_1RO7Ta3b88b_1RScFkOA4G6JIX9I45hLF4UAgE6qZoiVTRiiVpnKanpgiER76zujkjoKUknWu_1vKtvOXIcBYZ7g8_0lyu_1ccSB0fm9pLWbLWG3VkbZq0fYoCfFKPxr_1DAwfT0mBxUI_102PvHPI40H4AZ6AJjZeAnNKHTciUvdUkFNBy9C0TEFg_1oXYu0Rv_1Qmv1rUhfBDP72v5bz04ushfmgwiL3p26yTay5cu0b1au1X8g4Q_1sZ4




#ifndef SPL_OPER_INSTANCE_SORTBYNAME_H_
#define SPL_OPER_INSTANCE_SORTBYNAME_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Function/SPLCast.h>
#include <streams_boost/shared_ptr.hpp>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX.h"

#include <bitset>

#define MY_OPERATOR SortByName$OP
#define MY_BASE_OPERATOR SortByName_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX IPort0Type;
    typedef SPL::BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX OPort0Type;
    
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
 
class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public SPL::WindowEvent<SPL::BeJwrMSk2yUvMTS01ykwpNi3JLMlJTTMrTsxJLKoEAIzYApX* >,
                    public StateHandler
{
public:
    typedef int32_t PartitionByType; 
    typedef SPL::TumblingWindow<IPort0Type* > WindowType;
    typedef SPL::WindowEvent<IPort0Type* > WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 



    void beforeWindowFlushEvent(WindowEventType::WindowType & window, 
                                WindowEventType::PartitionType const & partition);



    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    bool compareTuples(WindowType::TupleType const & lhs, WindowType::TupleType const & rhs);
    struct TupleComparer
    {
        TupleComparer(MY_OPERATOR & oper) : _oper(oper) {}
        bool operator ()(WindowType::TupleType const & lhs, WindowType::TupleType const & rhs)
        {
            return _oper.compareTuples(lhs, rhs);
        }
        MY_OPERATOR & _oper;
    };

    WindowType _window;
    Mutex _mutex;
    Metric& _partitionCount;
}; 
 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_SORTBYNAME_H_

