#include "zs040/zs040.h"
#include <memory>
#include "gtest/gtest.h"

TEST(test_init, uart_write_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UserUartReceiveFunction uart_receive;

  ZS040_init(NULL, uart_receive, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, uart_receive_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UserUartSendFunction uart_send;

  ZS040_init(uart_send, NULL, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, success) {
  ZS040_Status status = ZS040_STATUS_FAILURE;
  ZS040_UserUartSendFunction uart_send;
  ZS040_UserUartReceiveFunction uart_receive;

  ZS040_init(uart_send, uart_receive, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_SUCCESS);
}
