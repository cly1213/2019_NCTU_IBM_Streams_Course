// eJylkU1PwzAMhuW_1Mu2wXZqk5dTbJu1AaRFSiwSnKaJhi5omUZLRlV9P_0jUok0AI_0ZI4r18_1dqwWgWGCOq4kFXGcK_0OAAPZBYBEEyLWaoS1LGpPlVdg_0vmVFjklbNfqeR0maiaQoMlPYc5Leqd3m9v15o5_0C46I3ENwtMeQPaRxz6aIQANBR1Qyx8hSGqFGmspq_0MESivfWdUUkdBakk66q7zLb1h97AWGe4PHhfrv3DEgcH5vaOO8FWa9idtWHW_0il6_0lEyVP6VHjiYDh8Tx2sG5Av_1NNIQADcgqZdMbLyE0yDsuS55SwU1LbwKRQcXDOpfhLUn_1Nab_1LyoTuv39El40Y_13uZyXXjwf4pcG009czTpWTYl51aBerf1KPgAtZMZ_1




#ifndef SPL_OPER_INSTANCE_SORTBYTITLE_H_
#define SPL_OPER_INSTANCE_SORTBYTITLE_H_

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

#define MY_OPERATOR SortByTitle$OP
#define MY_BASE_OPERATOR SortByTitle_Base
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
#endif // SPL_OPER_INSTANCE_SORTBYTITLE_H_

