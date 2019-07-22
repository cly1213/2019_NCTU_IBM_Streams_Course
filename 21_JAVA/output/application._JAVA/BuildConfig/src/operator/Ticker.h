// eJy1VV1v2jAUlV_17K6yqk5KpSuxQaBcGEmXtAzRVpaC9Ije4xSJfi51SivjvSxwToIatqmh4wLofJ_0ce33vD09DKBQuZWLhuP_0ciiQAGqPhhcGpZtlik1L6mg3nm_0cgZti69UZA9_0CNPDL3UGzEHD_1uv92_19l8HdcMYFm6f_07HVwR2bc7zuOf1P8_043B2w267d3_1wtde05qegkvABRH0LIgF8B_1uXDdnsWg4O2cMCk5nLRXJF9FjEvIqImRc_1JSnjIuMxc_0we9hR4azfmGYsoBrMU5iQ4p06zMaBgetKE0_1DcUDWAXtCz_0E_0T_0sCdmHXdctUo2R0ZSpKf3ISCyaYTqtSQmdV26vafiggkZEJLe_1r8zJh9B6LxRMWEJFk_17kojFVmRnkeqms9Zt98ASI6PqZhWkFISWaYADtSGLQjVqUV2O6LyuboYQ3ddKGbmrqppZsuD9_089F_1t7fyyaYHqsUM9uO6bf_0NjvMsJ2NMkojad5I5jz5NsxlMSUNvB40Hvd8_0eEEFAnMS0WkQIsDTJai2P2gQRyOS6W57A4qn3EuzALcLG3uGvfGrea8HUjK9TbvM4ECyJuet6REwLZUg8SSLDhN_0hVMY04Td5QmZbcmBP0DAOjSHsdGSwU6TJ6PJZ1qdNDftSZWajXUev5ImGnH4O6uI91PYKsJ6pGFd7uyi2A3cWuUWEUWut6taS1WZcbKVvluWHEOS630qv1v_0HUuuit9I3G3YDoYujECcJXMKj9ysUNEprQhXfNuT5Y8QENErnubyaptmGKzifspAaZWOtTgBogkp9oIYTSDmA_0nKBtdxADWldWR1fjCUVLNoYytFMvnQ0Nc7oHWuk8UZ7mCOdOyrI_1wUzh80F


#ifndef SPL_OPER_INSTANCE_TICKER_H_
#define SPL_OPER_INSTANCE_TICKER_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
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

#include "../type/BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5.h"

#include <bitset>

#define MY_OPERATOR Ticker$OP
#define MY_BASE_OPERATOR Ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 IPort0Type;
    typedef SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
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
    SPL::float64 lit$1;
    SPL::uint32 lit$2;
    SPL::uint32 lit$3;
    SPL::uint32 lit$4;
    SPL::uint32 lit$5;
    SPL::uint32 lit$6;
    SPL::list<SPL::rstring > lit$7;
    SPL::list<SPL::float64 > lit$8;
    SPL::list<SPL::uint32 > lit$9;
    SPL::list<SPL::rstring > lit$10;
    SPL::uint32 lit$11;
    
    SPL::uint32 state$cnt;
    SPL::list<SPL::rstring > state$symbols;
    SPL::list<SPL::float32 > state$prices;
    SPL::list<SPL::uint32 > state$quantities;
    SPL::list<SPL::rstring > state$tradetypes;
    SPL::uint32 state$tradetypeindicator;
    SPL::BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5 state$result;
    
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
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TICKER_H_

