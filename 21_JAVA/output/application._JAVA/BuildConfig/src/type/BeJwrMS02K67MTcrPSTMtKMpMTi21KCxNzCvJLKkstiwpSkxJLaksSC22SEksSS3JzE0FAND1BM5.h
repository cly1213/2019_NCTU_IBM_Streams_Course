// t5s6symbolf5priceu8quantitys9tradetypes8datetime


#ifndef BEJWRMS02K67MTCRPSTMTKMPMTI21KCXNZCVJLKKSTIWPSKXJLAKSSC22SEKSSS3JZE0FAND1BM5_H_
#define BEJWRMS02K67MTCRPSTMTKMPMTI21KCXNZCVJLKKSTIWPSKXJLAKSSC22SEKSSS3JZE0FAND1BM5_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrMS02K67MTcrPSTMtKMpMTi21KCxNzCvJLKkstiwpSkxJLaksSC22SEksSS3JzE0FAND1BM5

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::rstring symbol_type;
    typedef SPL::float32 price_type;
    typedef SPL::uint32 quantity_type;
    typedef SPL::rstring tradetype_type;
    typedef SPL::rstring datetime_type;

    enum { num_attributes = 5 } ;
    
    SELF() : Tuple(), symbol_(), price_(), quantity_(), tradetype_(), datetime_() {}
    SELF(const Self & ot) : Tuple(), symbol_(ot.symbol_), price_(ot.price_), quantity_(ot.quantity_), tradetype_(ot.tradetype_), datetime_(ot.datetime_) 
      { constructPayload(ot); }
    SELF(const symbol_type & _symbol, const price_type & _price, const quantity_type & _quantity, const tradetype_type & _tradetype, const datetime_type & _datetime) : Tuple(), symbol_(_symbol), price_(_price), quantity_(_quantity), tradetype_(_tradetype), datetime_(_datetime) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    symbol_type & get_symbol() { return symbol_; }
    const symbol_type & get_symbol() const { return symbol_; }
    void set_symbol(const symbol_type & _symbol) { symbol_ = _symbol; }
    price_type & get_price() { return price_; }
    const price_type & get_price() const { return price_; }
    void set_price(const price_type & _price) { price_ = _price; }
    quantity_type & get_quantity() { return quantity_; }
    const quantity_type & get_quantity() const { return quantity_; }
    void set_quantity(const quantity_type & _quantity) { quantity_ = _quantity; }
    tradetype_type & get_tradetype() { return tradetype_; }
    const tradetype_type & get_tradetype() const { return tradetype_; }
    void set_tradetype(const tradetype_type & _tradetype) { tradetype_ = _tradetype; }
    datetime_type & get_datetime() { return datetime_; }
    const datetime_type & get_datetime() const { return datetime_; }
    void set_datetime(const datetime_type & _datetime) { datetime_ = _datetime; }
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
        buf << symbol_ << price_ << quantity_ << tradetype_ << datetime_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << symbol_ << price_ << quantity_ << tradetype_ << datetime_;
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
        buf >> symbol_ >> price_ >> quantity_ >> tradetype_ >> datetime_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> symbol_ >> price_ >> quantity_ >> tradetype_ >> datetime_;
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
        s = 37 * s + std::tr1::hash<symbol_type >()(symbol_);
        s = 37 * s + std::tr1::hash<price_type >()(price_);
        s = 37 * s + std::tr1::hash<quantity_type >()(quantity_);
        s = 37 * s + std::tr1::hash<tradetype_type >()(tradetype_);
        s = 37 * s + std::tr1::hash<datetime_type >()(datetime_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::float32)+sizeof(SPL::uint32);
           size += symbol_.getSerializedSize();
   size += tradetype_.getSerializedSize();
   size += datetime_.getSerializedSize();

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
        symbol_ = ot.symbol_;
        price_ = ot.price_;
        quantity_ = ot.quantity_;
        tradetype_ = ot.tradetype_;
        datetime_ = ot.datetime_; 
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
                symbol_ == ot.symbol_ && 
                price_ == ot.price_ && 
                quantity_ == ot.quantity_ && 
                tradetype_ == ot.tradetype_ && 
                datetime_ == ot.datetime_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(symbol_, ot.symbol_);
        std::swap(price_, ot.price_);
        std::swap(quantity_, ot.quantity_);
        std::swap(tradetype_, ot.tradetype_);
        std::swap(datetime_, ot.datetime_);
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
    
    symbol_type symbol_;
    price_type price_;
    quantity_type quantity_;
    tradetype_type tradetype_;
    datetime_type datetime_;

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
#endif // BEJWRMS02K67MTCRPSTMTKMPMTI21KCXNZCVJLKKSTIWPSKXJLAKSSC22SEKSSS3JZE0FAND1BM5_H_ 


