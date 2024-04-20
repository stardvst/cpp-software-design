#pragma once

#include <memory>
#include <utility>
#include "point.h"
#include "shape.h"

template <typename DrawSquareStrategy>
class Square : public Shape
{
public:
  explicit Square(double side, DrawSquareStrategy drawer)
    : m_side(side)
    , m_drawer(std::move(drawer))
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

  void draw(/*some arguments*/) const override
  {
    m_drawer(*this /*, some arguments*/);
  }

private:
  double m_side{};
  Point m_center{};
  DrawSquareStrategy m_drawer{};
};
