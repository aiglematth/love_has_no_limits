//
// This file define all errors
//

#ifndef TEDDY_ERRORS
#define TEDDY_ERRORS

//
// Errors define
//
#define TEDDY_OK 0
#define TEDDY_FREERTOS_QUEUE_CREATE 1

//
// Typedefs
// 
typedef uint64_t teddy_err_t;

//
// Variables
//
static esp_err_t esp_errno = ESP_OK;
static teddy_err_t teddy_errno = TEDDY_OK;

//
// Macros
//
#define ESP_ERRNO_RESET() esp_errno = ESP_OK
#define ESP_RET_IF_FUNC_RET_ERR(ret_val) if((esp_errno = (ret_val)) != ESP_OK) { return; }
#define ESP_RET_IF_ERRNO_ERR(ret_val) (ret_val); if(esp_errno != ESP_OK) { return; }

#define TEDDY_ERRNO_RESET() teddy_errno = TEDDY_OK
#define TEDDY_RET_IF_ERR(ret_val) if((teddy_errno = (ret_val)) != TEDDY_OK) { return; }

#endif 