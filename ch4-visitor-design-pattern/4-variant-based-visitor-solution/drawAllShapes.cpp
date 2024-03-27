#include "drawAllShapes.h"
#include "draw.h"

void drawAllShapes(const Shapes &shapes)
{
  for (const auto &shape : shapes)
  {
    std::visit(Draw{}, shape);
  }
}
