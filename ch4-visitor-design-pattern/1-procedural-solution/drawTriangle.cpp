#include <iostream>
#include "drawTriangle.h"
#include "triangle.h"
// #include some graphics library

void draw(const Triangle &triangle)
{
  std::cout << "drawing triangle... p1=(" << triangle.p1().x << ", " << triangle.p1().y << "), p2=(" << triangle.p2().x << ", " << triangle.p2().y << "), p3=(" << triangle.p3().x << ", " << triangle.p3().y << ")\n";
}
