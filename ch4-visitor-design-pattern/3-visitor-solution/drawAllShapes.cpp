#include "drawAllShapes.h"
#include "shape.h"
#include "draw.h"

void drawAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
    shape->accept(Draw{});
}
