#pragma once

class Circle;
class Square;
class Triangle;

class ShapeVisitor
{
public:
  virtual ~ShapeVisitor() = default;

  virtual void visit(const Circle &circle) const = 0;
  virtual void visit(const Square &circle) const = 0;
  virtual void visit(const Triangle &circle) const = 0;
};
