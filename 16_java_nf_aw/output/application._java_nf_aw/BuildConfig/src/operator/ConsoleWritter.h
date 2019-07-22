// eJzFk1trgzAYhsltf4WUXThW1GiPWSm0Y4OVrgxcr0NQ17rVKCaZc2P_1ffHQw6ajIJTFG3l9v_0Tx_1b6waKsJ7m99niJ0IxgPAwCBIR8LtDVN52nk6TNvnsQPdgKfbLr8IMbtdDbrTpdDbdMGY_1txgefL_0ztBHe6HlGEnDLB8FzhIs52Ztpmcdr1nLgNAC0iUCwNIP0I_05ZYJcgVWFLNQYsZjn64LzarRupXKXkXp19QNKq5hRRnV1MEa_0Co9_1I0P9E0YeLrnCtPUkzB_0ZRFxPB328Qt5I5g_0Y5LoLuEE0JB6WYOyNvlRGO_1j_0qtNwAdx3tLPliIXQrl73wqEVrsBiCQLt3OiBVXVPGblalfBoi12COPjY_1KOcvg1ZYJQZlDLguOGyy9hgFDWcoTKycht_0KeLuG5_0rtFR8pwu5bpuwG0duJtgrD2_0Yl6sNjy9f77U3utwHRGIaZlct0iu1zS50T_0yDwr2YVN2eMZxPQkPdzNbDu1XC8hL6oogSIEo7r7xDestLeL


#ifndef SPL_OPER_INSTANCE_CONSOLEWRITTER_H_
#define SPL_OPER_INSTANCE_CONSOLEWRITTER_H_

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

#include "../type/BeJwrMSw1TSnNza0EABB4AN8.h"
#include <SPL_JNIFunctions_com_nctu_myutils.h>
#include <SPL_JNIFunctions_com_nctu_myutilx.h>


#define MY_OPERATOR ConsoleWritter$OP
#define MY_BASE_OPERATOR ConsoleWritter_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSw1TSnNza0EABB4AN8 IPort0Type;
    
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
    
    
    
    SPL::int32 lit$0;
    SPL::int32 lit$1;
    SPL::rstring lit$2;
    SPL::rstring lit$3;
    SPL::int32 lit$4;
    SPL::int32 lit$5;
    SPL::rstring lit$6;
    SPL::int32 lit$7;
    SPL::int32 lit$8;
    SPL::rstring lit$9;
    SPL::int32 lit$10;
    SPL::int32 lit$11;
    SPL::rstring lit$12;
    
    
protected:
    Mutex $svMutex;
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
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_CONSOLEWRITTER_H_

