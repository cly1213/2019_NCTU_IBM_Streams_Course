// t4u13maxPopulationu7maxMAgeu7minMAgeu12minpEducated


#ifndef BEJWRMSK1NM5NRAJILYJNSSZJZM8RNQDYFR3TU4GMZDWWW9AIYCPWTSLNTIXJTQEA8PUTA0_H_
#define BEJWRMSK1NM5NRAJILYJNSSZJZM8RNQDYFR3TU4GMZDWWW9AIYCPWTSLNTIXJTQEA8PUTA0_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::uint32 maxPopulation_type;
    typedef SPL::uint32 maxMAge_type;
    typedef SPL::uint32 minMAge_type;
    typedef SPL::uint32 minpEducated_type;

    enum { num_attributes = 4 } ;
    
    SELF() : Tuple(), maxPopulation_(), maxMAge_(), minMAge_(), minpEducated_() {}
    SELF(const Self & ot) : Tuple(), maxPopulation_(ot.maxPopulation_), maxMAge_(ot.maxMAge_), minMAge_(ot.minMAge_), minpEducated_(ot.minpEducated_) 
      { constructPayload(ot); }
    SELF(const maxPopulation_type & _maxPopulation, const maxMAge_type & _maxMAge, const minMAge_type & _minMAge, const minpEducated_type & _minpEducated) : Tuple(), maxPopulation_(_maxPopulation), maxMAge_(_maxMAge), minMAge_(_minMAge), minpEducated_(_minpEducated) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    maxPopulation_type & get_maxPopulation() { return maxPopulation_; }
    const maxPopulation_type & get_maxPopulation() const { return maxPopulation_; }
    void set_maxPopulation(const maxPopulation_type & _maxPopulation) { maxPopulation_ = _maxPopulation; }
    maxMAge_type & get_maxMAge() { return maxMAge_; }
    const maxMAge_type & get_maxMAge() const { return maxMAge_; }
    void set_maxMAge(const maxMAge_type & _maxMAge) { maxMAge_ = _maxMAge; }
    minMAge_type & get_minMAge() { return minMAge_; }
    const minMAge_type & get_minMAge() const { return minMAge_; }
    void set_minMAge(const minMAge_type & _minMAge) { minMAge_ = _minMAge; }
    minpEducated_type & get_minpEducated() { return minpEducated_; }
    const minpEducated_type & get_minpEducated() const { return minpEducated_; }
    void set_minpEducated(const minpEducated_type & _minpEducated) { minpEducated_ = _minpEducated; }
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
        buf << maxPopulation_ << maxMAge_ << minMAge_ << minpEducated_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << maxPopulation_ << maxMAge_ << minMAge_ << minpEducated_;
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
        buf >> maxPopulation_ >> maxMAge_ >> minMAge_ >> minpEducated_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> maxPopulation_ >> maxMAge_ >> minMAge_ >> minpEducated_;
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
        s = 37 * s + std::tr1::hash<maxPopulation_type >()(maxPopulation_);
        s = 37 * s + std::tr1::hash<maxMAge_type >()(maxMAge_);
        s = 37 * s + std::tr1::hash<minMAge_type >()(minMAge_);
        s = 37 * s + std::tr1::hash<minpEducated_type >()(minpEducated_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::uint32)+sizeof(SPL::uint32)+sizeof(SPL::uint32)+sizeof(SPL::uint32);
        
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
        maxPopulation_ = ot.maxPopulation_;
        maxMAge_ = ot.maxMAge_;
        minMAge_ = ot.minMAge_;
        minpEducated_ = ot.minpEducated_; 
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
                maxPopulation_ == ot.maxPopulation_ && 
                maxMAge_ == ot.maxMAge_ && 
                minMAge_ == ot.minMAge_ && 
                minpEducated_ == ot.minpEducated_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(maxPopulation_, ot.maxPopulation_);
        std::swap(maxMAge_, ot.maxMAge_);
        std::swap(minMAge_, ot.minMAge_);
        std::swap(minpEducated_, ot.minpEducated_);
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
    
    maxPopulation_type maxPopulation_;
    maxMAge_type maxMAge_;
    minMAge_type minMAge_;
    minpEducated_type minpEducated_;

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
#endif // BEJWRMSK1NM5NRAJILYJNSSZJZM8RNQDYFR3TU4GMZDWWW9AIYCPWTSLNTIXJTQEA8PUTA0_H_ 


