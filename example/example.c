#include "zs040/zs040.h"


void user_uart_send_blocking_function(const uint8_t* const data, 
    const unsigned len, 
    ZS040_Status *status)
{
    // TODO

    *status = ZS040_STATUS_SUCCESS;
}


void user_uart_receive_blocking_function(uint8_t* data, 
    const unsigned len, 
    unsigned timeout_ms, 
    ZS040_Status *status)
{
    // TODO

    *status = ZS040_STATUS_SUCCESS;
}


int main(void)
{
    ZS040_Status status;
    ZS040_init(user_uart_send_blocking_function, 
        user_uart_receive_blocking_function, 
        &status);
    
    if (status == ZS040_STATUS_SUCCESS) {
        ZS040_send_blocking("hello world", sizeof("hello world"), &status);
    }
    
    return 0;
}
