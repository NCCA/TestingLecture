#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <ngl/Mat4.h>
using namespace testing;


TEST(NGLMat4,DefaultCtor)
{
  ngl::Mat4 test;
  ngl::Mat4 result(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
  EXPECT_TRUE(test == result);
}
