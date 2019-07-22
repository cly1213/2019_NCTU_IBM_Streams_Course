// eJyNU1FvsjAUzf0ny_1I96AtQdPmMyR7AwTaHRoNmj6TTBjugJaV_0CL9_0RdAM1O0LTz3tufeccy9ZGmuCxFhSznA8Hk85ZYDAUN8Q7jVNl0VKdJtMczHzI7NY_15utfAP560i_0TSJkP7wcEp_05bmQ_1L5xwYs2Xz1aRa7v7CzJHK0ORXtliNUlM68mjo8O0XOfu_0zAPl1cZ7XaWY02jtWu73beFmL9Gg3JTen5hFKU_1kr5vFqUTz98C5Lxky3xOP73VrLAzy_0If1sNTVaEyGFP5xwB_14Y3HlMmBCUcEXSDmBTJoIaDveEJ0st2bpp5zEWUp3hDd_0Bt8qjz1LZYYGGfEABMSLDc7aHp8cB4TzJSYHk25UGq0kMhgS1LZ6989Pt7VKDqjAd32_0n1wDqkgWaaGBjgOuaByl6ia1fSsOFTlKGNEwGSfSZ54VBKBY9Vb4XWXuvsvOQMFoSjIQBu_0ZxLQN8uoyU5d37qstwhUW4YTAiKTgrIQKhewPz1s_1LX1_1Lgpv6syf1I1OKtq4jxpUcegJbTSz6_1E9d9_1ASRK6RA6RRuvJ_0A8kuOIq7e9fiejhtGc24R6U7pebnE6e3TN8w15Z2Yj8ZjxF7wTETP



#if 0
// This is needed to support hash join with shared_ptr tuples.
// TODO put this somewhere more appropriate
#include <tr1/functional>
#include <streams_boost/shared_ptr.hpp>

namespace std { namespace tr1 {
template<class T>
class hash<streams_boost::shared_ptr<T> > {
public:
    size_t operator()(const streams_boost::shared_ptr<T>& key) const {
        return hash<void*>()(key.get());
    }
};
}}
#endif


#ifndef SPL_OPER_INSTANCE_INNERJOIN1_H_
#define SPL_OPER_INSTANCE_INNERJOIN1_H_

#include <SPL/Runtime/Common/Metric.h>
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

#include "../type/BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw.h"
#include "../type/BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ.h"
#include "../type/BeJwrMSo2yUvMTS01SUktKAEAJkUFBF.h"
#include "../type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h"

#include <bitset>

#define MY_OPERATOR InnerJoin1$OP
#define MY_BASE_OPERATOR InnerJoin1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2yUvMTS01SUktKAEAJkUFBF IPort0Type;
    typedef SPL::BeJwrMSo1T0ktKInPTCm2ADLi8xJzUwFW4wgQ IPort1Type;
    typedef SPL::BeJwrMSk2yUvMTS01SUktKCk1B5HxmSnFFkBGPEgCANQGAyw OPort0Type;
    
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
    typedef std::bitset<3> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    SPL::rstring param$algorithm$0;
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
                    public StateHandler
{
public:
    typedef int32_t PartitionByLHSType; 
    typedef SPL::SlidingWindow<IPort0Type* > WindowLHSType;
    typedef SPL::WindowEvent<IPort0Type* > WindowEventLHSType;
    typedef WindowLHSType::TupleType WindowLHSTupleType;

    class WindowLHSHandler : public WindowEventLHSType {
    public:
      WindowLHSHandler(MY_OPERATOR & op) : op_(op) {}
      void beforeTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                     PartitionType const & partition)
        { op_.evictLHS (tuple);}
      void afterTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                    PartitionType const & partition) 
        { SPL::Allocator<TupleType>::deallocate(tuple); }
      

    private:
      MY_OPERATOR & op_;
      static const uint32_t portNumber_ = 0;
    };

    typedef int32_t PartitionByRHSType; 
    typedef SPL::SlidingWindow<IPort1Type* > WindowRHSType;
    typedef SPL::WindowEvent<IPort1Type* > WindowEventRHSType;
    typedef WindowRHSType::TupleType WindowRHSTupleType;

    class WindowRHSHandler : public WindowEventRHSType {
    public:
      WindowRHSHandler(MY_OPERATOR & op) : op_(op) {}
      void beforeTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                     PartitionType const & partition)
        { op_.evictRHS (tuple);}
      void afterTupleEvictionEvent (WindowType & window, TupleType & tuple,
                                    PartitionType const & partition) 
        { SPL::Allocator<TupleType>::deallocate(tuple); }
      

    private:
      MY_OPERATOR & op_;
      static const uint32_t portNumber_ = 1;
    };

    

    typedef std::tr1::unordered_map<WindowLHSTupleType, uint64_t> TupleMapLHSType;
    typedef std::tr1::unordered_map<WindowRHSTupleType, uint64_t> TupleMapRHSType;
    typedef std::vector<WindowLHSTupleType> TupleVectorLHSType;
    typedef std::vector<WindowRHSTupleType> TupleVectorRHSType;

    MY_OPERATOR();
    ~MY_OPERATOR();
  
    inline void submit(Tuple & tuple, uint32_t port) {
        MY_BASE_OPERATOR::submit(tuple, port);
        if (port == 0) _submitted = true;
    }

    inline void submit(Punctuation const & punct, uint32_t port)
    {   MY_BASE_OPERATOR::submit(punct, port); }

    virtual void process(Tuple const & tuple, uint32_t port);

    virtual void prepareToShutdown() {}

    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void evictLHS (WindowLHSTupleType & tuple);
    void evictRHS (WindowRHSTupleType & tuple);
    void cleanLHS (WindowLHSTupleType & tuple);
    void cleanRHS (WindowRHSTupleType & tuple);
    void resetSubmitted()
    { _submitted = false; }

    template <typename T>
    static void deserialize (SPL::Checkpoint & ckpt, std::deque<T> & value, std::vector<T> const & tupleVector);
    template <typename T>
    static void serialize (SPL::Checkpoint & ckpt, std::deque<T> const & value, std::tr1::unordered_map<T, uint64_t> const & tupleMap);

    template <typename Key, typename Value, typename T>
    static void deserialize (SPL::Checkpoint & ckpt, std::tr1::unordered_map<Key, Value> & map, std::vector<T> const & tupleVector);
    template <typename Key, typename Value, typename T>
    static void serialize (SPL::Checkpoint & ckpt, std::tr1::unordered_map<Key, Value> const & map, std::tr1::unordered_map<T, uint64_t> const & tupleMap);

    template <typename T>
    static void deserializeMatches (SPL::Checkpoint& ckpt, std::tr1::unordered_set<T> & matches, std::vector<T> const & tupleVector);
    template <typename T>
    static void serializeMatches (SPL::Checkpoint& ckpt, std::tr1::unordered_set<T> const & matches, std::tr1::unordered_map<T, uint64_t> const & tupleMap);

    template<typename T, typename G, typename D, typename S>
    static void populateTupleMap (SPL::Window<T,G,D,S> & window, std::tr1::unordered_map<T, uint64_t> & tupleMap);
    template<typename T, typename G, typename D, typename S>
    static void populateTupleVector (SPL::Window<T,G,D,S> & window, std::vector<T> & tupleVector);

    WindowLHSType    _windowLHS;
    WindowLHSHandler _winLHSHandler;
    WindowRHSType    _windowRHS;
    WindowRHSHandler _winRHSHandler;
    Mutex            _mutex;
    bool             _submitted;

    
    
        
    
    bool _emptyCountLHS;
    bool _emptyCountRHS;
    Metric& _lhsPartitionCount;
    Metric& _rhsPartitionCount;
    
}; 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_INNERJOIN1_H_

