#include "zs040/zs040.h"
#include <memory>
#include "gtest/gtest.h"

TEST(test_init, uart_write_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UserUartReceiveBlockingFunction uart_receive_blocking;

  ZS040_init(NULL, uart_receive_blocking, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, uart_receive_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UserUartSendBlockingFunction uart_send_blocking;

  ZS040_init(uart_send_blocking, NULL, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, success) {
  ZS040_Status status = ZS040_STATUS_FAILURE;
  ZS040_UserUartSendBlockingFunction uart_send_blocking;
  ZS040_UserUartReceiveBlockingFunction uart_receive_blocking;

  ZS040_init(uart_send_blocking, uart_receive_blocking, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_SUCCESS);
}
