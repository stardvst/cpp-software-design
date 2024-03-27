#pragma once

#include "point.h"

class Square
{
public:
  explicit Square(double side) : m_side(side)
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

private:
  double m_side{};
  Point m_center{};
};
