#pragma once

#include <memory>
#include <utility>

namespace detail
{

class ShapeConcept
{
public:
  virtual ~ShapeConcept() = default;
  virtual void draw() const = 0;
  virtual bool isEqual(const ShapeConcept *sc) const = 0;
  virtual std::unique_ptr<ShapeConcept> clone() const = 0;
};

template <typename ShapeT, typename DrawStrategy>
class OwningShapeModel : public ShapeConcept
{
public:
  explicit OwningShapeModel(ShapeT shape, DrawStrategy drawer)
    : m_shape(shape)
    , m_drawer(drawer)
  {}

  void draw() const override { m_drawer(m_shape); }

  bool isEqual(const ShapeConcept *sc) const override
  {
    using Model = OwningShapeModel<ShapeT, DrawStrategy>;
    const auto *model = dynamic_cast<const Model *>(sc);
    return (model && m_shape == model->m_shape);
  }

  std::unique_ptr<ShapeConcept> clone() const override
  {
    return std::make_unique<OwningShapeModel>(*this);
  }

private:
  ShapeT m_shape;
  DrawStrategy m_drawer;
};

} // namespace detail

// A wrapper around the external hierarchy
class Shape
{
public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer)
  {
    using Model = detail::OwningShapeModel<ShapeT, DrawStrategy>;
    m_pimpl = std::make_unique<Model>(std::move(shape), std::move(drawer));
  }

  Shape(const Shape &other)
    : m_pimpl(other.m_pimpl->clone())
  {}

  Shape &operator=(const Shape &other)
  {
    Shape copy(other);
    m_pimpl.swap(copy.m_pimpl);
    return *this;
  }

  ~Shape() = default;
  Shape(Shape &&) = default;
  Shape &operator=(Shape &&) = default;

private:
  friend void draw(const Shape &shape)
  {
    shape.m_pimpl->draw();
  }

  friend bool operator==(const Shape &lhs, const Shape &rhs)
  {
    return lhs.m_pimpl->isEqual(rhs.m_pimpl.get());
  }

  friend bool operator!=(const Shape &lhs, const Shape &rhs)
  {
    return !(lhs == rhs);
  }

  std::unique_ptr<detail::ShapeConcept> m_pimpl{};
};
