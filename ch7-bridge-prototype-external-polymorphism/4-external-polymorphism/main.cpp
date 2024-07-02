#include "circle.h"
#include "square.h"
#include "shape.h"
#include "openGLDrawStrategy.h"
#include <memory>
#include <vector>

int main()
{
  using Shapes = std::vector<std::unique_ptr<ShapeConcept>>;

  using CircleModel = ShapeModel<Circle, openGLDrawStrategy>;
  using SquareModel = ShapeModel<Square, openGLDrawStrategy>;

  Shapes shapes{};

  shapes.emplace_back(std::make_unique<CircleModel>(Circle{2.3}, openGLDrawStrategy{}));
  shapes.emplace_back(std::make_unique<SquareModel>(Square{1.2}, openGLDrawStrategy{}));
  shapes.emplace_back(std::make_unique<CircleModel>(Circle{4.1}, openGLDrawStrategy{}));

  for (const auto &shape : shapes)
    shape->draw();
}
