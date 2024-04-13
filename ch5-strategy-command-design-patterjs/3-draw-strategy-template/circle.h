#pragma once

#include <memory>
#include <utility>
#include "drawStrategy.h"
#include "serializeStrategy.h"
#include "point.h"
#include "shape.h"

class Circle : public Shape
{
public:
  Circle(double radius, std::unique_ptr<DrawStrategy<Circle>> drawer, std::unique_ptr<SerializeStrategy<Circle>> serializer)
    : m_radius(radius)
    , m_drawer(std::move(drawer))
    , m_serializer(std::move(serializer))
  {
  }

  double radius() const { return m_radius; }
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
  double m_radius{};
  Point m_center{};
  std::unique_ptr<DrawStrategy<Circle>> m_drawer{};
  std::unique_ptr<SerializeStrategy<Circle>> m_serializer{};
};
