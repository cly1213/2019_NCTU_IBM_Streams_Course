// eJzt0k1vgkAQBuDMXzE96IUvv7mhaZOqNCbYs0FcdQOy22Up0l_1fFRcSbNN00x43HMiSeYeZBzKaGDnHCeal6wZU3MEGS1w2dAzD5CVF5gwtCuYHsbMcjf1NxNbBxudLn_1ob7NjL_0eXlY_16_0WC3jjOOCBvFlsQrjLPBevedisJ55xqlT9RO9HywI1ivXZRlnOD0CgHkiZ2Sife44ZkFYnNEwQuZ0so1IesDHbViY_05CHkJIUWeDAASdI9Gp1qVt7XJx3OUdPDCGIUXlfaAGmhIlS44j4NivPO5J0e_1B4oQxlGSZptbusuUX_1uDtgYBUnwABuL4R6GspwhOCQkJD3HXjLw5SLrwA5Tq9nzsI9uvI39fa1D_1nv4b6MZf9SrT1_0k6oftFNVsQjdb9nE5LmdqqtF8BuOn_0dsAt2eXf1_0NzlbyynKOVLO0XKKcn0p19dyinIDKTfQcopyQyk31HKKciMpN9JyinJjKTfWcopyEyk30XKKclMpN9VyanKfzttlAp



#ifndef SPL_OPER_INSTANCE_GM_TICKER_H_
#define SPL_OPER_INSTANCE_GM_TICKER_H_

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
#include <vector>

#define MY_OPERATOR GM_Ticker$OP
#define MY_BASE_OPERATOR GM_Ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA IPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort1Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort2Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort3Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort4Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort5Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort6Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort7Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort8Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort9Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple const & tuple, uint32_t port)
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
    std::vector<OPortBitsetType> $oportBitset;
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
    MY_OPERATOR();

    virtual void process(Tuple const & tuple, uint32_t port);
    virtual void process(Punctuation const & punct, uint32_t port);

private:
    typedef std::tr1::unordered_map<SPL::rstring, std::vector<int64_t> > MapType;
    MapType _Map;
    std::vector<int64_t> _Default;
    bool _hasDefault;
    std::string _fileName;

}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_GM_TICKER_H_

