#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./addition.h"
namespace application { 
SPL::uint32 addition (const SPL::uint32& op1, const SPL::uint32& op2)
{
    return SPL::uint32(op1 + op2);
}
} 
