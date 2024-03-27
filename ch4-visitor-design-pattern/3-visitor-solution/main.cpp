#include <memory>
#include <vector>
#include "point.h"
#include "drawAllShapes.h"
#include "translateAllShapes.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "shape.h"

int main()
{
  using Shapes = std::vector<std::unique_ptr<Shape>>;

  Shapes shapes;
  shapes.emplace_back(std::make_unique<Circle>(2.3));
  shapes.emplace_back(std::make_unique<Square>(1.2));
  shapes.emplace_back(std::make_unique<Circle>(4.1));
  shapes.emplace_back(std::make_unique<Triangle>(Point{3, 5}, Point{5, 2}, Point{5, 10}));

  drawAllShapes(shapes);
  translateAllShapes(shapes);

  return 0;
}
