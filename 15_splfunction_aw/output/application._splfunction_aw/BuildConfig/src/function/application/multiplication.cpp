#include "SPL/Runtime/Function/SPLFunctions.h"
#include "./multiplication.h"
namespace application { 
SPL::uint32 multiplication (const SPL::uint32& op1, const SPL::uint32& op2)
{
    return SPL::uint32(op1 * op2);
}
} 
