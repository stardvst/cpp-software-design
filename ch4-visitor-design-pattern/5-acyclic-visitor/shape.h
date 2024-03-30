#pragma once

class AbstractVisitor;

class Shape
{
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual void accept(const AbstractVisitor &visitor) const = 0;
};
