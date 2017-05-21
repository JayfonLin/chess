
//Created on 2017-05-21
//@author: linjifang33@163.com

#include "log.h"
#include "gtest/gtest.h"


TEST(LogTest, WriteLog) {
  logging::log().info("IN MAIN!");
  logging::log().warn("root in main");
  logging::Log::GetInstance().error().info("error");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}