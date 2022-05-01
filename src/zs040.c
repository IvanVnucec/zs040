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
static ZS040_UserUartSendBlockingFunction ZS040_uart_send_blocking = NULL;
static ZS040_UserUartReceiveBlockingFunction ZS040_uart_receive_blocking = NULL;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
void ZS040_init(const ZS040_UserUartSendBlockingFunction uart_send_blocking, 
    const ZS040_UserUartReceiveBlockingFunction uart_receive_blocking,
    ZS040_Status *status)
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (uart_send_blocking == NULL || uart_receive_blocking == NULL) {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (m_status == ZS040_STATUS_SUCCESS) {
        ZS040_uart_send_blocking = uart_send_blocking;
        ZS040_uart_receive_blocking = uart_receive_blocking;
    }

    if (status != NULL) {
        *status = m_status;
    }
}

void ZS040_receive_blocking(uint8_t *data, 
    const unsigned max_len, 
    const unsigned timeout_ms, 
    ZS040_Status *status)
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (ZS040_uart_receive_blocking != NULL && data != NULL) {
        ZS040_uart_receive_blocking(data, max_len, timeout_ms, &m_status);
    } else {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (status != NULL) {
        *status = m_status;
    }
}

void ZS040_send_blocking(const uint8_t *data, 
    const unsigned len, 
    const unsigned timeout_ms, 
    ZS040_Status *status) 
{
    ZS040_Status m_status = ZS040_STATUS_SUCCESS;

    if (ZS040_uart_send_blocking != NULL && data != NULL) {
        ZS040_uart_send_blocking(data, len, timeout_ms, &m_status);
    } else {
        m_status = ZS040_STATUS_FAILURE;
    }

    if (status != NULL) {
        *status = m_status;
    }
}
