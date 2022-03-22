#include <cstdlib>
#include "gtest/gtest.h"

int main(int argc, char** argv) {
  try {
      testing::InitGoogleTest(&argc, argv);
      testing::FLAGS_gtest_death_test_style = "threadsafe";
      return RUN_ALL_TESTS();
  } catch (...) {
      // Catch all exceptions to make Coverity happy.
  }
  
  return EXIT_FAILURE;
}
