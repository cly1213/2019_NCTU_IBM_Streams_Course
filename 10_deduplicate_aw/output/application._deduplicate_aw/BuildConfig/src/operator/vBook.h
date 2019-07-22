// eJytkk9Pg0AQxTNfpfHQXmCXVk24VauJClVDe24oHWGFsuvukIqf3i39E0FjLw2nXd6bfe_0XMapwKhKFoNr3JzipVCGSmBA4MPtx6DmOS7VC9wYfNzqMmBckuannOU1NbmZG6mluTJCUD0H94QW32bS29195StF7SE_0hCmfpfDy7Hr2OtZP1mpn2tQsG0Uvg_02_0FjOlqBABuJtfo4qryPHcjdW5UnKDL2WJl7_1apFvHGXcUUQylLZOABiTU_0V2RntqYdnhgTabGsCO81IuRYH4Ta2B9latMIJbWVOinSQphl2R_1A3afSaIyQZUNhr9gZz0ABBOgGLsClLUAFwiHONsDxEFeUSX08qmpZCJPhjxstEoSm89CzMBjIc0dd26jdkPx_1iI3YUmx1OeHZg_080PmHaqa3tN5kTzqNha25B5K1NGnpd41bcH_1Bmi3ew_0Xn3ogubtTmyLiP2R3vWKcVs3m9TN0Ti

#ifndef vBook$KeyType_H
#define vBook$KeyType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.h"

class vBook$KeyType {
public:
  vBook$KeyType() {}


  vBook$KeyType(const vBook$KeyType & o) :
    field0_(o.field0_)
  {}

  vBook$KeyType(
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

  const vBook$KeyType & operator=(vBook$KeyType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    return *this;
  }

  bool operator==(vBook$KeyType const & o) const {
    if(field0_ != o.field0_) return false;
    return true;
  }

  bool operator!=(vBook$KeyType const & o) const {
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
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const vBook$KeyType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, vBook$KeyType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<vBook$KeyType > {
      size_t operator()(vBook$KeyType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, vBook$KeyType const & x) {
    ostr << x.get_field0();
    return ostr;
  }

}

#endif /* vBook$KeyType_H */


#ifndef SPL_OPER_INSTANCE_VBOOK_H_
#define SPL_OPER_INSTANCE_VBOOK_H_

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

#include "../type/BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr.h"

#include <bitset>
#include <vector>

#define MY_OPERATOR vBook$OP
#define MY_BASE_OPERATOR vBook_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr IPort0Type;
    typedef SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr OPort0Type;
    typedef SPL::BeJwrMS02LcksyUktNsksTsorNkssLcnILyq2LChNyskszkgtSjMtKMpMTgUAT74QAr OPort1Type;
    
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
    
    
    
    SPL::float64 lit$0;
    
    
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


class MY_OPERATOR : public MY_BASE_OPERATOR, 
    public StateHandler
{
public:
    MY_OPERATOR();

    virtual void process(Punctuation const & punct, uint32_t port);
    virtual void process(Tuple const & tuple, uint32_t port);

    virtual void checkpoint(Checkpoint & ckpt);
    virtual void reset(Checkpoint & ckpt);
    virtual void resetToInitialState();

    typedef vBook$KeyType KeyType;
    struct ListDataType {
        ListDataType(KeyType const & k, double value)
            : _key(k), _value(value) {}

        ListDataType() {}
 
        void checkpoint(Checkpoint & ckpt) {
            ckpt << _key;
            ckpt << _value;
        }

        void reset(Checkpoint & ckpt) {
            ckpt >> _key;
            ckpt >> _value;
        }

        KeyType _key;
        double _value;
    };
    typedef std::list<ListDataType> TupleListType;
    typedef TupleListType::iterator ListElementIter;
    typedef std::tr1::unordered_map<KeyType, ListElementIter> TupleMapType;

private:
    void resetCommon();

    Mutex                  _mutex;
    
        double             _diff;        // time for 'uniqueness'
    
    TupleMapType           _map;         // The tuples to be checked
    TupleListType          _list;        // The ordered list of tuples

}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_VBOOK_H_

