#pragma once

#include "point.h"
#include "shape.h"
#include "abstractVisitor.h"
#include "visitor.h"

class Circle : public Shape
{
public:
  Circle(double radius) : m_radius(radius)
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

  void accept(const AbstractVisitor &visitor) const override
  {
    if (const auto *circleVisitor = dynamic_cast<const Visitor<Circle> *>(&visitor))
      circleVisitor->visit(*this);
  }

private:
  double m_radius{};
  Point m_center{};
};
