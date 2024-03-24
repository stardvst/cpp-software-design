#include <iostream>
#include "drawSquare.h"
#include "square.h"
// #include some graphics library

void draw(const Square &square)
{
  std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
}
