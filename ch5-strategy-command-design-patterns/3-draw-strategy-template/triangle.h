#pragma once

#include <memory>
#include <utility>
#include "drawStrategy.h"
#include "serializeStrategy.h"
#include "point.h"
#include "shape.h"

class Triangle : public Shape
{
public:
  explicit Triangle(Point p1, Point p2, Point p3, std::unique_ptr<DrawStrategy<Triangle>> drawer, std::unique_ptr<SerializeStrategy<Triangle>> serializer)
    : m_p1(std::move(p1)), m_p2(std::move(p2)), m_p3(std::move(p3))
    , m_drawer(std::move(drawer))
    , m_serializer(std::move(serializer))
  {
  }

  Point p1() const { return m_p1; }
  Point p2() const { return m_p2; }
  Point p3() const { return m_p3; }

  void draw(/*some arguments*/) const override
  {
    m_drawer->draw(*this /*, some arguments*/);
  }

  void serialize(/*some arguments*/) const override
  {
    m_serializer->serialize(*this /*, some arguments*/);
  }

private:
  Point m_p1{}, m_p2{}, m_p3{};
  std::unique_ptr<DrawStrategy<Triangle>> m_drawer{};
    std::unique_ptr<SerializeStrategy<Triangle>> m_serializer{};
};
