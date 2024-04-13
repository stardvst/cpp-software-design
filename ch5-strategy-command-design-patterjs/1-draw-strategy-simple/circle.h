#pragma once

#include <memory>
#include <utility>
#include "drawStrategy.h"
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
public:
  Circle(double radius, std::unique_ptr<DrawStrategy> drawer)
    : m_radius(radius)
    , m_drawer(std::move(drawer))
  {
  }

  double radius() const { return m_radius; }
  Point center() const { return m_center; }

  void draw(/*some arguments*/) const override
  {
    m_drawer->draw(*this /*, some arguments*/);
  }

private:
  double m_radius{};
  Point m_center{};
  std::unique_ptr<DrawStrategy> m_drawer{};
};
