#include "zs040/zs040.h"
#include <memory>
#include "gtest/gtest.h"

TEST(test_init, uart_write_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UartReceiveFunction uart_receive;

  ZS040_init(NULL, uart_receive, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, uart_receive_null) {
  ZS040_Status status = ZS040_STATUS_SUCCESS;
  ZS040_UartSendFunction uart_send;

  ZS040_init(uart_send, NULL, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_FAILURE);
}

TEST(test_init, success) {
  ZS040_Status status = ZS040_STATUS_FAILURE;
  ZS040_UartSendFunction uart_send;
  ZS040_UartReceiveFunction uart_receive;

  ZS040_init(uart_send, uart_receive, &status);
  
  EXPECT_EQ(status, ZS040_STATUS_SUCCESS);
}
