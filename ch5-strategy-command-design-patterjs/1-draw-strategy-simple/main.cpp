#include <memory>
#include <vector>
#include "point.h"
#include "circle.h"
#include "square.h"
#include "shape.h"
#include "openGLDrawStrategy.h"

int main()
{
  using Shapes = std::vector<std::unique_ptr<Shape>>;

  Shapes shapes;
  shapes.emplace_back(std::make_unique<Circle>(2.3, std::make_unique<OpenGLDrawStrategy>()));
  shapes.emplace_back(std::make_unique<Square>(1.2, std::make_unique<OpenGLDrawStrategy>()));
  shapes.emplace_back(std::make_unique<Circle>(4.1, std::make_unique<OpenGLDrawStrategy>()));

  for (const auto &shape : shapes)
    shape->draw();

  return 0;
}
