#pragma once

#include "pricedItem.h"

template <PricedItem Item>
class Discounted // using composition
{
public:
  template <typename... Args>
  explicit Discounted(double discount, Args &&...args)
      : m_item{std::forward<Args>(args)...}, m_discount{discount}
  {
  }

  Money price() const
  {
    return m_item.price() * (1 - m_discount);
  }

private:
  Item m_item{};
  double m_discount{};
};
