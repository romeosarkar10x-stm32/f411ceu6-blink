#include <blink/gpio/globals.hpp>
#include <blink/main.hpp>
#include <blink/rcc/globals.hpp>

void loop()
{
    for (u32 i = 0; i < 0x100000; i++);
}

[[noreturn]] int main()
{
    /*
    unsigned int a = 0x11111111;
    unsigned int b = 0x22222222;
    unsigned int c = 0x33333333;
    unsigned int d = 0x44444444;

    unsigned int e = 0x55555555;
    unsigned int f = 0x66666666;
    unsigned int g = 0x77777777;
    unsigned int h = 0x88888888;
    */

    // rcc::rcc_global.

    /* Initialize gpio */
    rcc::rcc_global.get_ahb1_peripheral_clock_enable_register().set_gpio_c_clock_enable(rcc::enum_enable_t::ENABLE);

    gpio::gpio_c_global.get_mode_register().set_mode(gpio::pin<13u>{}, gpio::enum_gpio_mode::GENERAL_PURPOSE_OUTPUT);
    gpio::gpio_c_global.get_output_type_register().set_type(
        gpio::pin<13u>{}, gpio::registers::enum_output_type::type::PUSH_PULL
    );
    gpio::gpio_c_global.get_output_speed_register().set_speed(gpio::registers::enum_output_speed::type::LOW);
    gpio::gpio_c_global.get_pull_up_pull_down_register().set_configuration(
        gpio::pin<13u>{},
        gpio::registers::pull_up_pull_down_register::enum_pull_up_pull_down_configuration::type::NO_PULL_UP_PULL_DOWN
    );

    while (1) {
        gpio::gpio_c_global.get_output_data_register().set_data(
            gpio::registers::pin<13u>{}, gpio::registers::enum_bit::OFF
        );
        loop();

        gpio::gpio_c_global.get_output_data_register().set_data(
            gpio::registers::pin<13u>{}, gpio::registers::enum_bit::ON
        );

        loop();
    }
}