// eJytUctOwzAQ1P4K4tw4aXiot9ISiTyAKqkEXJCbbFu3qW3sNSF8PW55iHJGPs3YM96Ztbod8IZrQjMaJaLFUjlTI4TA_1IngZDAIqNcYXGHamaJkYb_1tNG1XLi8v0nfGKNs8pWX5lubV42tW6Ptszly2mKv8elhkl1v7MpuNqzqeXT0M1idHfr25vWHDSsSu6M91Nk3uetu9V7VJq8s46mtZlN18vHwOu3Si9uL9QK2gUwblfT4aGUtGyBUcuPCTW7aK03kMAMFa7TDAxkVR0CmztZrXGLCL540SMmg4cZBKIoMYlj43hMem4ddPY_1J44QgTgwhLZXac_1OXU65NPwKC2rzBxltQuF75I3sKa2ym2vE8Ets239UKpFrn0AjIOYaKkJS4JhBR0eA1_1QoRfyY5nYIflKK3MTxP_1sBzYgYEzEA04IWkY7WMdIqGB704Y_0NrwF9RGNa6mX8yL84kE9T8u7AORPMDW



#ifndef SPL_OPER_INSTANCE_ORDER_H_
#define SPL_OPER_INSTANCE_ORDER_H_

#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <streams_boost/iostreams/device/file_descriptor.hpp>
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

#include "../type/BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX.h"
#include "../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR Order$OP
#define MY_BASE_OPERATOR Order_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS01ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqQQATc4QBX OPort0Type;
    
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
    SPL::float64 lit$1;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$format$0;
    SPL::boolean param$hasDelayField$0;
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
    
    
    
    
    
    
        std::auto_ptr<streams_boost::iostreams::file_descriptor_source> _fd_src;
    
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
#endif // SPL_OPER_INSTANCE_ORDER_H_


