#pragma once

#include <memory>
#include <utility>
#include "drawSquareStrategy.h"
#include "point.h"
#include "shape.h"

class Square : public Shape
{
public:
  explicit Square(double side, std::unique_ptr<DrawSquareStrategy> drawer)
    : m_side(side)
    , m_drawer(std::move(drawer))
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

  void draw(/*some arguments*/) const override
  {
    m_drawer->draw(*this /*, some arguments*/);
  }

private:
  double m_side{};
  Point m_center{};
  std::unique_ptr<DrawSquareStrategy> m_drawer{};
};
