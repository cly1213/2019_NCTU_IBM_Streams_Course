// t5s7fly_nums7depDates6origins4dests4gate


#ifndef BEJWRMS02T8UPJM8RZS02T0KTCEKSSS02YY_1KTM_1MKZZJSS0UKTZJB4OBADUUA9_1_H_
#define BEJWRMS02T8UPJM8RZS02T0KTCEKSSS02YY_1KTM_1MKZZJSS0UKTZJB4OBADUUA9_1_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrMS02T8upjM8rzS02T0ktcEksSS02yy_1KTM_1MKzZJSS0uKTZJB4oBADuUA9_1

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::rstring fly_num_type;
    typedef SPL::rstring depDate_type;
    typedef SPL::rstring origin_type;
    typedef SPL::rstring dest_type;
    typedef SPL::rstring gate_type;

    enum { num_attributes = 5 } ;
    
    SELF() : Tuple(), fly_num_(), depDate_(), origin_(), dest_(), gate_() {}
    SELF(const Self & ot) : Tuple(), fly_num_(ot.fly_num_), depDate_(ot.depDate_), origin_(ot.origin_), dest_(ot.dest_), gate_(ot.gate_) 
      { constructPayload(ot); }
    SELF(const fly_num_type & _fly_num, const depDate_type & _depDate, const origin_type & _origin, const dest_type & _dest, const gate_type & _gate) : Tuple(), fly_num_(_fly_num), depDate_(_depDate), origin_(_origin), dest_(_dest), gate_(_gate) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    fly_num_type & get_fly_num() { return fly_num_; }
    const fly_num_type & get_fly_num() const { return fly_num_; }
    void set_fly_num(const fly_num_type & _fly_num) { fly_num_ = _fly_num; }
    depDate_type & get_depDate() { return depDate_; }
    const depDate_type & get_depDate() const { return depDate_; }
    void set_depDate(const depDate_type & _depDate) { depDate_ = _depDate; }
    origin_type & get_origin() { return origin_; }
    const origin_type & get_origin() const { return origin_; }
    void set_origin(const origin_type & _origin) { origin_ = _origin; }
    dest_type & get_dest() { return dest_; }
    const dest_type & get_dest() const { return dest_; }
    void set_dest(const dest_type & _dest) { dest_ = _dest; }
    gate_type & get_gate() { return gate_; }
    const gate_type & get_gate() const { return gate_; }
    void set_gate(const gate_type & _gate) { gate_ = _gate; }
    virtual bool equals(const Tuple & ot) const
    {

        if (typeid(*this) != typeid(ot)) { return false; }
        const SELF & o = static_cast<const SELF &>(ot);
        return (*this == o);

    }

    virtual SELF& clear();

    Tuple* clone() const { return new Self(*this); }
    
    void serialize(VirtualByteBuffer & buf) const
    {
        buf << fly_num_ << depDate_ << origin_ << dest_ << gate_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << fly_num_ << depDate_ << origin_ << dest_ << gate_;
    } 
    
    void serialize(NativeByteBuffer & buf) const
    {
        this->serialize<NativeByteBuffer>(buf);
    }

    void serialize(NetworkByteBuffer & buf) const
    {
        this->serialize<NetworkByteBuffer>(buf);
    }
    
    void deserialize(VirtualByteBuffer & buf)
    {
        buf >> fly_num_ >> depDate_ >> origin_ >> dest_ >> gate_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> fly_num_ >> depDate_ >> origin_ >> dest_ >> gate_;
    } 

    void deserialize(NativeByteBuffer & buf)
    {
        this->deserialize<NativeByteBuffer>(buf);
    }    

    void deserialize(NetworkByteBuffer & buf)
    {
        this->deserialize<NetworkByteBuffer>(buf);
    }    

    void serialize(std::ostream & ostr) const;

    void serializeWithPrecision(std::ostream & ostr) const;

    void deserialize(std::istream & istr, bool withSuffix = false);
    
    void deserializeWithNanAndInfs(std::istream & istr, bool withSuffix = false);
    
    size_t hashCode() const
    {
        size_t s = 17;
        s = 37 * s + std::tr1::hash<fly_num_type >()(fly_num_);
        s = 37 * s + std::tr1::hash<depDate_type >()(depDate_);
        s = 37 * s + std::tr1::hash<origin_type >()(origin_);
        s = 37 * s + std::tr1::hash<dest_type >()(dest_);
        s = 37 * s + std::tr1::hash<gate_type >()(gate_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = 0;
           size += fly_num_.getSerializedSize();
   size += depDate_.getSerializedSize();
   size += origin_.getSerializedSize();
   size += dest_.getSerializedSize();
   size += gate_.getSerializedSize();

        return size;

    }
    
    uint32_t getNumberOfAttributes() const 
        { return num_attributes; }

    TupleIterator getBeginIterator() 
        { return TupleIterator(*this, 0); }
    
    ConstTupleIterator getBeginIterator() const 
        { return ConstTupleIterator(*this, 0); }

    TupleIterator getEndIterator() 
        { return TupleIterator(*this, num_attributes); }

    ConstTupleIterator getEndIterator() const 
        { return ConstTupleIterator(*this, num_attributes); }
    
    TupleIterator findAttribute(const std::string & attrb)
    {
        std::tr1::unordered_map<std::string, uint32_t>::const_iterator it = mappings_->nameToIndex_.find(attrb);
        if ( it == mappings_->nameToIndex_.end() ) {
            return this->getEndIterator();
        }
        return TupleIterator(*this, it->second);
    }
    
    ConstTupleIterator findAttribute(const std::string & attrb) const
        { return const_cast<Self*>(this)->findAttribute(attrb); }
    
    TupleAttribute getAttribute(uint32_t index)
    {
        if (index >= num_attributes)
            invalidIndex (index, num_attributes);
        return TupleAttribute(mappings_->indexToName_[index], index, *this);
    }
    
    ConstTupleAttribute getAttribute(uint32_t index) const
        { return const_cast<Self*>(this)->getAttribute(index); }

    ValueHandle getAttributeValue(const std::string & attrb)
        { return getAttributeValueRaw(lookupAttributeName(*mappings_, attrb)->second); }


    ConstValueHandle getAttributeValue(const std::string & attrb) const
        { return const_cast<Self*>(this)->getAttributeValue(attrb); }

    ValueHandle getAttributeValue(uint32_t index) 
        { return getAttributeValueRaw(index); }

    ConstValueHandle getAttributeValue(uint32_t index) const
        { return const_cast<Self*>(this)->getAttributeValue(index); }

    Self & operator=(const Self & ot) 
    { 
        fly_num_ = ot.fly_num_;
        depDate_ = ot.depDate_;
        origin_ = ot.origin_;
        dest_ = ot.dest_;
        gate_ = ot.gate_; 
        assignPayload(ot);
        return *this; 
    }

    Self & operator=(const Tuple & ot) 
    { 
        assignFrom(ot); 
        return *this; 
    }

    void assign(Tuple const & tuple)
    {
        *this = static_cast<SELF const &>(tuple);
    }


    bool operator==(const Self & ot) const 
    {  
       return ( 
                fly_num_ == ot.fly_num_ && 
                depDate_ == ot.depDate_ && 
                origin_ == ot.origin_ && 
                dest_ == ot.dest_ && 
                gate_ == ot.gate_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(fly_num_, ot.fly_num_);
        std::swap(depDate_, ot.depDate_);
        std::swap(origin_, ot.origin_);
        std::swap(dest_, ot.dest_);
        std::swap(gate_, ot.gate_);
      std::swap(payload_, ot.payload_);
    }

    void reset()
    { 
        *this = SELF(); 
    }

    void normalizeBoundedSetsAndMaps(); 

    const std::string & getAttributeName(uint32_t index) const
    {
        if (index >= num_attributes)
            invalidIndex (index, num_attributes);
        return mappings_->indexToName_[index];
    }

    const std::tr1::unordered_map<std::string, uint32_t> & getAttributeNames() const 
        { return mappings_->nameToIndex_; }


protected:

    ValueHandle getAttributeValueRaw(const uint32_t index)
    {
        if (index >= num_attributes)
            invalidIndex(index, num_attributes);
        const TypeOffset & t = mappings_->indexToTypeOffset_[index];
        return ValueHandle((char*)this + t.getOffset(), t.getMetaType(), &t.getTypeId());
    }

private:
    
    fly_num_type fly_num_;
    depDate_type depDate_;
    origin_type origin_;
    dest_type dest_;
    gate_type gate_;

    static TupleMappings* mappings_;
    static TupleMappings* initMappings();
};

inline VirtualByteBuffer & operator>>(VirtualByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline VirtualByteBuffer & operator<<(VirtualByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

template <class BufferType>
inline ByteBuffer<BufferType> & operator>>(ByteBuffer<BufferType> & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
template <class BufferType>
inline ByteBuffer<BufferType> & operator<<(ByteBuffer<BufferType> & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

inline NetworkByteBuffer & operator>>(NetworkByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline NetworkByteBuffer & operator<<(NetworkByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

inline NativeByteBuffer & operator>>(NativeByteBuffer & sbuf, SELF & tuple) 
    { tuple.deserialize(sbuf); return sbuf; }
inline NativeByteBuffer & operator<<(NativeByteBuffer & sbuf, SELF const & tuple) 
    { tuple.serialize(sbuf); return sbuf; }

template<>
inline std::ostream & serializeWithPrecision(std::ostream & ostr, SELF const & tuple) 
    { tuple.serializeWithPrecision(ostr); return ostr; }
inline std::ostream & operator<<(std::ostream & ostr, SELF const & tuple) 
    { tuple.serialize(ostr); return ostr; }
inline std::istream & operator>>(std::istream & istr, SELF & tuple) 
    { tuple.deserialize(istr); return istr; }
template<>
inline void deserializeWithSuffix(std::istream & istr, SELF  & tuple) 
{ tuple.deserialize(istr,true);  }
inline void deserializeWithNanAndInfs(std::istream & istr, SELF  & tuple, bool withSuffix = false) 
{ tuple.deserializeWithNanAndInfs(istr,withSuffix);  }



}  // namespace SPL

namespace std
{
    inline void swap(SPL::SELF & a, SPL::SELF & b)
    {
        a.swap(b);
    }
}

namespace std { 
    namespace tr1 {
        template <>
        struct hash<SPL::SELF> {
            inline size_t operator()(const SPL::SELF & self) const 
                { return self.hashCode(); }
        };
    }
}

#undef SELF
#endif // BEJWRMS02T8UPJM8RZS02T0KTCEKSSS02YY_1KTM_1MKZZJSS0UKTZJB4OBADUUA9_1_H_ 


