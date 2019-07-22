// eJytUUFuwjAQ1H4F9dBeEidQleYGAVUlBBAJFy6RRVxwE2zLXpOG19dBAkHP1V527NHszK5RtUdLqpDpKMrjVcZFBQEQVyH0PM_1HVjF_1zGaNTjMS5kOrvtOhPnc9qXA3rUzm_0rYtgiRPiyBNztuZe7FJvp2NB3I8mtjN6L0IvEPvQa_1Vi0_1ZT8gAk8pgWp2W7ea8SJrpaLlqPuJFxyfOSc3xiUC2mkeR5QL7IQD4B3lkPittGPqN1JVRdMf84K1wAQra_0CVFCkIKRqAPWtbM6WRyVzFcd4CAYfrENMTWoDzOuQtPa1BSY0e8G3UdP_11RmhnDpYCv2prDH9qDv_0dg8wKxFAapwMsqead8DfEPqwQO_0nIhgFfnpy2EPYI2qLnYQ8nUhCK7Yan5nou7b4M3sL8nkl_1NRKIK



#ifndef SPL_OPER_INSTANCE_TCPSINK_2_H_
#define SPL_OPER_INSTANCE_TCPSINK_2_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <streams_boost/iostreams/device/file_descriptor.hpp>
#include <SPL/Toolkit/TCPServer.h>
#include <SPL/Runtime/Common/Metric.h>
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

#include "../type/BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1.h"
#include "../type/BeJyrNIo3K04tKkstMkvOyUzNKwEAOPwGCN.h"


#define MY_OPERATOR TCPSink_2$OP
#define MY_BASE_OPERATOR TCPSink_2_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1 IPort0Type;
    
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
    
    
    
    SPL::uint32 lit$0;
    
    
protected:
    Mutex $svMutex;
    SPL::rstring param$role$0;
    SPL::uint32 param$flush$0;
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

    virtual void process(Tuple const & tuple, uint32_t port);
    bool processInternal(Tuple const & tuple, uint32_t port);

    virtual void process(Punctuation const & punct, uint32_t port);
    bool processInternal(Punctuation const & punct, uint32_t port);

    
        virtual void allPortsReady();
        virtual void process(uint32_t index);
    

private:
    inline void setupLocked (int32_t fd);
    void setup (int32_t fd);
    void cleanup();
    void closeConnection ();
    bool isDisconnected();
    void reconnectToNewConnection();
    inline bool canReconnect();

    std::auto_ptr<streams_boost::iostreams::file_descriptor_sink> _fd_sink;
    std::auto_ptr<SPL::TCPServer> _connector;
    std::auto_ptr<streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::output> > _filt_str;
    std::auto_ptr<std::ostream> _fs;
    
    
    
        CV _cv;
    
    Mutex _mutex;
    
    uint32_t _tuplesUntilFlush;
    
    
    volatile bool _connected, _connectionClosed;
    
    Metric& _numReconnects;
    Metric& _numConnections;
    Metric& _numWireFormatHandshakesFailed;
    
    
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_TCPSINK_2_H_


