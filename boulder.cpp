#include "boulder.h"

#define BOULDER_RES 32
#define BOULDER_SIZE 50
#define BOULDER_DELTA 15
#define BOULDER_DELTA_2 (BOULDER_DELTA/2)

#define PI 3.14159265
#define TAU PI*2

using namespace std;

Boulder::Boulder(const int stage)
{
  Spin = 5 - rand() % 10;
  Speed = sf::Vector2f(5.0 - rand() % 10, 5.0 - rand() % 10);
  Stage = stage;

  // resize it to 5 points
  Shape.setPointCount(BOULDER_RES);

  // define the points
  for(int i=0; i<BOULDER_RES; i++) {
      float angle = (TAU / BOULDER_RES) * i;
      float x = (cos(angle) * BOULDER_SIZE) + (BOULDER_DELTA_2-rand() % BOULDER_DELTA);
      float y = (sin(angle) * BOULDER_SIZE) + (BOULDER_DELTA_2-rand() % BOULDER_DELTA);
      //cout << x << ", " << y << " " << endl;
      Shape.setPoint(i, sf::Vector2f(x, y));
  }
  cout << endl;

  Shape.setPosition(rand() % 800, rand() % 600);
  /*
  Shape.setPoint(0, sf::Vector2f(0, 0));
  Shape.setPoint(1, sf::Vector2f(sin(45)*50, sin(45)*50));
  Shape.setPoint(2, sf::Vector2f(120, 90));
  Shape.setPoint(3, sf::Vector2f(30, 100));
  Shape.setPoint(4, sf::Vector2f(0, 50));
  */
}
