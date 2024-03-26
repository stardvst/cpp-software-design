#pragma once

class Circle;
class Square;

class ShapeVisitor
{
public:
  virtual ~ShapeVisitor() = default;

  virtual void visit(const Circle &circle) const = 0;
  virtual void visit(const Square &circle) const = 0;
};
