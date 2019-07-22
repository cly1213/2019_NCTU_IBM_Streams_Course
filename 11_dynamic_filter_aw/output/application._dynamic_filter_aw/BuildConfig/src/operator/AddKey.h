// eJyNUE1Pg0AQzfyVxjO70KYabkglsRRtQnvwRBaYFlLY2ewuEvz1LpqqvZk5zcd7b94zqvNELZRFHYZJ22FOg64QfOCuAlh4HrOTQvaI21FnOQXp_0j47VHqflm8mPaoszwO1ezonUSLjqLl4zeIGNOmXZ748tKshm9Yq3SSvkxk_1HMH28LAKpkpm_0XiMToU_1bmOawdxpd62945Dvd2GojdWtPAMAa6hHhvUQBGwkfTFKVMh8v6gnKfq2Kk5t52wUYmS1sAIkSeSwBDee_1dywXSUi6_1pysJhoRDiR7oV1y43DJ98Nh8q8QzwYS_12udfyig4Zs8oe0JOpQSHdq9YAQkzRWSPvlhAMp0j9u_1psi9KBd_0mbqS_0rg_0vUsIGqco_12d8U_0lY47i



#ifndef SPL_OPER_INSTANCE_ADDKEY_H_
#define SPL_OPER_INSTANCE_ADDKEY_H_

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

#include "../type/BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk.h"
#include "../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR AddKey$OP
#define MY_BASE_OPERATOR AddKey_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSo2K67MTcrPKbYsKUpMSS2pLEgFAFnCAhk OPort0Type;
    
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
#endif // SPL_OPER_INSTANCE_ADDKEY_H_


