#include <iostream>
#include "circle.h"
// #include some graphics library

void Circle::draw() const
{
  std::cout << "drawing circle... r=" << radius() << ", center x/y=" << center().x << '/' << center().y << '\n';
}

void Circle::serialize() const
{
  std::cout << "serializing circle...\n";
}
