#include "drawAllShapes.h"
#include "shape.h"
#include "circle.h"
#include "square.h"

int main()
{
  Shapes shapes;

  shapes.emplace_back(Circle{2.3});
  shapes.emplace_back(Square{1.2});
  shapes.emplace_back(Circle{4.1});

  drawAllShapes(shapes);

  return 0;
}
