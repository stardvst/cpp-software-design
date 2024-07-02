#pragma once

class Circle
{
public:
  explicit Circle(double radius)
      : m_radius(radius)
  {
  }

  double radius() const { return m_radius; }

private:
  double m_radius{};
};
