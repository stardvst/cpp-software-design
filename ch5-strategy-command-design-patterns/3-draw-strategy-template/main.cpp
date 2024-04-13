#include <memory>
#include <vector>
#include "point.h"
#include "circle.h"
#include "square.h"
#include "shape.h"
#include "openGLDrawCircleStrategy.h"
#include "openGLDrawSquareStrategy.h"
#include "openGLDrawTriangleStrategy.h"
#include "streamSerializeCircleStrategy.h"
#include "streamSerializeSquareStrategy.h"
#include "streamSerializeTriangleStrategy.h"

int main()
{
  using Shapes = std::vector<std::unique_ptr<Shape>>;

  Shapes shapes;
  shapes.emplace_back(std::make_unique<Circle>(2.3, std::make_unique<OpenGLDrawCircleStrategy>(), std::make_unique<StreamSerializeCircleStrategy>()));
  shapes.emplace_back(std::make_unique<Square>(1.2, std::make_unique<OpenGLDrawSquareStrategy>(), std::make_unique<StreamSerializeSquareStrategy>()));
  shapes.emplace_back(std::make_unique<Circle>(4.1, std::make_unique<OpenGLDrawCircleStrategy>(), std::make_unique<StreamSerializeCircleStrategy>()));
  shapes.emplace_back(std::make_unique<Triangle>(Point{3, 5}, Point{5, 2}, Point{5, 10}, std::make_unique<OpenGLDrawTriangleStrategy>(), std::make_unique<StreamSerializeTriangleStrategy>()));

  for (const auto &shape : shapes)
    shape->draw();

  for (const auto &shape : shapes)
    shape->serialize();

  return 0;
}
