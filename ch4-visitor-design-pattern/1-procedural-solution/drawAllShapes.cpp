#include "drawAllShapes.h"
#include "circle.h"
#include "drawCircle.h"
#include "square.h"
#include "drawSquare.h"
#include "triangle.h"
#include "drawTriangle.h"

void drawAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
  {
    switch (shape->getType())
    {
    case ShapeType::circle:
      draw(static_cast<const Circle &>(*shape));
      break;

    case ShapeType::square:
      draw(static_cast<const Square &>(*shape));
      break;

    case ShapeType::triangle:
      draw(static_cast<const Triangle &>(*shape));
      break;

    default:
      break;
    }
  }
}
