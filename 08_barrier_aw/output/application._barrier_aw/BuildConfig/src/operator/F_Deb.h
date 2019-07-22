// eJydUU9vgjAUz_1sqZge90BbN5rzhZMnGcBo4uFNTocNOoKyUEPn0A0Wik12Wpoe_0vN_1f5llsFFrEQh9mszlTSnAFBHB9xjAwDKQPGUdz_1loq15sQ_16NaOVNCXGy_0_01i5ge9iz46XYk_0JW3mULJ3StpIIO0_0_0sRvcMMgbBmttlSraLHu2N_0uqwrn_0wo9OZdnW8_1fLYvHQ7DXuAO1kwhEPC9NEpVT7PGMBR3hKt6cUlJUoZJpBKlPeIMz6ikwqfYfBW73Vcf_0TCgSok4G6IEbTIoFCpHpsQlArx_1AZS6bvJxDyLWWJLFLdjUgrTy7le0NeiBBIeXnF3PyO7Mnxd7eQ1HTmtVsCrY323XVjRFzT4_0pw9CtThzkPziByBLVGh6OGjfwATB_0wD0



#ifndef SPL_OPER_INSTANCE_F_DEB_H_
#define SPL_OPER_INSTANCE_F_DEB_H_

#include <deque>
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

#include "../type/BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT.h"
#include "../type/BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN.h"
#include "../type/BeJwrMXQzz0stj09KzAEAFqIDD7.h"

#include <bitset>

#define MY_OPERATOR F_Deb$OP
#define MY_BASE_OPERATOR F_Deb_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS41TYzPK811M02OT0rMcTM0SElNik_1MzS_1NKwEAmg0KCT IPort0Type;
    typedef SPL::BeJwrMXQzz0stj09KzAEAFqIDD7 IPort1Type;
    typedef SPL::BeJwrMSo1TYzPK811M02OT0rMAQAwrgXN OPort0Type;
    
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
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    
    
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
    typedef int32_t PartitionByType; 

    typedef std::deque<const Tuple*> DequeType;
    struct OneQueueSet 
    {
        OneQueueSet () : _nonEmptyQueues(0)
             {}

        void resetToInitialState() {
            _nonEmptyQueues = 0;
            
            for (uint32_t i = 0; i < 2; i++) {
                DequeType & d = _tuples[i];
                for (DequeType::iterator it = d.begin(); it != d.end(); it++)
                    delete *it;
                d.clear();
            }
        }

        template <class S>
        friend SPL::ByteBuffer<S> & operator>>(ByteBuffer<S> & buf, OneQueueSet & value) {
            buf >> value._nonEmptyQueues;
            
            uint64_t queueSize;
            
                // Queue size
                buf >> queueSize;
                
                DequeType & d0 = value._tuples[0];
                // Clear deque before inserting data to it
                d0.clear();
                // Each tuple in the queue
                IPort0Type iport$0;
                for (int i = 0; i < queueSize; i++) {
                    buf >> iport$0;
                    d0.push_back(iport$0.clone());
                }
            
                // Queue size
                buf >> queueSize;
                
                DequeType & d1 = value._tuples[1];
                // Clear deque before inserting data to it
                d1.clear();
                // Each tuple in the queue
                IPort1Type iport$1;
                for (int i = 0; i < queueSize; i++) {
                    buf >> iport$1;
                    d1.push_back(iport$1.clone());
                }
            
            return buf;
        }
 
        template <class S>
        friend SPL::ByteBuffer<S> & operator<<(SPL::ByteBuffer<S> & buf, const OneQueueSet & value) {
            buf << value._nonEmptyQueues;
            
            
                // Queue size
                buf << (uint64_t) value._tuples[0].size();
                
                const DequeType & d0 = value._tuples[0];
                // Each tuple in the queue
                for (DequeType::const_iterator it = d0.begin(); it != d0.end(); it++) {
                    const Tuple * tup = static_cast<const Tuple *>(*it);
                    const IPort0Type& iport$0 =
                        static_cast<const IPort0Type&>(*tup);
                    buf << iport$0;
                }
            
                // Queue size
                buf << (uint64_t) value._tuples[1].size();
                
                const DequeType & d1 = value._tuples[1];
                // Each tuple in the queue
                for (DequeType::const_iterator it = d1.begin(); it != d1.end(); it++) {
                    const Tuple * tup = static_cast<const Tuple *>(*it);
                    const IPort1Type& iport$1 =
                        static_cast<const IPort1Type&>(*tup);
                    buf << iport$1;
                }
            
            return buf;
        }

        DequeType _tuples[2];
        uint32_t _nonEmptyQueues;
        
    };

    

    MY_OPERATOR();
    ~MY_OPERATOR();
  
    virtual void process(Tuple const & tuple, uint32_t port);

    

    

private:
    

    Mutex _mutex;
    
        OneQueueSet Tuples;
    
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_F_DEB_H_

