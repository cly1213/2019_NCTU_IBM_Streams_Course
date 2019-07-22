#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./division.h"
namespace application { 
SPL::uint32 division (const SPL::uint32& op1, const SPL::uint32& op2)
{
    return SPL::uint32(op1 / op2);
}
} 
