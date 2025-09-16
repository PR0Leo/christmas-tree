#include "driver/gpio.h"
#include "esp_rom_sys.h"

#define BLINK_GPIO GPIO_NUM_15 // adjust if needed

void app_main(void)
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (true)
    {
        gpio_set_level(BLINK_GPIO, 1);
        esp_rom_delay_us(500000); // 500ms
        gpio_set_level(BLINK_GPIO, 0);
        esp_rom_delay_us(500000);
    }
}
