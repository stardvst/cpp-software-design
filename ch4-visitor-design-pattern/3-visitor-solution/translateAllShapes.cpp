#include "translateAllShapes.h"
#include "shape.h"
#include "translate.h"

void translateAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
    shape->accept(Translate{});
}
