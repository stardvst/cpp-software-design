#pragma once

#include "decoratedItem.h"

class Discounted : public DecoratedItem
{
public:
  explicit Discounted(double discount, std::unique_ptr<Item> item)
      : DecoratedItem(std::move(item)), m_factor{1 - discount}
  {
    if (!std::isfinite(discount) || discount < 0.0 || discount > 1.0)
      throw std::invalid_argument("Invalid discount");
  }

  Money price() const override
  {
    return item().price() * m_factor;
  }

private:
  double m_factor{};
};
