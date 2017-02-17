#ifndef PAINTER_H_
#define PAINTER_H_
#include "Turtle.h"
#include <iostream>
class Painter
{
  public :
    Painter(Turtle *t) :m_turtle(t){;}
    bool drawCircle(int _x, int _y, int _r )
    {
      // made up routine to test
      m_turtle->penDown();
      m_turtle->goTo(_x,_y);
      m_turtle->turn(_r);
      m_turtle->forward(_r);
      return true;
    }

  private :
     Turtle *m_turtle;
};

#endif
