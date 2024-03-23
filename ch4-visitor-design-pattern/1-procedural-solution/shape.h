#pragma once

enum class ShapeType
{
  circle,
  square
};

class Shape
{
public:
  virtual ~Shape() = default;
  ShapeType getType() const { return m_type; }

protected:
  explicit Shape(ShapeType type) : m_type(type) {}

private:
  ShapeType m_type{};
};
