// eJy1Uk1PgzAYzvtXjAe9AGXTzN2YLsY5iLPs4mVpoGId0NoWC_1v1Fieb24x60PQCzfs87_1NRJXJH0pxoxkuSD4dBlkmaEU0BgWePD0eO4_0pGUHdEJ0aG2PNx0lcv2PjxoP_06wkq8MIOiy_0ebafMcYbyarMKBjJIcxeOB1rg2Mc6jmNWTeDYOtEjwaOI8HR3wKhSFZ5EM9nhmafN434vn_1etwdWWMuQhumkux5cTLQz3ZLJjdqofRvN3jWSc508ce4LvpcMhK3fMBwH3iBXVpWvm_0a7hcKkES6qL_0gnQJLIhxU6IJlLykLUsmeSVGjc3knUkqLVmZ2QVMcGkXOBnVi4Tp5uQUxrWQVCmb6rfDvCq13JtH26E19g_0DBwayTcRDmhW240_0RdCmtD8AZtFagE_14hdfMvuKjWzwaqNUERZLT7FuO0SmyGaXfRmuJfmPqP1qGwJs_0hIPXdgUgUktqKeZfwcbVbydaXbcVShJ9c_1QhuI2hhrNyFsfKXsMPcfsJuEJZgpzA0JUp30G_1f6n61v0F2D9f2_0gbXmVxh

#ifndef B_Result$GroupByType_H
#define B_Result$GroupByType_H
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Serialization/ByteBuffer.h>
#include <SPL/Runtime/Utility/TimeUtils.h>
#include "../type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h"
#include "../type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.h"

class B_Result$GroupByType {
public:
  B_Result$GroupByType() {}


  B_Result$GroupByType(const B_Result$GroupByType & o) :
    field0_(o.field0_),
    field1_(o.field1_)
  {}

  B_Result$GroupByType(
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

  const B_Result$GroupByType & operator=(B_Result$GroupByType const & o) {
    if(this==&o) return *this;
    field0_ = o.field0_;
    field1_ = o.field1_;
    return *this;
  }

  bool operator==(B_Result$GroupByType const & o) const {
    if(field0_ != o.field0_) return false;
    if(field1_ != o.field1_) return false;
    return true;
  }

  bool operator!=(B_Result$GroupByType const & o) const {
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
inline SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const B_Result$GroupByType & v)
{
    v.serialize(buf); return buf;
}
template <class S>
inline SPL::ByteBuffer<S> & operator>>(SPL::ByteBuffer<S> & buf, B_Result$GroupByType & v)
{
    v.deserialize(buf); return buf;
}

namespace std {
  namespace tr1 {
    template <>
    struct hash<B_Result$GroupByType > {
      size_t operator()(B_Result$GroupByType const & val) const {
        return val.hashCode();
      }
    };
  }
}

namespace SPL {
  std::ostream & operator<<(std::ostream & ostr, B_Result$GroupByType const & x) {
    ostr << x.get_field0();
    ostr << x.get_field1();
    return ostr;
  }

}

#endif /* B_Result$GroupByType_H */




#ifndef SPL_OPER_INSTANCE_B_RESULT_H_
#define SPL_OPER_INSTANCE_B_RESULT_H_

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

#include "../type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h"
#include "../type/BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU.h"

#include <bitset>

#define MY_OPERATOR B_Result$OP
#define MY_BASE_OPERATOR B_Result_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ IPort0Type;
    typedef SPL::BeJwrMSs1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTSk2Sc4sqSw2T84vzSspqgQAQKsZBU OPort0Type;
    
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
                    public SPL::WindowEvent<SPL::BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ >,
                    public StateHandler
{
public:
    typedef B_Result$GroupByType GroupByType; 
    
    
    
    typedef int32_t PartitionByType; 
    typedef SPL::TumblingWindow<IPort0Type > WindowType;
    typedef SPL::WindowEvent<IPort0Type > WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 



    void beforeWindowFlushEvent(WindowEventType::WindowType & window,
                                WindowEventType::PartitionType const & partition);



    struct Tumbling$B_Result$G;

    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void aggregatePartition(WindowEventType::WindowType & window, 
                            WindowEventType::PartitionType const & partition);

    WindowType _window;
    Mutex    _mutex;

    Metric& _partitionCount;
    
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_B_RESULT_H_

