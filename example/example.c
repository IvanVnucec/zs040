#include "zs040/zs040.h"


#define RECV_LEN (10)


void user_uart_send_function(const uint8_t* const data, 
    const unsigned len, 
    const unsigned timeout_ms,
    ZS040_Status *status)
{
    // TODO

    *status = ZS040_STATUS_SUCCESS;
}


void user_uart_receive_function(uint8_t* data, 
    const unsigned len, 
    const unsigned timeout_ms, 
    ZS040_Status *status)
{
    // TODO

    *status = ZS040_STATUS_SUCCESS;
}


int main(void)
{
    ZS040_Status status;
    uint8_t recv_data[RECV_LEN] = {0};

    ZS040_init(user_uart_send_function, 
        user_uart_receive_function, 
        &status);
    
    if (status == ZS040_STATUS_SUCCESS) {
        ZS040_receive(recv_data, RECV_LEN, 100, &status);
    }

    if (status == ZS040_STATUS_SUCCESS) {
        ZS040_send("hello world", sizeof("hello world"), 100, &status);
    }

    
    return 0;
}
