// t9u2ids8customers4dates7productu8quantityu10product_ids11productNamef5priceu9quantity2


#ifndef BEJWRSSW1YKWPTKGULS7JZ00TKJZJSSXJLTYVKMPPKU0UKBUOLE3MK8KSQSW1NICKXQPVGXPCOX6JUALPPGVFMCMPPZYWTUYAUGAHDC_H_
#define BEJWRSSW1YKWPTKGULS7JZ00TKJZJSSXJLTYVKMPPKU0UKBUOLE3MK8KSQSW1NICKXQPVGXPCOX6JUALPPGVFMCMPPZYWTUYAUGAHDC_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrsSw1ykwptkguLS7Jz00tKjZJSSxJLTYvKMpPKU0uKbUoLE3MK8ksqSw1NICKxQPVGxpCOX6JualppgVFmcmppZYwtUYAugAhDC

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::uint32 id_type;
    typedef SPL::rstring customer_type;
    typedef SPL::rstring date_type;
    typedef SPL::rstring product_type;
    typedef SPL::uint32 quantity_type;
    typedef SPL::uint32 product_id_type;
    typedef SPL::rstring productName_type;
    typedef SPL::float32 price_type;
    typedef SPL::uint32 quantity2_type;

    enum { num_attributes = 9 } ;
    
    SELF() : Tuple(), id_(), customer_(), date_(), product_(), quantity_(), product_id_(), productName_(), price_(), quantity2_() {}
    SELF(const Self & ot) : Tuple(), id_(ot.id_), customer_(ot.customer_), date_(ot.date_), product_(ot.product_), quantity_(ot.quantity_), product_id_(ot.product_id_), productName_(ot.productName_), price_(ot.price_), quantity2_(ot.quantity2_) 
      { constructPayload(ot); }
    SELF(const id_type & _id, const customer_type & _customer, const date_type & _date, const product_type & _product, const quantity_type & _quantity, const product_id_type & _product_id, const productName_type & _productName, const price_type & _price, const quantity2_type & _quantity2) : Tuple(), id_(_id), customer_(_customer), date_(_date), product_(_product), quantity_(_quantity), product_id_(_product_id), productName_(_productName), price_(_price), quantity2_(_quantity2) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    id_type & get_id() { return id_; }
    const id_type & get_id() const { return id_; }
    void set_id(const id_type & _id) { id_ = _id; }
    customer_type & get_customer() { return customer_; }
    const customer_type & get_customer() const { return customer_; }
    void set_customer(const customer_type & _customer) { customer_ = _customer; }
    date_type & get_date() { return date_; }
    const date_type & get_date() const { return date_; }
    void set_date(const date_type & _date) { date_ = _date; }
    product_type & get_product() { return product_; }
    const product_type & get_product() const { return product_; }
    void set_product(const product_type & _product) { product_ = _product; }
    quantity_type & get_quantity() { return quantity_; }
    const quantity_type & get_quantity() const { return quantity_; }
    void set_quantity(const quantity_type & _quantity) { quantity_ = _quantity; }
    product_id_type & get_product_id() { return product_id_; }
    const product_id_type & get_product_id() const { return product_id_; }
    void set_product_id(const product_id_type & _product_id) { product_id_ = _product_id; }
    productName_type & get_productName() { return productName_; }
    const productName_type & get_productName() const { return productName_; }
    void set_productName(const productName_type & _productName) { productName_ = _productName; }
    price_type & get_price() { return price_; }
    const price_type & get_price() const { return price_; }
    void set_price(const price_type & _price) { price_ = _price; }
    quantity2_type & get_quantity2() { return quantity2_; }
    const quantity2_type & get_quantity2() const { return quantity2_; }
    void set_quantity2(const quantity2_type & _quantity2) { quantity2_ = _quantity2; }
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
        buf << id_ << customer_ << date_ << product_ << quantity_ << product_id_ << productName_ << price_ << quantity2_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << id_ << customer_ << date_ << product_ << quantity_ << product_id_ << productName_ << price_ << quantity2_;
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
        buf >> id_ >> customer_ >> date_ >> product_ >> quantity_ >> product_id_ >> productName_ >> price_ >> quantity2_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> id_ >> customer_ >> date_ >> product_ >> quantity_ >> product_id_ >> productName_ >> price_ >> quantity2_;
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
        s = 37 * s + std::tr1::hash<id_type >()(id_);
        s = 37 * s + std::tr1::hash<customer_type >()(customer_);
        s = 37 * s + std::tr1::hash<date_type >()(date_);
        s = 37 * s + std::tr1::hash<product_type >()(product_);
        s = 37 * s + std::tr1::hash<quantity_type >()(quantity_);
        s = 37 * s + std::tr1::hash<product_id_type >()(product_id_);
        s = 37 * s + std::tr1::hash<productName_type >()(productName_);
        s = 37 * s + std::tr1::hash<price_type >()(price_);
        s = 37 * s + std::tr1::hash<quantity2_type >()(quantity2_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::uint32)+sizeof(SPL::uint32)+sizeof(SPL::uint32)+sizeof(SPL::float32)+sizeof(SPL::uint32);
           size += customer_.getSerializedSize();
   size += date_.getSerializedSize();
   size += product_.getSerializedSize();
   size += productName_.getSerializedSize();

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
        id_ = ot.id_;
        customer_ = ot.customer_;
        date_ = ot.date_;
        product_ = ot.product_;
        quantity_ = ot.quantity_;
        product_id_ = ot.product_id_;
        productName_ = ot.productName_;
        price_ = ot.price_;
        quantity2_ = ot.quantity2_; 
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
                id_ == ot.id_ && 
                customer_ == ot.customer_ && 
                date_ == ot.date_ && 
                product_ == ot.product_ && 
                quantity_ == ot.quantity_ && 
                product_id_ == ot.product_id_ && 
                productName_ == ot.productName_ && 
                price_ == ot.price_ && 
                quantity2_ == ot.quantity2_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(id_, ot.id_);
        std::swap(customer_, ot.customer_);
        std::swap(date_, ot.date_);
        std::swap(product_, ot.product_);
        std::swap(quantity_, ot.quantity_);
        std::swap(product_id_, ot.product_id_);
        std::swap(productName_, ot.productName_);
        std::swap(price_, ot.price_);
        std::swap(quantity2_, ot.quantity2_);
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
    
    id_type id_;
    customer_type customer_;
    date_type date_;
    product_type product_;
    quantity_type quantity_;
    product_id_type product_id_;
    productName_type productName_;
    price_type price_;
    quantity2_type quantity2_;

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
#endif // BEJWRSSW1YKWPTKGULS7JZ00TKJZJSSXJLTYVKMPPKU0UKBUOLE3MK8KSQSW1NICKXQPVGXPCOX6JUALPPGVFMCMPPZYWTUYAUGAHDC_H_ 


