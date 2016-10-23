#ifndef BOULDER_H
#define BOULDER_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Boulder
{
public:
  Boulder(const int stage);
  sf::Vector2f Speed;
  float Spin;
  int Stage;
  sf::ConvexShape Shape;
};

#endif
