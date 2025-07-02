#include <blink/memory_map.hpp>
#include <blink/rcc/globals.hpp>

namespace rcc
{
    rcc& rcc_global = *reinterpret_cast<rcc*>(RCC_BASE);
}