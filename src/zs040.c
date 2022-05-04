/**
 ******************************************************************************
 * @file           : zs040.c
 * @brief          : Source file.
 *                   This file contains the common code of the ZS-040 bluetooth
 *                   dongle.
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <zs040/zs040.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static ZS040_UartSendFunction ZS040_uart_send = NULL;
static ZS040_UartReceiveFunction ZS040_uart_receive = NULL;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void ZS040_init(const ZS040_UartSendFunction uart_send_fun, 
    const ZS040_UartReceiveFunction uart_receive_fun,
    ZS040_Status *status)
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (uart_send_fun == NULL || uart_receive_fun == NULL) {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (m_status == ZS040_STATUS_SUCCESS) {
        ZS040_uart_send = uart_send_fun;
        ZS040_uart_receive = uart_receive_fun;
    }

    if (status != NULL) {
        *status = m_status;
    }
}

void ZS040_receive(uint8_t *data, 
    const unsigned max_len, 
    const unsigned timeout_ms, 
    ZS040_Status *status)
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (ZS040_uart_receive != NULL && data != NULL) {
        ZS040_uart_receive(data, max_len, timeout_ms, &m_status);
    } else {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (status != NULL) {
        *status = m_status;
    }
}

void ZS040_send(const uint8_t *data, 
    const unsigned len, 
    const unsigned timeout_ms, 
    ZS040_Status *status) 
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (ZS040_uart_send != NULL && data != NULL) {
        ZS040_uart_send(data, len, timeout_ms, &m_status);
    } else {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (status != NULL) {
        *status = m_status;
    }
}
