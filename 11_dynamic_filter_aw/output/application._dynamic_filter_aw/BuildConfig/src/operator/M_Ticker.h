// eJy9VF1v2jAU1X3dr0DVHkCdkthUq5RNk1JWpJFkQgo87ClyExesBNuzTYH9_0jkBUj66bGjrlKdY99xzzvW51rJ0loaVzGx8_1_1OGkwXLhqw0VAECz34YrhzHNRtJ3Ts6Wqk4KXD4_1jaeZGqcTGITxjKeMIzCwfrrj8HTKAoLbdhKJsV6FJFCJ8E0_0LK6Gd8FzvzqrJdoeoUP33Q4lXGSYBndz4bBkA_0CeVGBKhFW4FsPknHk_00obxfgM6jN0cgbuXCyoS_1Mlxu5KqEJLklEXoTTfmksfa3cpWbk5MQS44NSDPhR0Y2mOmnnApFCW15lRk_0rN4kGU3R7cr6WiWjPB28qNIjmtrB4jSJ6Hv2ZClzGhNiZFF_0KJtpDhy8hwG1n_12f0W_1ZdZAQaqjh_1ADWwlwl6QVCyj8FgKYvoYvi8JNza9sGS8_0m8ENvVoP60jZb9NXiPB92vccMkzY71q35_1uF8ZK4SapaSLe7dYh7Vx3dggtyzQj2nw8nOe7zkUqOp98v_0rR3Xno9Xof3oC90pOhnNvG_03v7L7bRq9rGl9j2QPzrJJ5l0DtJoXeWQ_08FbV61JshKRDuJ6BUlIkB_19JwdG2lQz84OUXWxBZ26bWCN_00PUvtoCX1rPVp0HD85uej8BPnUmDF

#ifndef M_Ticker$KeyType_H
#define M_Ticker$KeyType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA.h"
#include "../type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.h"

class M_Ticker$KeyType {
public:
  M_Ticker$KeyType() {}


  M_Ticker$KeyType(const M_Ticker$KeyType & o) :
    field0_(o.field0_),
    field1_(o.field1_)
  {}

  M_Ticker$KeyType(
    const SPL::rstring & field0,
    const SPL::rstring & field1
  ) :
    field0_(field0),
    field1_(field1)
  {}

  SPL::rstring & get_field0() {
    return field0_;
  }

  SPL::rstring const & get_field0() const {
    return field0_;
  }

  SPL::rstring & get_field1() {
    return field1_;
  }

  SPL::rstring const & get_field1() const {
    return field1_;
  }

  const M_Ticker$KeyType & operator=(M_Ticker$KeyType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    field1_ = o.field1_;
    return *this;
  }

  bool operator==(M_Ticker$KeyType const & o) const {
    if(field0_ != o.field0_) return false;
    if(field1_ != o.field1_) return false;
    return true;
  }

  bool operator!=(M_Ticker$KeyType const & o) const {
    return !(*this==o);
  }

  size_t hashCode() const {
    size_t r = 17;
    size_t c;
    c = std::tr1::hash<SPL::rstring >()(field0_);
    r = 37 * r + c;
    c = std::tr1::hash<SPL::rstring >()(field1_);
    r = 37 * r + c;
    return r;
  }

  template <class S>
  void serialize(SPL::ByteBuffer<S> & buf) const {
    buf << field0_;
    buf << field1_;
  }

  template <class S>
  void deserialize(SPL::ByteBuffer<S> & buf) {
    buf >> field0_;
    buf >> field1_;
  }

  SPL::rstring field0_;
  SPL::rstring field1_;
};
template <class S>
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const M_Ticker$KeyType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, M_Ticker$KeyType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<M_Ticker$KeyType > {
      size_t operator()(M_Ticker$KeyType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, M_Ticker$KeyType const & x) {
    ostr << x.get_field0();
    ostr << x.get_field1();
    return ostr;
  }

}

#endif /* M_Ticker$KeyType_H */




#ifndef SPL_OPER_INSTANCE_M_TICKER_H_
#define SPL_OPER_INSTANCE_M_TICKER_H_

#include <SPL/Runtime/Operator/State/StateHandler.h>
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
#include "../type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.h"

#include <bitset>
#include <vector>

#define MY_OPERATOR M_Ticker$OP
#define MY_BASE_OPERATOR M_Ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA IPort0Type;
    typedef SPL::BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk IPort1Type;
    typedef SPL::BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk IPort2Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSAUAIw4PBA OPort1Type;
    
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
    SPL::rstring lit$1;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<4> OPortBitsetType;
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


class MY_OPERATOR : public MY_BASE_OPERATOR,
    public StateHandler
{
public:
    MY_OPERATOR(); 
    void process(Tuple const & tuple, uint32_t port);   
    void process(Punctuation const & punct, uint32_t port);

    virtual void checkpoint(Checkpoint & ckpt);
    virtual void reset(Checkpoint & ckpt);
    virtual void resetToInitialState();

private:
    void processKey(Tuple const & tuple);
    void processAddKey(Tuple const & tuple);
    
        void processRemoveKey(Tuple const & tuple);
    

    Mutex _mutex;

    typedef M_Ticker$KeyType KeyType;
    typedef std::tr1::unordered_set<KeyType> SetType;
    SetType set_;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_M_TICKER_H_


