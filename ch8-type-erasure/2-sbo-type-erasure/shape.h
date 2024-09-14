#pragma once

#include <array>
#include <cstdlib>
#include <memory>
#include <utility>

// A wrapper around the external hierarchy
template <std::size_t Capacity = 32U, std::size_t Alignment = alignof(void *)>
class Shape
{
public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer)
  {
    using Model = OwningModel<ShapeT, DrawStrategy>;

    static_assert(sizeof(Model) <= Capacity, "Given type is too large");
    static_assert(alignof(Model) <= Alignment, "Given type is misaligned");

    std::construct_at(static_cast<Model *>(pimpl()), std::move(shape), std::move(drawer));
  }

  Shape(const Shape &other)
  {
    other.pimpl()->clone(pimpl());
  }

  Shape &operator=(const Shape &other)
  {
    Shape copy(other);
    m_buffer.swap(copy.m_buffer);
    return *this;
  }

  Shape(Shape &&other) noexcept
  {
    other.pimpl()->move(pimpl());
  }

  Shape &operator=(Shape &&other) noexcept
  {
    Shape copy(std::move(other));
    m_buffer.swap(copy.m_buffer);
    return *this;
  }

  ~Shape()
  {
    std::destroy_at(pimpl());
  }

private:
  friend void draw(const Shape &shape)
  {
    shape.pimpl()->draw();
  }

  struct Concept // The External Polymorphism design pattern
  {
    virtual ~Concept() = default;
    virtual void draw() const = 0;
    virtual void clone(Concept *memory) const = 0;
    virtual void move(Concept *memory) = 0;
  };

  template <typename ShapeT, typename DrawStrategy>
  class OwningModel : public Concept
  {
  public:
    explicit OwningModel(ShapeT shape, DrawStrategy drawer)
      : m_shape(std::move(shape))
      , m_drawer(std::move(drawer))
    {}

    void draw() const override { m_drawer(m_shape); }

    void clone(Concept *memory) const override
    {
      std::construct_at(static_cast<OwningModel *>(memory), *this);
    }

    void move(Concept *memory) override
    {
      std::construct_at(static_cast<OwningModel *>(memory), std::move(*this));
    }

  private:
    ShapeT m_shape;
    DrawStrategy m_drawer;
  };

  Concept *pimpl() // The Bridge design pattern
  {
    return reinterpret_cast<Concept *>(m_buffer.data());
  }

  const Concept *pimpl() const
  {
    return reinterpret_cast<const Concept *>(m_buffer.data());
  }

  alignas(Alignment) std::array<std::byte, Capacity> m_buffer{};
};
