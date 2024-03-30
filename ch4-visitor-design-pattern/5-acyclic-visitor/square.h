#pragma once

#include "point.h"
#include "shape.h"
#include "abstractVisitor.h"
#include "visitor.h"

class Square : public Shape
{
public:
  explicit Square(double side) : m_side(side)
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

  void accept(const AbstractVisitor &visitor) const override
  {
    if (const auto *squareVisitor = dynamic_cast<const Visitor<Square> *>(&visitor))
      squareVisitor->visit(*this);
  }

private:
  double m_side{};
  Point m_center{};
};
