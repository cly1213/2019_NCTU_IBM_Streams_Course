// eJy9kN9OwjAUh3NehXi9lZGI7g4RjNtAzBwRbkjdyijb2kP_1uOHTOwhDfQHTi_0ac9vedftVYOjSjaJjy_1SkvWcxFAX0g7epDz3Fcc0TmPrCgVjqu_08eiRlPkNoqHwRchJtyvgzhuguht9RnOcBEmxIYfiYwmg1l4V_0hDm5k_1j8PmdbF8anD88n4bWFoi5stplVaI61VtktXI5qPd49jZ9c5zS25uCMSLyPeVNoqLHADcnayYyzLreW4tVaGRpswlw81ecuFm1FAQUrBTftuKtNsfQEedNKiY1lyKsyZHqa7D_1kkTOKjzDwPcA8_1AcmEGHqRWm1ZRQffk1oldC1Qys6m51gdLheHm2KUv55sf3qUzp9VvCk8ZbEtJTzc6htdFyDcKTa2q





#ifndef SPL_OPER_INSTANCE_FILESINK_8_H_
#define SPL_OPER_INSTANCE_FILESINK_8_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <SPL/Runtime/Common/Metric.h>
#include <streams_boost/iostreams/device/file_descriptor.hpp>
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

#include "../type/BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC.h"


#define MY_OPERATOR FileSink_8$OP
#define MY_BASE_OPERATOR FileSink_8_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC IPort0Type;
    
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
    
    
    
    SPL::rstring lit$0;
    
    
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
    MY_OPERATOR();

    virtual void prepareToShutdown();

    void process(Tuple const & tuple, uint32_t port);
    
    
        void process(Punctuation const & punct, uint32_t port);
    
    
  private:
    class Helper {
        public:
            Helper (const std::string& fName, bool restoring
                    
                    );
            
                std::ostream& fs() { return _fs; }
                std::ostream& writeTo() { return _fs; }
            
            void flush() { _fs.flush(); }
            int fd() { return _fd; }
            streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::output>& filt_str()
                { return _filt_str; }
        private:
            std::auto_ptr<streams_boost::iostreams::file_descriptor_sink> _fd_sink;
            std::ostream _fs;
            streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::output> _filt_str;
            
            
            int _fd;
    };


    
    

    std::string genFilename();
    std::string makeAbsolute(const std::string & path);
    void openFile(bool restoring);
    void closeFile();
    Mutex _mutex;
    volatile bool _shutdown;
    std::string _pathName;
    std::string _pattern;
    Metric& _numFilesOpenedMetric;
    Metric& _numTupleWriteErrorsMetric;
    std::auto_ptr<Helper> _f;
    uint32_t _fileGeneration;
    
    
    
    
    
    
    
    

    

    // Position of the file on a checkpoint/restore
    uint64_t _ckptOffset;
    bool _resetting;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_FILESINK_8_H_
