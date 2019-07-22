// t9i1ii1js4str1s4str2s4str3s4str4s4str5s4str6s4str7


#ifndef BEJWRSCW0ZMW0ZCO2KS4PMGSTRMDSGEYAGELTMGKGJS0BYRGSAH_H_
#define BEJWRSCW0ZMW0ZCO2KS4PMGSTRMDSGEYAGELTMGKGJS0BYRGSAH_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrscw0zMw0zCo2KS4pMgSTRmDSGEyagElTMGkGJs0ByrgSAh

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::int32 i_type;
    typedef SPL::int32 j_type;
    typedef SPL::rstring str1_type;
    typedef SPL::rstring str2_type;
    typedef SPL::rstring str3_type;
    typedef SPL::rstring str4_type;
    typedef SPL::rstring str5_type;
    typedef SPL::rstring str6_type;
    typedef SPL::rstring str7_type;

    enum { num_attributes = 9 } ;
    
    SELF() : Tuple(), i_(), j_(), str1_(), str2_(), str3_(), str4_(), str5_(), str6_(), str7_() {}
    SELF(const Self & ot) : Tuple(), i_(ot.i_), j_(ot.j_), str1_(ot.str1_), str2_(ot.str2_), str3_(ot.str3_), str4_(ot.str4_), str5_(ot.str5_), str6_(ot.str6_), str7_(ot.str7_) 
      { constructPayload(ot); }
    SELF(const i_type & _i, const j_type & _j, const str1_type & _str1, const str2_type & _str2, const str3_type & _str3, const str4_type & _str4, const str5_type & _str5, const str6_type & _str6, const str7_type & _str7) : Tuple(), i_(_i), j_(_j), str1_(_str1), str2_(_str2), str3_(_str3), str4_(_str4), str5_(_str5), str6_(_str6), str7_(_str7) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    i_type & get_i() { return i_; }
    const i_type & get_i() const { return i_; }
    void set_i(const i_type & _i) { i_ = _i; }
    j_type & get_j() { return j_; }
    const j_type & get_j() const { return j_; }
    void set_j(const j_type & _j) { j_ = _j; }
    str1_type & get_str1() { return str1_; }
    const str1_type & get_str1() const { return str1_; }
    void set_str1(const str1_type & _str1) { str1_ = _str1; }
    str2_type & get_str2() { return str2_; }
    const str2_type & get_str2() const { return str2_; }
    void set_str2(const str2_type & _str2) { str2_ = _str2; }
    str3_type & get_str3() { return str3_; }
    const str3_type & get_str3() const { return str3_; }
    void set_str3(const str3_type & _str3) { str3_ = _str3; }
    str4_type & get_str4() { return str4_; }
    const str4_type & get_str4() const { return str4_; }
    void set_str4(const str4_type & _str4) { str4_ = _str4; }
    str5_type & get_str5() { return str5_; }
    const str5_type & get_str5() const { return str5_; }
    void set_str5(const str5_type & _str5) { str5_ = _str5; }
    str6_type & get_str6() { return str6_; }
    const str6_type & get_str6() const { return str6_; }
    void set_str6(const str6_type & _str6) { str6_ = _str6; }
    str7_type & get_str7() { return str7_; }
    const str7_type & get_str7() const { return str7_; }
    void set_str7(const str7_type & _str7) { str7_ = _str7; }
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
        buf << i_ << j_ << str1_ << str2_ << str3_ << str4_ << str5_ << str6_ << str7_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << i_ << j_ << str1_ << str2_ << str3_ << str4_ << str5_ << str6_ << str7_;
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
        buf >> i_ >> j_ >> str1_ >> str2_ >> str3_ >> str4_ >> str5_ >> str6_ >> str7_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> i_ >> j_ >> str1_ >> str2_ >> str3_ >> str4_ >> str5_ >> str6_ >> str7_;
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
        s = 37 * s + std::tr1::hash<i_type >()(i_);
        s = 37 * s + std::tr1::hash<j_type >()(j_);
        s = 37 * s + std::tr1::hash<str1_type >()(str1_);
        s = 37 * s + std::tr1::hash<str2_type >()(str2_);
        s = 37 * s + std::tr1::hash<str3_type >()(str3_);
        s = 37 * s + std::tr1::hash<str4_type >()(str4_);
        s = 37 * s + std::tr1::hash<str5_type >()(str5_);
        s = 37 * s + std::tr1::hash<str6_type >()(str6_);
        s = 37 * s + std::tr1::hash<str7_type >()(str7_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::int32)+sizeof(SPL::int32);
           size += str1_.getSerializedSize();
   size += str2_.getSerializedSize();
   size += str3_.getSerializedSize();
   size += str4_.getSerializedSize();
   size += str5_.getSerializedSize();
   size += str6_.getSerializedSize();
   size += str7_.getSerializedSize();

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
        i_ = ot.i_;
        j_ = ot.j_;
        str1_ = ot.str1_;
        str2_ = ot.str2_;
        str3_ = ot.str3_;
        str4_ = ot.str4_;
        str5_ = ot.str5_;
        str6_ = ot.str6_;
        str7_ = ot.str7_; 
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
                i_ == ot.i_ && 
                j_ == ot.j_ && 
                str1_ == ot.str1_ && 
                str2_ == ot.str2_ && 
                str3_ == ot.str3_ && 
                str4_ == ot.str4_ && 
                str5_ == ot.str5_ && 
                str6_ == ot.str6_ && 
                str7_ == ot.str7_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(i_, ot.i_);
        std::swap(j_, ot.j_);
        std::swap(str1_, ot.str1_);
        std::swap(str2_, ot.str2_);
        std::swap(str3_, ot.str3_);
        std::swap(str4_, ot.str4_);
        std::swap(str5_, ot.str5_);
        std::swap(str6_, ot.str6_);
        std::swap(str7_, ot.str7_);
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
    
    i_type i_;
    j_type j_;
    str1_type str1_;
    str2_type str2_;
    str3_type str3_;
    str4_type str4_;
    str5_type str5_;
    str6_type str6_;
    str7_type str7_;

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
#endif // BEJWRSCW0ZMW0ZCO2KS4PMGSTRMDSGEYAGELTMGKGJS0BYRGSAH_H_ 


