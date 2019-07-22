// y4_5inner5outer9leftOuter10rightOuter


#include "BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D.h"

#define SELF BeJyrNIk3zczLSy0yzS8tSS2yzElNK_1EHsQwNijLTMyBsAAobA5D

using namespace SPL;

EnumMappings* SELF::mappings_ = SELF::initMappings();


SELF SELF::inner(0);
SELF SELF::outer(1);
SELF SELF::leftOuter(2);
SELF SELF::rightOuter(3);

SELF::SELF(const std::string & v)
: Enum(*mappings_)
{
    // initialize from a string value
    this->Enum::operator=(v);
}

SELF::SELF(const rstring & v)
: Enum(*mappings_)
{
    // initialize from a string value
    this->Enum::operator=(v);
}


EnumMappings* SELF::initMappings()
{
   EnumMappings* em = new EnumMappings();
   // initialize the mappings 
   {
      std::string s("inner");
      em->nameToIndex_.insert(std::make_pair(s, 0));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("outer");
      em->nameToIndex_.insert(std::make_pair(s, 1));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("leftOuter");
      em->nameToIndex_.insert(std::make_pair(s, 2));
      em->indexToName_.push_back(s);
   }
   
   {
      std::string s("rightOuter");
      em->nameToIndex_.insert(std::make_pair(s, 3));
      em->indexToName_.push_back(s);
   }
   
   return em;
}
