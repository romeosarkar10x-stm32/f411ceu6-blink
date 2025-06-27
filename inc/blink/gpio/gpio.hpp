
#include <cstdint>

#include <blink/memory_map.hpp>
#include <blink/types.hpp>

#include "registers/alternate_function_register.hpp"
#include "registers/bit_set_reset_register.hpp"
#include "registers/configuration_lock_register.hpp"
#include "registers/pull_up_pull_down_register.hpp"
#include "registers/registers.hpp"

namespace gpio
{
    struct gpio
    {
        mode_register              mode_obj;
        output_type_register       output_typer_obj;
        output_speed_register      output_speed_obj;
        pull_up_pull_down_register pull_up_pull_down_obj;

        input_data_register         input_data_obj;
        output_data_register        output_data_obj;
        bit_set_reset_register      bit_set_reset_obj;
        configuration_lock_register configuration_lock_obj;
        alternate_function_register alternate_function_obj;
    };

} // namespace gpio