#pragma once

#include <iostream>
#include "drawSquareStrategy.h"
#include "square.h"

class OpenGLDrawSquareStrategy : public DrawSquareStrategy
{
public:
  void draw(const Square &square /*, some arguments*/) const override
  {
    std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
  }
};
