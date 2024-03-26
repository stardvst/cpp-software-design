#pragma once

#include "point.h"
#include "shape.h"

class Circle : public Shape
{
public:
  Circle(double radius) : m_radius(radius)
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

  void draw() const override;
  void serialize() const override;

private:
  double m_radius{};
  Point m_center{};
};
