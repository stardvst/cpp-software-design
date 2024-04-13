#pragma once

#include <iostream>
#include "drawStrategy.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

class OpenGLDrawStrategy : public DrawStrategy
{
public:
  void draw(const Circle &circle /*, some arguments*/) const override
  {
    std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
  }

  void draw(const Square &square /*, some arguments*/) const override
  {
    std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
  }

  void draw(const Triangle &triangle/*, some arguments*/) const override
  {
    std::cout << "drawing triangle... p1=(" << triangle.p1().x << ", " << triangle.p1().y << "), p2=(" << triangle.p2().x << ", " << triangle.p2().y << "), p3=(" << triangle.p3().x << ", " << triangle.p3().y << ")\n";
  }
};
