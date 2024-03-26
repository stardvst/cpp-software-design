#include <iostream>
#include "square.h"
// #include some graphics library

void Square::draw() const
{
  std::cout << "drawing square... side=" << side() << ", center x/y=" << center().x << '/' << center().y << '\n';
}

void Square::serialize() const
{
  std::cout << "serializing square...\n";
}
