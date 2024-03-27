#pragma once

#include "point.h"

class Circle
{
public:
  Circle(double radius) : m_radius(radius)
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

private:
  double m_radius{};
  Point m_center{};
};
