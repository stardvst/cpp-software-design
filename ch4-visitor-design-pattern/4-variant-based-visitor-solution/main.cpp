#include "drawAllShapes.h"
#include "point.h"
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

int main()
{
  Shapes shapes;

  shapes.emplace_back(Circle{2.3});
  shapes.emplace_back(Square{1.2});
  shapes.emplace_back(Circle{4.1});
  shapes.emplace_back(Triangle{Point{3, 5}, Point{5, 2}, Point{5, 10}});

  drawAllShapes(shapes);

  return 0;
}
