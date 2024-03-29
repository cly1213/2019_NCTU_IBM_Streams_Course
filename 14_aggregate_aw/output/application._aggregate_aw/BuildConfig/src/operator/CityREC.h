// eJytUctu2zAQxP5K0LMlKmpg_0ObYFhDVVltQORsMtZaZUiRDLqPIX1_1GebTuueBpZjm7O7PB6ZnohCP0i0WlNHIbvURgkKdXwNVsltHkMLvFevQ7nhdcluGJj0U7L59PPLgnNbJm9Xi3nR4bzk_11aTf3jdSs3cyJ_0MvYct206qVuf26W5CS_1rWfHq4u_0k2_1u8utWlXE33bhv6_0r7FMZTK32dZhSTNDs_03i8PezbWK_1sqfl1MK_1qSA_1_0xXSx8IK9MD2eOvXEHbQXdlACQHe2AGXaxKLLR_0l_1BCYkZK_1ei7z32gnAvxqwTJMBYgzmUcEg5ALtszt4nLinhh0hYeUQ4WD8ISsV10ldvIAcZnmEVA9lhq1KwQsNRhDVqMVUKdffR_0sFajcIkAfmIsLImkDAEyig6_14Z_1zLB3h5c75OdjWWf9ZyL_18VgwgIevIBVN8JFFcmijIf8346yLWpCyBqIydF0kblj2_0Ae5TRdlirv7pPLfmyfLDY



#ifndef SPL_OPER_INSTANCE_CITYREC_H_
#define SPL_OPER_INSTANCE_CITYREC_H_

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

#include "../type/BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ.h"
#include "../type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h"


#define MY_OPERATOR CityREC$OP
#define MY_BASE_OPERATOR CityREC_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ OPort0Type;
    
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
#endif // SPL_OPER_INSTANCE_CITYREC_H_


