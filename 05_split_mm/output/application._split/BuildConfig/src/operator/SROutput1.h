// eJzt2M9r4kAUwHHev1L2sHtJMmOMrTcFC626FGKh7EXUju2s_0cVkrE3_1_0p3GeaFu4bWUHh8eJGHeOPng4UvqKgv2VmfaNsNhWrlvEBC5j4CzIAhtU6lwrK4PZp7u5DQZzBcbczNd_17lK0_0fr2aaYL_05uX2bp3_0liEtvf6WD2cpiMmng0HxfB41m7j9vzRwTpzWw4NLU1ungAgPCxzFWo7vdShofS7OpqtVFh1F_1Wr2dY5nl4v7IrKMpCRSBhqzPltjrZBHceWXe93lt1aZSCnWr_0XxiBrkrjlgYPyi7rJl_0X2c9fMHmujKprXRbtI_1s1x9EvPjJoMK0eQAzHHwI8hXseZXWuuhuV0RsF26xc2SSGJ7d0rwvbkyATt0P5Xcd5dxDxSZ93B_15gENe70dNH6_0bwxulcu9gNvRHoJvz16cDT6_1FE_0986KglWIpSkV5KsRCj1vFKPlQil2CvFrEQo9b1Sn5UIpcQrJaxEKA280oCVCKVzr3TOSoTShVe6YCWqKjG_0Bdc36dTlN_1c36YQBLrjASSdMcMENTjphhAuucNIJM1xwh5NOGOKCS5x0whQX3OKkE8a44BonnTDHBfc4_0f4Se1xyj5NO2OOSe5x06l6Ic4_0TTtjjknucdMIel9zjpBP2uOQeJ5z_0AfxBLIx



#ifndef SPL_OPER_INSTANCE_SROUTPUT1_H_
#define SPL_OPER_INSTANCE_SROUTPUT1_H_

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

#include "../type/BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn.h"

#include <bitset>
#include <vector>

#define MY_OPERATOR SROutput1$OP
#define MY_BASE_OPERATOR SROutput1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn IPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort0Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort1Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort2Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort3Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort4Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort5Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort6Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort7Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort8Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort9Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort10Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort11Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort12Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort13Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort14Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort15Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort16Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort17Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort18Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort19Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort20Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort21Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort22Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort23Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort24Type;
    typedef SPL::BeJwrMSk2K67MTcrPKbZISSxJLcnMTXUzLSjKTE4tNS7LzwEAy4AMBn OPort25Type;
    
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
#endif // SPL_OPER_INSTANCE_SROUTPUT1_H_

