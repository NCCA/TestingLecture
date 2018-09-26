#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockTurtle.h"
#include "Painter.h"
// based on example here https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md

int main(int argc, char** argv)
{
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(PainterTest, CanDrawSomething)
{
  using ::testing::AtLeast;
  using ::testing::_;
  MockTurtle turtle;
  EXPECT_CALL(turtle, penDown())
      .Times(AtLeast(1));
  EXPECT_CALL(turtle, goTo(_,_))
      .Times(AtLeast(1));
  EXPECT_CALL(turtle, forward(_))
      .Times(AtLeast(1));

  EXPECT_CALL(turtle, turn(_))
      .Times(AtLeast(1));


  Painter painter(&turtle);
  // Note test and mock together!
  EXPECT_TRUE(painter.drawCircle(0, 0, 10));
}








