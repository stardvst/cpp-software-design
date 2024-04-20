#pragma once

#include <iostream>
#include "square.h"

class OpenGLDrawSquareStrategy
{
public:
  void operator()(const Square &square /*, some arguments*/) const
  {
    std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
  }
};
