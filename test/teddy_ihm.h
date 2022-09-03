//
// This file provide all ihm functions and configurations
//

#ifndef TEDDY_IHM
#define TEDDY_IHM

//
// Includes 
//
#include "driver/gpio.h"
#include "freertos/queue.h"

//
// Defines
//
#define TEDDY_WEBCONFIG_PIN GPIO_NUM_13
#define TEDDY_LOVE_PIN GPIO_NUM_34
#define TEDDY_GPIO_QUEUE_LEN 2

//
// Consts
//
static const gpio_config_t teddy_gpio_disabling_config = {
  .pin_bit_mask = 0xffffffffffffffff,
  .mode         = GPIO_MODE_DISABLE,
  .pull_up_en   = GPIO_PULLUP_DISABLE,
  .pull_down_en = GPIO_PULLDOWN_DISABLE,
  .intr_type    = GPIO_INTR_DISABLE
};

//
// Variables
//
static QueueHandle_t teddy_gpio_queue = NULL;

//
// Functions
//
void teddy_gpio_disable_all(void);
  //
  // This function disable all gpio in all functionalities
  //
  // esp_errno:
  //  - inhert all **gpio_config** function errors
  //

void teddy_install_gpio_input(gpio_num_t pin);
  //
  // This function install a gpio isr handler in input mode
  //
  // Parameters:
  //  - pin<gpio_num_t> : The pin number to install
  //
  // esp_errno:
  //  - inhert all **gpio_intr_enable**, **gpio_set_intr_type**, **gpio_set_direction** 
  //    **gpio_pullup_en** function errors
  //

void teddy_gpio_config_buttons(void);
  //
  // This function enable gpio for love and config buttons
  // It also install interrupt handlers
  //
  // esp_errno:
  //  - inhert all **gpio_install_isr_service**, **teddy_install_gpio_input**
  //

void teddy_gpio_init(void);
  //
  // This function is in charge of enabling only required gpio
  //
  // esp_errno:
  //  - inhert all **teddy_gpio_disable_all**, **teddy_gpio_config_buttons** errors
  //
  // teddy_errno:
  //  - TEDDY_FREERTOS_QUEUE_CREATE: Queue cannot be created
  //

static void IRAM_ATTR teddy_isr_handler(void *args);
  //
  // This function is the isr handler in charge of feeding the task queue
  //
  // Parameters:
  //  - args<void*> : Arguments passed to this handler (in our case, the pin number)
  //

#endif