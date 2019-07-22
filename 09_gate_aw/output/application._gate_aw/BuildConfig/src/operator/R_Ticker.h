// eJytkV9vgjAUxXO_1ivFhe4HCzJbxhu5PFHEm1GdSocMGaLu2DPTTD4g6J3vb0rfm3HN_0514tC6syrGBm73mvxFBwALXPhZFl2WYvqT2li1qFUe4G9w8hTtQ6wqEJQhli5jrBrFkdZp_0LZZBrw2oZ5c3iieQ68jf_0XEzWfmbtRgOv2sGbwxvO0dT3Y8f1V_1NOhdrsFmSMIFovPa9i3Ny5AGDvREltmlaua9dC5VqShNroMc5a3pjUdkoMAS447bhL0mw4SXKa4koWdCYqblrjS8tTjG_0MYtvK0BdFKfCq7Cc0Fn6SX40gYFIoM3asjJq4t7_05hedGKqo1Exy_0JUf8P64NGKj_0EgAT0PtyKwpQuuXlGUjFEgrvhSAd2kdFuGnvB0dUo0hKcbvts945wf8gGx7hItOBviOcN4ZA_1He7QS901QwNuqFf2qHu2_1kCLdfdDD


#ifndef SPL_OPER_INSTANCE_R_TICKER_H_
#define SPL_OPER_INSTANCE_R_TICKER_H_

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

#include "../type/BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg.h"
#include "../type/BeJwrMSw1TUzOTk0BAA_12ANI.h"

#include <bitset>

#define MY_OPERATOR R_Ticker$OP
#define MY_BASE_OPERATOR R_Ticker_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg IPort0Type;
    typedef SPL::BeJwrMSw1TUzOTk0BAA_12ANI IPort1Type;
    typedef SPL::BeJwrMSk2K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJDaksSAUAIo4PAg OPort0Type;
    
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
    
    
    
    SPL::uint32 lit$0;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<3> OPortBitsetType;
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
    MY_OPERATOR();

    virtual void process(Tuple const & tuple, uint32_t port);
    virtual void process(Punctuation const & punct, uint32_t port);

    virtual void prepareToShutdown();

private:
    uint32_t   _maxUnackedTupleCount;           // maximum allowed to be unack'ed
    int32_t    _unackedCount;                   // current number of tuples unacked
    Mutex      _mutex;
    CV         _waitForACKs;
    volatile bool _done;                        // finished processing (shutdown or Final punct)
    uint32_t   _numWaiting;                     // number of threads waiting for an ack


}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_R_TICKER_H_

