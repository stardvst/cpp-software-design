#include <iostream>
#include "triangle.h"
// #include some graphics library

void Triangle::draw() const
{
  std::cout << "drawing triangle... p1=(" << p1().x << ", " << p1().y << "), p2=(" << p2().x << ", " << p2().y << "), p3=(" << p3().x << ", " << p3().y << ")\n";
}
