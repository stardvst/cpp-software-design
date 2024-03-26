#include "serializeAllShapes.h"
#include "shape.h"

void serializeAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
    shape->serialize();
}
