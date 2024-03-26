#pragma once

class ShapeVisitor;

class Shape
{
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual void accept(const ShapeVisitor &visitor) const = 0;
};
