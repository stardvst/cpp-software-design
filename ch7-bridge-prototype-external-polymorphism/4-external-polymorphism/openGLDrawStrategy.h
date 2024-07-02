#pragma once

#include "circle.h"
#include "square.h"
#include <iostream>
// #include OpenGL headers

class openGLDrawStrategy
{
public:
  explicit openGLDrawStrategy(/* drawing related args */) {}

  void operator()(const Circle &circle) const
  {
    std::cout << "drawing circle... r=" << circle.radius() << '\n';
  }

  void operator()(const Square &square) const
  {
    std::cout << "drawing square... side=" << square.side() << '\n';
  }

private:
  /// drawing related members
};
