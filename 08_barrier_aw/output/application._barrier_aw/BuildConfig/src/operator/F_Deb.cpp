// eJydUU9vgjAUz_1sqZge90BbN5rzhZMnGcBo4uFNTocNOoKyUEPn0A0Wik12Wpoe_0vN_1f5llsFFrEQh9mszlTSnAFBHB9xjAwDKQPGUdz_1loq15sQ_16NaOVNCXGy_0_01i5ge9iz46XYk_0JW3mULJ3StpIIO0_0_0sRvcMMgbBmttlSraLHu2N_0uqwrn_0wo9OZdnW8_1fLYvHQ7DXuAO1kwhEPC9NEpVT7PGMBR3hKt6cUlJUoZJpBKlPeIMz6ikwqfYfBW73Vcf_0TCgSok4G6IEbTIoFCpHpsQlArx_1AZS6bvJxDyLWWJLFLdjUgrTy7le0NeiBBIeXnF3PyO7Mnxd7eQ1HTmtVsCrY323XVjRFzT4_0pw9CtThzkPziByBLVGh6OGjfwATB_0wD0




#include "./F_Deb.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR F_Deb_Base
#define MY_OPERATOR F_Deb$OP



MY_OPERATOR_SCOPE::MY_OPERATOR::MY_OPERATOR()
: MY_BASE_OPERATOR()
{
    
}



MY_OPERATOR_SCOPE::MY_OPERATOR::~MY_OPERATOR()
{
    // Delete any remaining tuples in the windows
    
        for (uint32_t i = 0; i < 2; i++) {
            DequeType& d = Tuples._tuples[i];
            for (DequeType::iterator it = d.begin(); it != d.end(); it++)
                delete *it;
        }
    
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port)
{
    const Tuple *inputTuples[2];
    {
        AutoMutex am(_mutex);
        
        if (Tuples._tuples[port].empty())
            Tuples._nonEmptyQueues++;
        Tuples._tuples[port].push_back (tuple.clone());
        if (Tuples._nonEmptyQueues != 2)
            return;

        
        for (uint32_t i = 0; i < 2; i++) { // clean up
            DequeType& d = Tuples._tuples[i];
            inputTuples[i] = d.front();
            
            d.pop_front();
            if (d.empty())
                Tuples._nonEmptyQueues--;
        }
        
        
    }

    // Now we can submit the output tuple and delete the input tuples
    
        const IPort0Type& iport$0 =
            static_cast<const IPort0Type&>(*inputTuples[0]);
    
        const IPort1Type& iport$1 =
            static_cast<const IPort1Type&>(*inputTuples[1]);
    

    OPort0Type otuple (iport$0.get_a_num(), iport$1.get_new_bal());
    submit (otuple, 0);

    // Now delete the saved input tuples
    for (uint32_t i = 0; i < 2; i++)
        delete inputTuples[i];
}




static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("F_Deb",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator()  {
    uint32_t index = getIndex();
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("011"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
    switch(port) {
    }
}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(2);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    case Punctuation::WatermarkMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    case 1:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}


