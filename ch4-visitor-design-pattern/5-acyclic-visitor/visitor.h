#pragma once

template <typename Shape>
class Visitor
{
public:
  virtual void visit(const Shape &shape) const = 0;

protected:
  ~Visitor() = default;
};
