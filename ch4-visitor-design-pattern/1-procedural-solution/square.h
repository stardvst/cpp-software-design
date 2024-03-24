#pragma once

#include "point.h"
#include "shape.h"

class Square : public Shape
{
public:
  explicit Square(double side)
      : Shape(ShapeType::square), m_side(side)
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

private:
  double m_side{};
  Point m_center{};
};
