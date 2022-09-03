#include <stdio.h>
#include "teddy_ihm.h"
#include "teddy_errors.h"

static void gpio_task_example(void* arg) {
    gpio_num_t io_num;
    for(;;) {
        if(xQueueReceive(teddy_gpio_queue, &io_num, portMAX_DELAY)) {
            printf("GPIO_%d\n", io_num);
        }
    }
}

extern "C" void app_main() {   
    ESP_ERRNO_RESET();
    TEDDY_ERRNO_RESET();
    teddy_gpio_init();

    if(esp_errno != ESP_OK || teddy_errno != TEDDY_OK) {
        printf("ERROR");
        return;
    }

    xTaskCreate(gpio_task_example, "gpio_task_example", 128, NULL, 10, NULL);
}