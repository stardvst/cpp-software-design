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

  if (shape1 == shape2)
    std::cout << "shape1 == shape2\n";
  else
    std::cout << "shape1 != shape2\n";

  Square square1(2);
  auto squareDrawer = [](const Square &s)
  { std::cout << "drawing a square, side = " << s.side() << '\n'; };

  Shape shape3(square1, squareDrawer);
  draw(shape3);

  Square square2(3);
  Shape shape4(square2, squareDrawer);
  draw(shape4);

  if (shape3 == shape4)
    std::cout << "shape3 == shape4\n";
  else
    std::cout << "shape3 != shape4\n";
}
