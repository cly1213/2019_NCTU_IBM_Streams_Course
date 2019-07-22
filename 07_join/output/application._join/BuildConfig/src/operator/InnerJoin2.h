// eJy1VNFyojAUnfxJp7MP7YskaFvXmT6gddsKsnWjnbYvDoUsRoGkIRTx6zdYrCDa7s7uDk9cck7uOedeYh40BAkcSVnkBJ3OgNEIIADV0wLHjYYmM060LhmkYoghyhYplws_1sfDFYAWhNOdPA4yXA2v8_0GoO_0Z05gYn5PGFWvzk024v4ZTQyxm5r1H1ozI5rfAtk93yWLdp8jM8VX8rtOe67ryl2kW1ZI271p8g2h4oHwtSic3M8Sa8d2r3x6nQxTv_08PYWxb3vmcnR3f73kve8P54PECTj377_0Fbsj502MqJ49G4huzq97unZmwbxfNlbuycAazFW5LjPVs1Q9sc4r6N_1EotencGg_0zbmwY7Nk4u8oZIDgDAZVfIMB3VqeT0Eg2dbAuoXpJfyuVKs1apVWpAG3GQqIRL9F1LWViEXPHJRq8mM5VtprnSAdELCJ5wE7gM0HlLFSR58kbga_16o1FEBOglsWShRSURTgBCR7ozUDT4zFhAnHxOTihnQjXe8ImccsG8xJVT6p2cHl1eHq1VnoL_0kgsSx2rAAHlR7lKZWTd4wyViKWi0vnZNBctUJ3vRPw6jK43YTkiqDPr2mjf8PxhsQIFQtAgijwTKW1TOEBW5VopVqblbALksiWRxrAzV16sI1MxQDxR4d52MimijXmVK3l8K8e_1vyrRIKtfAe0uFVRUH_1mIVtwZIGpI9Gpr510MCW4XAFtiOz6bVUo4H5XBBXQJ_0Bsx544SA1QL_0_178GECoPvpYyQqC6zHsyr8WIPt6JzXkFrQT_0CSw_1qyC7Y_1EJaruA9fn5SNnm9PbG6eem1H8fe6M_12PK_0rd_0diwK6KexC1eGSVv33Ot6Kzb_0gX58_1E2W

#ifndef InnerJoin2$IndexKeyType_H
#define InnerJoin2$IndexKeyType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h"
#include "../type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.h"
#include "../type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.h"
#include "../type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h"

class InnerJoin2$IndexKeyType {
public:
  InnerJoin2$IndexKeyType() {}


  InnerJoin2$IndexKeyType(const InnerJoin2$IndexKeyType & o) :
    field0_(o.field0_)
  {}

  InnerJoin2$IndexKeyType(
    const SPL::rstring & field0
  ) :
    field0_(field0)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  const InnerJoin2$IndexKeyType & operator=(InnerJoin2$IndexKeyType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(InnerJoin2$IndexKeyType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(InnerJoin2$IndexKeyType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
  }

  SPL::rstring field0_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const InnerJoin2$IndexKeyType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, InnerJoin2$IndexKeyType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<InnerJoin2$IndexKeyType > {
      size_t operator()(InnerJoin2$IndexKeyType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, InnerJoin2$IndexKeyType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* InnerJoin2$IndexKeyType_H */



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


#ifndef SPL_OPER_INSTANCE_INNERJOIN2_H_
#define SPL_OPER_INSTANCE_INNERJOIN2_H_

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

#include "../type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h"
#include "../type/BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd.h"
#include "../type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.h"
#include "../type/BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h"

#include <bitset>

#define MY_OPERATOR InnerJoin2$OP
#define MY_BASE_OPERATOR InnerJoin2_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX IPort0Type;
    typedef SPL::BeJwrMSk1NCgoyk8pTS6Jz0wpNjSEcvwSc1NLLQpLE_1NKMksq00wLijKTUwGaiBHd IPort1Type;
    typedef SPL::BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC OPort0Type;
    
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
    
    
    
    SPL::uint32 lit$0;
    SPL::uint32 lit$1;
    SPL::int32 lit$2;
    SPL::int32 lit$3;
    SPL::int32 lit$4;
    
    
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

    
        typedef InnerJoin2$IndexKeyType EqualityKeyType;

        
            typedef std::deque<WindowLHSTupleType> LHSEqType;
        
        
            typedef std::deque<WindowRHSTupleType> RHSEqType;
        
        typedef std::tr1::unordered_map<EqualityKeyType, LHSEqType> LHSEqMapType;
        typedef std::tr1::unordered_map<EqualityKeyType, RHSEqType> RHSEqMapType;
    

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

    
        LHSEqMapType _LHSEq;
        RHSEqMapType _RHSEq;
    
    
        
    
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
#endif // SPL_OPER_INSTANCE_INNERJOIN2_H_

