#include <iostream>
#include "circle.h"
#include "square.h"
#include "draw.h"

void Draw::visit(const Circle &circle) const
{
  std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
}

void Draw::visit(const Square &square) const
{
  std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
}
