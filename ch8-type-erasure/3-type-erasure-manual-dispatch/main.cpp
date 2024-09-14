#include "circle.h"
#include "square.h"
#include "shape.h"
#include <cstdlib>
#include <iostream>

int main()
{
  Circle circle{3.14};
  auto drawer = [](const Circle &c)
  { std::cout << "drawing a circle, radius = " << c.radius() << '\n'; };

  Shape shape1(circle, drawer);
  draw(shape1);

  Shape shape2(shape1);
  draw(shape2);
}
