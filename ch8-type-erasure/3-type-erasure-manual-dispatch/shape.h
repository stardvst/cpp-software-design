#pragma once

#include <cstddef>
#include <memory>

class Shape
{
public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer)
      : m_drawer([](void *shapeBytes)
                 { using Model = OwningModel<ShapeT, DrawStrategy>;
                const auto *model = static_cast<Model *>(shapeBytes);
                (*model->m_drawer)(model->m_shape); }),
        m_cloner([](void *shapeBytes) -> void *
                 { using Model = OwningModel<ShapeT, DrawStrategy>;
                const auto *model = static_cast<Model *>(shapeBytes);
                return new Model(*model); }),
        m_pimpl(new OwningModel<ShapeT, DrawStrategy>(std::move(shape), std::move(drawer)),
                [](void *shapeBytes)
                { using Model = OwningModel<ShapeT, DrawStrategy>;
                const auto *model = static_cast<Model *>(shapeBytes);
                delete model; })
  {
  }

  Shape(const Shape &other)
      : m_cloner(other.m_cloner), m_drawer(other.m_drawer), m_pimpl(other.m_cloner(other.m_pimpl.get()), other.m_pimpl.get_deleter())
  {
  }

  Shape &operator=(const Shape &other)
  {
    using std::swap;
    Shape copy(other);
    swap(m_pimpl, copy.m_pimpl);
    swap(m_drawer, copy.m_drawer);
    swap(m_cloner, copy.m_cloner);
    return *this;
  }

  ~Shape() = default;
  Shape(Shape &&) = default;
  Shape &operator=(Shape &&) = default;

private:
  friend void draw(const Shape &shape)
  {
    shape.m_drawer(shape.m_pimpl.get());
  }

  template <typename ShapeT, typename DrawStrategy>
  struct OwningModel
  {
    OwningModel(ShapeT shape, DrawStrategy drawer)
        : m_shape(shape), m_drawer(drawer)
    {
    }

    ShapeT m_shape;
    DrawStrategy m_drawer;
  };

  using DestroyOperation = void(void *);
  using DrawOperation = void(void *);
  using CloneOperation = void *(void *);

  DrawOperation *m_drawer{nullptr};
  CloneOperation *m_cloner{nullptr};
  std::unique_ptr<void, DestroyOperation *> m_pimpl;
};
