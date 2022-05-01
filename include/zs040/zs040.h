/**
 ******************************************************************************
 * @file           : zs040.h
 * @brief          : Header for zs040.c file.
 *                   This file contains the common code of the ZS-040 bluetooth
 *                   dongle.
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ZS040_H
#define __ZS040_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
#include <stdint.h>

/* Private defines -----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef enum {
    ZS040_STATUS_SUCCESS,
    ZS040_STATUS_FAILURE,
} ZS040_Status;

typedef void (*ZS040_UserUartSendBlockingFunction)(const uint8_t* const data, 
    const unsigned len, 
    ZS040_Status *status);

typedef void (*ZS040_UserUartReceiveBlockingFunction)(uint8_t* data, 
    const unsigned len, 
    unsigned timeout_ms,
    ZS040_Status *status);

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void ZS040_init(ZS040_UserUartSendBlockingFunction uart_send_blocking, 
    ZS040_UserUartReceiveBlockingFunction uart_receive_blocking,
    ZS040_Status *status);
void ZS040_receive_blocking(uint8_t *data, unsigned max_len, unsigned timeout_ms, ZS040_Status *status);
void ZS040_send_blocking(const uint8_t *data, const unsigned len, ZS040_Status *status);

#ifdef __cplusplus
}
#endif

#endif /* __ZS040_H */
