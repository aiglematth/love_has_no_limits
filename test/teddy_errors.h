//
// This file define all teddy errors
//

#ifndef TEDDY_ERRORS
#define TEDDY_ERRORS

//
// Teddy errors define
//
#define TEDDY_OK 0

//
// Fifo errors define
//
#define FIFO_OK 0
#define FIFO_FULL 1
#define FIFO_EMPTY 2

//
// Typedefs
// 
typedef uint64_t teddy_err_t;
typedef uint64_t fifo_err_t;

//
// Variables
//
static esp_err_t esp_errno     = ESP_OK;
static teddy_err_t teddy_errno = TEDDY_OK;
static fifo_err_t fifo_errno   = FIFO_OK;

//
// Macros
//
#define ESP_ERRNO_RESET() esp_errno = ESP_OK
#define ESP_RET_IF_FUNC_RET_ERR(ret_val) if((esp_errno = (ret_val)) != ESP_OK) { return; }
#define ESP_RET_IF_ERRNO_ERR(ret_val) (ret_val); if(esp_errno != ESP_OK) { return; }

#define TEDDY_ERRNO_RESET() teddy_errno = TEDDY_OK
#define TEDDY_RET_IF_ERR(ret_val) if((teddy_errno = (ret_val)) != TEDDY_OK) { return; }

#define FIFO_ERRNO_RESET() fifo_errno = FIFO_OK

#endif 