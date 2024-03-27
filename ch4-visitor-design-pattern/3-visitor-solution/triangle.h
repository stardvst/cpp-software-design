#pragma once

#include <utility>
#include "point.h"
#include "shape.h"
#include "shapeVisitor.h"

class Triangle : public Shape
{
public:
  explicit Triangle(Point p1, Point p2, Point p3)
      : m_p1(std::move(p1)), m_p2(std::move(p2)), m_p3(std::move(p3))
  {
  }

  Point p1() const { return m_p1; }
  Point p2() const { return m_p2; }
  Point p3() const { return m_p3; }

  void accept(const ShapeVisitor &visitor) const override { visitor.visit(*this); }

private:
  Point m_p1{}, m_p2{}, m_p3{};
};
