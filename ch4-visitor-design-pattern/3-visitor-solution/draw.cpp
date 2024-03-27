#include <iostream>
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "draw.h"

void Draw::visit(const Circle &circle) const
{
  std::cout << "drawing circle... r=" << circle.radius() << ", center x/y=" << circle.center().x << '/' << circle.center().y << '\n';
}

void Draw::visit(const Square &square) const
{
  std::cout << "drawing square... side=" << square.side() << ", center x/y=" << square.center().x << '/' << square.center().y << '\n';
}

void Draw::visit(const Triangle &triangle) const
{
  std::cout << "drawing triangle... p1=(" << triangle.p1().x << ", " << triangle.p1().y << "), p2=(" << triangle.p2().x << ", " << triangle.p2().y << "), p3=(" << triangle.p3().x << ", " << triangle.p3().y << ")\n";
}
