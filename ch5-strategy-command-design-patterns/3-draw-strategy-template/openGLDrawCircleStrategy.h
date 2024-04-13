#pragma once

#include <iostream>
#include "drawStrategy.h"
#include "circle.h"

class OpenGLDrawCircleStrategy : public DrawStrategy<Circle>
{
public:
  void draw(const Circle &circle /*, some arguments*/) const override
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }
};
