// eJyNkNFOgzAUhnNeZfEaCkOzcIdbMM4xdaC3S8eK1JW2tqcj_0PRWzKa7M7360v5fz3_0sFgHdU43MpGnOBSuVMzWDCIg_1MUyCIMRBs_1CWLXtTlId44DO1rpNjkT1vNh_0v3YbKXFcHkd0d2_0xdBe3kIjSY9T2ZVjxxxXCjHxb542D7z6o2y2qWxEMti7J_1yZpt1C_1nY5j4vwXHKwLl0ypNjUXD5RsAhK3qWMj2Lo7DXpmD1bRmYXS9tVo0TtbIldzSPtxTpCCVZASm0PhKXnihOvkz9LxzyHLDGDTKdBT95cLn8x8gUNsjzJ1F1a243xEV0CrM_10h3SglGpX_0KxjGYK2mRShxrEFBamXOV_164QOjCQ_0CycJv4WReC4xGk8QvwLhlkn8MzkC4IBJK8



#ifndef SPL_OPER_INSTANCE_AOP_H_
#define SPL_OPER_INSTANCE_AOP_H_

#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <streams_boost/iostreams/device/file_descriptor.hpp>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>
#include <SPL/Toolkit/HotFile.h>
#include <SPL/Runtime/Common/Metric.h>
#include <streams_boost/filesystem/path.hpp>
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

#include "../type/BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo.h"
#include "../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR Aop$OP
#define MY_BASE_OPERATOR Aop_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yi8oNc4vMAQRRqVmRanFpTklAGvhAjo OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    
    inline void submit(Tuple & tuple, uint32_t port)
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
    SPL::rstring param$format$0;
    SPL::boolean param$hotFile$0;
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
    
    
        virtual void process(uint32_t index);
        virtual void allPortsReady();
    

    virtual void prepareToShutdown();

    

private:
    void initialize();
    std::string makeAbsolute(const std::string & path);
    inline void punctAndStatus(const std::string& pathName);
    void processOneFile (const std::string& pathName);
    
    

    int32_t _fd;
    uint64_t _tupleNumber;
    
    
    
    
    
    
    std::auto_ptr<streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::input> > _filt_str;
    
        std::auto_ptr<std::istream> _fs;
    
    
    Metric& _numFilesOpenedMetric;
    Metric& _numInvalidTuples;

    
    std::streamoff _position;
    
    bool _reset; 
    // When FileSource is a start operator, this indicates
    // whether the file has been opened yet.
    bool _initialized;

    
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_AOP_H_


