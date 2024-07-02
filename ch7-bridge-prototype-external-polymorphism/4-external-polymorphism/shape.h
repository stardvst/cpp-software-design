#pragma once

#include <functional>
#include <stdexcept>
#include <utility>

class ShapeConcept
{
public:
  virtual ~ShapeConcept() = default;

  virtual void draw() const = 0;

  /// ... other methods
};

template <typename ShapeT, typename DrawStrategy>
class ShapeModel : public ShapeConcept
{
public:
  // using DrawStrategy = std::function<void(const ShapeT &)>;

  explicit ShapeModel(ShapeT shape, DrawStrategy drawer)
      : m_shape(std::move(shape)), m_drawer(std::move(drawer))
  {
  }

  void draw() const override { m_drawer(m_shape); }

  /// ... other methods

private:
  ShapeT m_shape{};
  DrawStrategy m_drawer{};
};
