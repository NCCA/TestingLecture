// based on example here https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md

#ifndef MOCKTURTLE_H_
#define MOCKTURTLE_H_
#include "Turtle.h"
#include <gmock/gmock.h>

class MockTurtle : public Turtle
{
 public:
  MOCK_METHOD0(penUp, void());
  MOCK_METHOD0(penDown, void());
  MOCK_METHOD1(forward, void(int distance));
  MOCK_METHOD1(turn, void(int degrees));
  MOCK_METHOD2(goTo, void(int x, int y));
  MOCK_CONST_METHOD0(getX, int());
  MOCK_CONST_METHOD0(getY, int());
};


#endif
