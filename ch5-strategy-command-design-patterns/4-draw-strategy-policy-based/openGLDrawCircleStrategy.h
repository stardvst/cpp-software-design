#pragma once

#include <iostream>
#include "circle.h"

class OpenGLDrawCircleStrategy
{
public:
  void operator()(const Circle<OpenGLDrawCircleStrategy> &circle /*, some arguments*/) const
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }
};
