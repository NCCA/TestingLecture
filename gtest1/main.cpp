#include <gtest/gtest.h>
#include "str2double.h"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(str2Double,positiveTest)
{
  double value;
  ASSERT_TRUE(stringToDouble("1", value));
  ASSERT_DOUBLE_EQ(value, 1.0);
}

TEST(str2Double,negativeTest)
{
  double value;
  ASSERT_TRUE(stringToDouble("-1", value));
  ASSERT_DOUBLE_EQ(value, -1.0);
}


TEST(str2Double,zero)
{
  double value;
  ASSERT_TRUE(stringToDouble("0", value));
  ASSERT_DOUBLE_EQ(value, 0.0);
}

TEST(str2Double,minusZero)
{
  double value;
  ASSERT_TRUE(stringToDouble("-0", value));
  ASSERT_DOUBLE_EQ(value, -0.0);
}

TEST(str2Double,pi)
{
  double value;
  ASSERT_TRUE(stringToDouble("3.14159265", value));
  ASSERT_DOUBLE_EQ(value, 3.14159265);
}


TEST(str2Double,largeScientific)
{
  double value;
  ASSERT_TRUE(stringToDouble("2e10", value));
  ASSERT_DOUBLE_EQ(value, 2e10);
}

TEST(str2Double,random)
{
  double value;
  ASSERT_FALSE(stringToDouble("one",value));
  ASSERT_DOUBLE_EQ(1.0,value);
}


TEST(str2Double,smallScientific)
{
  double value;
  ASSERT_TRUE(stringToDouble("+4.3e-10", value));
  ASSERT_DOUBLE_EQ(value, +4.3e-10);
}

TEST(str2Double,empty)
{
  double value;
  ASSERT_FALSE(stringToDouble("",value));
}

TEST(str2Double,whitespace)
{
  double value;
  ASSERT_FALSE(stringToDouble(" ", value));
}

TEST(str2Double,plusminus)
{
  double value;
  ASSERT_FALSE(stringToDouble("+-1", value));
}

// this one is intersting it should fail but returns 1 / true but from the spec
// Function discards any whitespace characters (as determined by std::isspace())
// until first non-whitespace character is found.
// Then it takes as many characters as possible to form a valid floating-point representation
// and converts them to a floating-point value.
TEST(str2Double,multiplepoints)
{
  double value;
  ASSERT_TRUE(stringToDouble("1.0.1", value));
}

TEST(str2Double,notanumber)
{
  double value;
  ASSERT_FALSE(stringToDouble("text", value));
}



