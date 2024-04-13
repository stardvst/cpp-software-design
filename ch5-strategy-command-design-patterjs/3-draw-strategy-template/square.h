#pragma once

#include <memory>
#include <utility>
#include "drawStrategy.h"
#include "serializeStrategy.h"
#include "point.h"
#include "shape.h"

class Square : public Shape
{
public:
  explicit Square(double side, std::unique_ptr<DrawStrategy<Square>> drawer, std::unique_ptr<SerializeStrategy<Square>> serializer)
    : m_side(side)
    , m_drawer(std::move(drawer))
    , m_serializer(std::move(serializer))
  {
  }

  double side() const { return m_side; }
  Point center() const { return m_center; }

  void draw(/*some arguments*/) const override
  {
    m_drawer->draw(*this /*, some arguments*/);
  }

  void serialize(/*some arguments*/) const override
  {
    m_serializer->serialize(*this /*, some arguments*/);
  }

private:
  double m_side{};
  Point m_center{};
  std::unique_ptr<DrawStrategy<Square>> m_drawer{};
  std::unique_ptr<SerializeStrategy<Square>> m_serializer{};
};
