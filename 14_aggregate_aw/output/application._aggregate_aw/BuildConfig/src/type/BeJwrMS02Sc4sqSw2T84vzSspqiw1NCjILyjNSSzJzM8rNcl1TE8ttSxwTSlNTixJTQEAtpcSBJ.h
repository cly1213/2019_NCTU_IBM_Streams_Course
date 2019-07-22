// t5s4citys7countryu10populationu4mAgeu9pEducated


#ifndef BEJWRMS02SC4SQSW2T84VZSSPQIW1NCJILYJNSSZJZM8RNCL1TE8TTSXWTSLNTIXJTQEATPCSBJ_H_
#define BEJWRMS02SC4SQSW2T84VZSSPQIW1NCJILYJNSSZJZM8RNCL1TE8TTSXWTSLNTIXJTQEATPCSBJ_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrMS02Sc4sqSw2T84vzSspqiw1NCjILyjNSSzJzM8rNcl1TE8ttSxwTSlNTixJTQEAtpcSBJ

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::rstring city_type;
    typedef SPL::rstring country_type;
    typedef SPL::uint32 population_type;
    typedef SPL::uint32 mAge_type;
    typedef SPL::uint32 pEducated_type;

    enum { num_attributes = 5 } ;
    
    SELF() : Tuple(), city_(), country_(), population_(), mAge_(), pEducated_() {}
    SELF(const Self & ot) : Tuple(), city_(ot.city_), country_(ot.country_), population_(ot.population_), mAge_(ot.mAge_), pEducated_(ot.pEducated_) 
      { constructPayload(ot); }
    SELF(const city_type & _city, const country_type & _country, const population_type & _population, const mAge_type & _mAge, const pEducated_type & _pEducated) : Tuple(), city_(_city), country_(_country), population_(_population), mAge_(_mAge), pEducated_(_pEducated) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    city_type & get_city() { return city_; }
    const city_type & get_city() const { return city_; }
    void set_city(const city_type & _city) { city_ = _city; }
    country_type & get_country() { return country_; }
    const country_type & get_country() const { return country_; }
    void set_country(const country_type & _country) { country_ = _country; }
    population_type & get_population() { return population_; }
    const population_type & get_population() const { return population_; }
    void set_population(const population_type & _population) { population_ = _population; }
    mAge_type & get_mAge() { return mAge_; }
    const mAge_type & get_mAge() const { return mAge_; }
    void set_mAge(const mAge_type & _mAge) { mAge_ = _mAge; }
    pEducated_type & get_pEducated() { return pEducated_; }
    const pEducated_type & get_pEducated() const { return pEducated_; }
    void set_pEducated(const pEducated_type & _pEducated) { pEducated_ = _pEducated; }
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
        buf << city_ << country_ << population_ << mAge_ << pEducated_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << city_ << country_ << population_ << mAge_ << pEducated_;
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
        buf >> city_ >> country_ >> population_ >> mAge_ >> pEducated_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> city_ >> country_ >> population_ >> mAge_ >> pEducated_;
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
        s = 37 * s + std::tr1::hash<city_type >()(city_);
        s = 37 * s + std::tr1::hash<country_type >()(country_);
        s = 37 * s + std::tr1::hash<population_type >()(population_);
        s = 37 * s + std::tr1::hash<mAge_type >()(mAge_);
        s = 37 * s + std::tr1::hash<pEducated_type >()(pEducated_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::uint32)+sizeof(SPL::uint32)+sizeof(SPL::uint32);
           size += city_.getSerializedSize();
   size += country_.getSerializedSize();

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
        city_ = ot.city_;
        country_ = ot.country_;
        population_ = ot.population_;
        mAge_ = ot.mAge_;
        pEducated_ = ot.pEducated_; 
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
                city_ == ot.city_ && 
                country_ == ot.country_ && 
                population_ == ot.population_ && 
                mAge_ == ot.mAge_ && 
                pEducated_ == ot.pEducated_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(city_, ot.city_);
        std::swap(country_, ot.country_);
        std::swap(population_, ot.population_);
        std::swap(mAge_, ot.mAge_);
        std::swap(pEducated_, ot.pEducated_);
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
    
    city_type city_;
    country_type country_;
    population_type population_;
    mAge_type mAge_;
    pEducated_type pEducated_;

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
#endif // BEJWRMS02SC4SQSW2T84VZSSPQIW1NCJILYJNSSZJZM8RNCL1TE8TTSXWTSLNTIXJTQEATPCSBJ_H_ 


