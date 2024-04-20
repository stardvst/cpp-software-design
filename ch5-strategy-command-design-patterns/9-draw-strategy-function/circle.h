#pragma once

#include <functional>
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
public:
  using DrawCircleStrategy = std::function<void(const Circle & /*, ...*/)>;

  Circle(double radius, DrawCircleStrategy drawer)
    : m_radius(radius)
    , m_drawer(std::move(drawer))
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

  void draw(/*some arguments*/) const override
  {
    m_drawer(*this /*, some arguments*/);
  }

private:
  double m_radius{};
  Point m_center{};
  DrawCircleStrategy m_drawer{};
};
