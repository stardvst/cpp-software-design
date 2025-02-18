#pragma once

#include "point.h"
#include "shape.h"
#include "shapeVisitor.h"

class Circle : public Shape
{
public:
  Circle(double radius) : m_radius(radius)
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

  void accept(const ShapeVisitor &visitor) const override { visitor.visit(*this); }

private:
  double m_radius{};
  Point m_center{};
};
