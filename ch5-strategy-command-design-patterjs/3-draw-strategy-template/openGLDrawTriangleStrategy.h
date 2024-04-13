#pragma once

#include <iostream>
#include "drawStrategy.h"
#include "triangle.h"

class OpenGLDrawTriangleStrategy : public DrawStrategy<Triangle>
{
public:
  void draw(const Triangle &triangle /*, some arguments*/) const override
  {
    std::cout << "drawing triangle... p1=(" << triangle.p1().x << ", " << triangle.p1().y << "), p2=(" << triangle.p2().x << ", " << triangle.p2().y << "), p3=(" << triangle.p3().x << ", " << triangle.p3().y << ")\n";
  }
};
