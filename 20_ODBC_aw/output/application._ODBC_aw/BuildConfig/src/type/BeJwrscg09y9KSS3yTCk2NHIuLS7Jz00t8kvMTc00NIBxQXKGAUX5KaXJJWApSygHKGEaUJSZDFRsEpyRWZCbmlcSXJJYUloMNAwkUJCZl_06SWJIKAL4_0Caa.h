// t8i7OrderIds12CustomerNamei10CustomerIds11ProductNamei9ProductIds5Pricei14ShipmentStatuss12ShippingDate


#ifndef BEJWRSCG09Y9KSS3YTCK2NHIULS7JZ00T8KVMTC00NIBXQXKGAUX5KAXJJWAPSYGHKGEAUJSZDFRSEPYRWZCBMLCSXJJYULOMNAWKUJCZL_06SWJIKAL4_0CAA_H_
#define BEJWRSCG09Y9KSS3YTCK2NHIULS7JZ00T8KVMTC00NIBXQXKGAUX5KAXJJWAPSYGHKGEAUJSZDFRSEPYRWZCBMLCSXJJYULOMNAWKUJCZL_06SWJIKAL4_0CAA_H_

#include <SPL/Runtime/Type/Tuple.h>
#include <SPL/Runtime/Type/PrimitiveType.h>
#include <SPL/Runtime/Type/CollectionType.h>
#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Serialization/NativeByteBuffer.h>
#include <SPL/Runtime/Serialization/VirtualByteBuffer.h>
#include <SPL/Runtime/Type/Optional.h>



#define SELF BeJwrscg09y9KSS3yTCk2NHIuLS7Jz00t8kvMTc00NIBxQXKGAUX5KaXJJWApSygHKGEaUJSZDFRsEpyRWZCbmlcSXJJYUloMNAwkUJCZl_06SWJIKAL4_0Caa

namespace SPL {

class SELF : public Tuple
{
public:
    static const bool facade = false;

    typedef SELF Self;
    
    typedef SPL::int32 OrderId_type;
    typedef SPL::rstring CustomerName_type;
    typedef SPL::int32 CustomerId_type;
    typedef SPL::rstring ProductName_type;
    typedef SPL::int32 ProductId_type;
    typedef SPL::rstring Price_type;
    typedef SPL::int32 ShipmentStatus_type;
    typedef SPL::rstring ShippingDate_type;

    enum { num_attributes = 8 } ;
    
    SELF() : Tuple(), OrderId_(), CustomerName_(), CustomerId_(), ProductName_(), ProductId_(), Price_(), ShipmentStatus_(), ShippingDate_() {}
    SELF(const Self & ot) : Tuple(), OrderId_(ot.OrderId_), CustomerName_(ot.CustomerName_), CustomerId_(ot.CustomerId_), ProductName_(ot.ProductName_), ProductId_(ot.ProductId_), Price_(ot.Price_), ShipmentStatus_(ot.ShipmentStatus_), ShippingDate_(ot.ShippingDate_) 
      { constructPayload(ot); }
    SELF(const OrderId_type & _OrderId, const CustomerName_type & _CustomerName, const CustomerId_type & _CustomerId, const ProductName_type & _ProductName, const ProductId_type & _ProductId, const Price_type & _Price, const ShipmentStatus_type & _ShipmentStatus, const ShippingDate_type & _ShippingDate) : Tuple(), OrderId_(_OrderId), CustomerName_(_CustomerName), CustomerId_(_CustomerId), ProductName_(_ProductName), ProductId_(_ProductId), Price_(_Price), ShipmentStatus_(_ShipmentStatus), ShippingDate_(_ShippingDate) { }
    
    SELF(const Tuple & ot, bool typesafe = true) : Tuple() { assignFrom(ot, typesafe); }
    SELF(const ConstValueHandle & ot) : Tuple() { const Tuple & o = ot; assignFrom(o); }

    virtual ~SELF() {}
    
    OrderId_type & get_OrderId() { return OrderId_; }
    const OrderId_type & get_OrderId() const { return OrderId_; }
    void set_OrderId(const OrderId_type & _OrderId) { OrderId_ = _OrderId; }
    CustomerName_type & get_CustomerName() { return CustomerName_; }
    const CustomerName_type & get_CustomerName() const { return CustomerName_; }
    void set_CustomerName(const CustomerName_type & _CustomerName) { CustomerName_ = _CustomerName; }
    CustomerId_type & get_CustomerId() { return CustomerId_; }
    const CustomerId_type & get_CustomerId() const { return CustomerId_; }
    void set_CustomerId(const CustomerId_type & _CustomerId) { CustomerId_ = _CustomerId; }
    ProductName_type & get_ProductName() { return ProductName_; }
    const ProductName_type & get_ProductName() const { return ProductName_; }
    void set_ProductName(const ProductName_type & _ProductName) { ProductName_ = _ProductName; }
    ProductId_type & get_ProductId() { return ProductId_; }
    const ProductId_type & get_ProductId() const { return ProductId_; }
    void set_ProductId(const ProductId_type & _ProductId) { ProductId_ = _ProductId; }
    Price_type & get_Price() { return Price_; }
    const Price_type & get_Price() const { return Price_; }
    void set_Price(const Price_type & _Price) { Price_ = _Price; }
    ShipmentStatus_type & get_ShipmentStatus() { return ShipmentStatus_; }
    const ShipmentStatus_type & get_ShipmentStatus() const { return ShipmentStatus_; }
    void set_ShipmentStatus(const ShipmentStatus_type & _ShipmentStatus) { ShipmentStatus_ = _ShipmentStatus; }
    ShippingDate_type & get_ShippingDate() { return ShippingDate_; }
    const ShippingDate_type & get_ShippingDate() const { return ShippingDate_; }
    void set_ShippingDate(const ShippingDate_type & _ShippingDate) { ShippingDate_ = _ShippingDate; }
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
        buf << OrderId_ << CustomerName_ << CustomerId_ << ProductName_ << ProductId_ << Price_ << ShipmentStatus_ << ShippingDate_;
    }

    template <class BufferType>
    void serialize(ByteBuffer<BufferType> & buf) const
    {        
        buf << OrderId_ << CustomerName_ << CustomerId_ << ProductName_ << ProductId_ << Price_ << ShipmentStatus_ << ShippingDate_;
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
        buf >> OrderId_ >> CustomerName_ >> CustomerId_ >> ProductName_ >> ProductId_ >> Price_ >> ShipmentStatus_ >> ShippingDate_;
    }

    template <class BufferType>
    void deserialize(ByteBuffer<BufferType> & buf)
    {        
        buf >> OrderId_ >> CustomerName_ >> CustomerId_ >> ProductName_ >> ProductId_ >> Price_ >> ShipmentStatus_ >> ShippingDate_;
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
        s = 37 * s + std::tr1::hash<OrderId_type >()(OrderId_);
        s = 37 * s + std::tr1::hash<CustomerName_type >()(CustomerName_);
        s = 37 * s + std::tr1::hash<CustomerId_type >()(CustomerId_);
        s = 37 * s + std::tr1::hash<ProductName_type >()(ProductName_);
        s = 37 * s + std::tr1::hash<ProductId_type >()(ProductId_);
        s = 37 * s + std::tr1::hash<Price_type >()(Price_);
        s = 37 * s + std::tr1::hash<ShipmentStatus_type >()(ShipmentStatus_);
        s = 37 * s + std::tr1::hash<ShippingDate_type >()(ShippingDate_);
        return s;
    }
    
    size_t getSerializedSize() const
    {
        size_t size = sizeof(SPL::int32)+sizeof(SPL::int32)+sizeof(SPL::int32)+sizeof(SPL::int32);
           size += CustomerName_.getSerializedSize();
   size += ProductName_.getSerializedSize();
   size += Price_.getSerializedSize();
   size += ShippingDate_.getSerializedSize();

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
        OrderId_ = ot.OrderId_;
        CustomerName_ = ot.CustomerName_;
        CustomerId_ = ot.CustomerId_;
        ProductName_ = ot.ProductName_;
        ProductId_ = ot.ProductId_;
        Price_ = ot.Price_;
        ShipmentStatus_ = ot.ShipmentStatus_;
        ShippingDate_ = ot.ShippingDate_; 
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
                OrderId_ == ot.OrderId_ && 
                CustomerName_ == ot.CustomerName_ && 
                CustomerId_ == ot.CustomerId_ && 
                ProductName_ == ot.ProductName_ && 
                ProductId_ == ot.ProductId_ && 
                Price_ == ot.Price_ && 
                ShipmentStatus_ == ot.ShipmentStatus_ && 
                ShippingDate_ == ot.ShippingDate_  
              ); 
    }
    bool operator==(const Tuple & ot) const { return equals(ot); }

    bool operator!=(const Self & ot) const { return !(*this == ot); }
    bool operator!=(const Tuple & ot) const { return !(*this == ot); }


    void swap(SELF & ot) 
    { 
        std::swap(OrderId_, ot.OrderId_);
        std::swap(CustomerName_, ot.CustomerName_);
        std::swap(CustomerId_, ot.CustomerId_);
        std::swap(ProductName_, ot.ProductName_);
        std::swap(ProductId_, ot.ProductId_);
        std::swap(Price_, ot.Price_);
        std::swap(ShipmentStatus_, ot.ShipmentStatus_);
        std::swap(ShippingDate_, ot.ShippingDate_);
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
    
    OrderId_type OrderId_;
    CustomerName_type CustomerName_;
    CustomerId_type CustomerId_;
    ProductName_type ProductName_;
    ProductId_type ProductId_;
    Price_type Price_;
    ShipmentStatus_type ShipmentStatus_;
    ShippingDate_type ShippingDate_;

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
#endif // BEJWRSCG09Y9KSS3YTCK2NHIULS7JZ00T8KVMTC00NIBXQXKGAUX5KAXJJWAPSYGHKGEAUJSZDFRSEPYRWZCBMLCSXJJYULOMNAWKUJCZL_06SWJIKAL4_0CAA_H_ 


