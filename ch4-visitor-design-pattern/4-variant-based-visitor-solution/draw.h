#pragma once

#include <iostream>
#include "shape.h"
// #include some graphics library

struct Draw
{
  void operator()(const Circle &circle)
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }

  void operator()(const Square &square)
  {
    std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
  }
};
