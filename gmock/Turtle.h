// based on example here https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md

#ifndef TURTLE_H_
#define TURTLE_H_

class Turtle
{
  public :
   virtual ~Turtle() {}
   virtual void penUp(){}
   virtual void penDown() {}
   virtual void forward(int distance) {}
   virtual void turn(int degrees) { m_rot=degrees;}
   virtual void goTo(int x, int y) { m_x=x; m_y=y;}
   virtual int getX() const {return m_x;}
   virtual int getY() const {return m_y;}

  private :
   int m_x=0;
   int m_y=0;
   int m_rot;

};

#endif
