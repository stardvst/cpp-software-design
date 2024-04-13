#pragma once

#include <iostream>
#include "drawCircleStrategy.h"
#include "circle.h"

class OpenGLDrawCircleStrategy : public DrawCircleStrategy
{
public:
  void draw(const Circle &circle /*, some arguments*/) const override
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }
};
