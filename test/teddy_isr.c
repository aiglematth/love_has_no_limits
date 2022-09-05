//
// Includes
//
#include "driver/gpio.h"
#include "fifo.h"
#include "teddy_isr.h"
#include "teddy_errors.h"

//
// Functions
//
void teddy_gpio_disable_all(void) {
  ESP_RET_IF_FUNC_RET_ERR(gpio_config(&teddy_gpio_disabling_config))
}

void teddy_install_gpio_input(gpio_num_t pin) {
  ESP_RET_IF_FUNC_RET_ERR(gpio_intr_enable(pin))                      
  ESP_RET_IF_FUNC_RET_ERR(gpio_set_intr_type(pin, GPIO_INTR_ANYEDGE)) 
  ESP_RET_IF_FUNC_RET_ERR(gpio_set_direction(pin, GPIO_MODE_INPUT))   
  ESP_RET_IF_FUNC_RET_ERR(gpio_pullup_en(pin))                        
  ESP_RET_IF_FUNC_RET_ERR(gpio_isr_handler_add(pin, teddy_isr_handler, (void *)pin))
}

void teddy_gpio_config_buttons(void) {
  ESP_RET_IF_FUNC_RET_ERR(gpio_install_isr_service(ESP_INTR_FLAG_IRAM))
  ESP_RET_IF_ERRNO_ERR(teddy_install_gpio_input(TEDDY_WEBCONFIG_PIN))
  ESP_RET_IF_ERRNO_ERR(teddy_install_gpio_input(TEDDY_LOVE_PIN))
}

void teddy_gpio_init(void) {
  ESP_RET_IF_ERRNO_ERR(teddy_gpio_disable_all())
  ESP_RET_IF_ERRNO_ERR(teddy_gpio_config_buttons())
}

static void IRAM_ATTR teddy_isr_handler(void *args) {
  fifo_push(teddy_gpio_queue, (gpio_num_t)args);
}