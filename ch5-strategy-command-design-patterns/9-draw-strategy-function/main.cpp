#include <memory>
#include <vector>
#include "circle.h"
#include "square.h"
#include "shape.h"
#include "openGLDrawCircleStrategy.h"
#include "openGLDrawSquareStrategy.h"

int main()
{
  using Shapes = std::vector<std::unique_ptr<Shape>>;

  Shapes shapes;
  shapes.emplace_back(std::make_unique<Circle>(2.3, OpenGLDrawCircleStrategy{}));
  shapes.emplace_back(std::make_unique<Square>(1.2, OpenGLDrawSquareStrategy{}));
  shapes.emplace_back(std::make_unique<Circle>(4.1, OpenGLDrawCircleStrategy{}));

  for (const auto &shape : shapes)
    shape->draw();

  return 0;
}
