#include <iostream>
#include "drawCircle.h"
#include "circle.h"
// #include some graphics library

void draw(const Circle &circle)
{
  std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
}
