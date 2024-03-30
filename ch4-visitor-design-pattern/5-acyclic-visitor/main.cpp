#include <memory>
#include <vector>
#include "drawAllShapes.h"
#include "shape.h"
#include "circle.h"
#include "square.h"

int main()
{
  using Shapes = std::vector<std::unique_ptr<Shape>>;

  Shapes shapes;
  shapes.emplace_back(std::make_unique<Circle>(2.3));
  shapes.emplace_back(std::make_unique<Square>(1.2));
  shapes.emplace_back(std::make_unique<Circle>(4.1));

  drawAllShapes(shapes);

  return 0;
}
