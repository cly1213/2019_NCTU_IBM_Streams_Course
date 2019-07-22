// t4u13maxPopulationu7maxMAgeu7minMAgeu12minpEducated


#include "BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0.h"
#include <sstream>

#define SELF BeJwrMSk1NM5NrAjILyjNSSzJzM8rNQdyfR3TU4GMzDwww9AIyCpwTSlNTixJTQEA8PUTA0

using namespace SPL;

TupleMappings* SELF::mappings_ = SELF::initMappings();

static void addMapping(TupleMappings & tm, TypeOffset & offset,
                       std::string const & name, uint32_t index)
{
    tm.nameToIndex_.insert(std::make_pair(name, index)); 
    tm.indexToName_.push_back(name);
    tm.indexToTypeOffset_.push_back(offset);    
}

static Tuple * initer() { return new SELF(); }

TupleMappings* SELF::initMappings()
{
    instantiators_.insert(std::make_pair("tuple<uint32 maxPopulation,uint32 maxMAge,uint32 minMAge,uint32 minpEducated>",&initer));
    TupleMappings * tm = new TupleMappings();
#define MY_OFFSETOF(member, base) \
    ((uintptr_t)&reinterpret_cast<Self*>(base)->member) - (uintptr_t)base
   
    // initialize the mappings 
    
    {
        std::string s("maxPopulation");
        TypeOffset t(MY_OFFSETOF(maxPopulation_, tm), 
                     Meta::Type::typeOf<SPL::uint32 >(), 
                     &typeid(SPL::uint32));
        addMapping(*tm, t, s, 0);
    }
    
    {
        std::string s("maxMAge");
        TypeOffset t(MY_OFFSETOF(maxMAge_, tm), 
                     Meta::Type::typeOf<SPL::uint32 >(), 
                     &typeid(SPL::uint32));
        addMapping(*tm, t, s, 1);
    }
    
    {
        std::string s("minMAge");
        TypeOffset t(MY_OFFSETOF(minMAge_, tm), 
                     Meta::Type::typeOf<SPL::uint32 >(), 
                     &typeid(SPL::uint32));
        addMapping(*tm, t, s, 2);
    }
    
    {
        std::string s("minpEducated");
        TypeOffset t(MY_OFFSETOF(minpEducated_, tm), 
                     Meta::Type::typeOf<SPL::uint32 >(), 
                     &typeid(SPL::uint32));
        addMapping(*tm, t, s, 3);
    }
    
    return tm;
}

void SELF::deserialize(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "maxPopulation") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, maxPopulation_);
   else
     istr >> maxPopulation_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "maxMAge") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, maxMAge_);
   else
     istr >> maxMAge_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "minMAge") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, minMAge_);
   else
     istr >> minMAge_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "minpEducated") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   if (withSuffix)
     SPL::deserializeWithSuffix(istr, minpEducated_);
   else
     istr >> minpEducated_;
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::deserializeWithNanAndInfs(std::istream & istr, bool withSuffix)
{
   std::string s;
   char c;

   istr >> c; if (!istr) { return; }
   if (c != '{') { istr.setstate(std::ios_base::failbit); return; }
   
   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "maxPopulation") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, maxPopulation_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "maxMAge") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, maxMAge_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "minMAge") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, minMAge_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   if (c != ',') { istr.setstate(std::ios_base::failbit); return; }

   if (!readAttributeIdentifier(istr, s)) { return; }
   if (s != "minpEducated") { istr.setstate(std::ios_base::failbit); return; }
   istr >> c; if (!istr) { return; }
   if (c != '=') { istr.setstate(std::ios_base::failbit); return; }
   SPL::deserializeWithNanAndInfs(istr, minpEducated_, withSuffix);
   if (!istr) { return; }  
   istr >> c; if (!istr) { return; }
   
   if (c != '}') { istr.setstate(std::ios_base::failbit); return; }
}

void SELF::serialize(std::ostream & ostr) const
{
    ostr << '{'
         << "maxPopulation=" << get_maxPopulation()  << ","
         << "maxMAge=" << get_maxMAge()  << ","
         << "minMAge=" << get_minMAge()  << ","
         << "minpEducated=" << get_minpEducated()  
         << '}';
}

void SELF::serializeWithPrecision(std::ostream & ostr) const
{
    ostr << '{';
    SPL::serializeWithPrecision(ostr << "maxPopulation=", get_maxPopulation()) << ",";
    SPL::serializeWithPrecision(ostr << "maxMAge=", get_maxMAge()) << ",";
    SPL::serializeWithPrecision(ostr << "minMAge=", get_minMAge()) << ",";
    SPL::serializeWithPrecision(ostr << "minpEducated=", get_minpEducated()) ;
    ostr << '}';
}

SELF& SELF::clear()
{
    get_maxPopulation() = 0;
    get_maxMAge() = 0;
    get_minMAge() = 0;
    get_minpEducated() = 0;

    return *this;
}

void SELF::normalizeBoundedSetsAndMaps()
{
    SPL::normalizeBoundedSetsAndMaps(*this);
}


