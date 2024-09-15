#pragma once

#include "decoratedItem.h"

class Taxed : public DecoratedItem
{
public:
  explicit Taxed(double taxRate, std::unique_ptr<Item> item)
      : DecoratedItem(std::move(item)), m_factor{1 + taxRate}
  {
    if (!std::isfinite(taxRate) || taxRate < 0.0)
      throw std::invalid_argument("Invalid tax");
  }

  Money price() const override
  {
    return item().price() * m_factor;
  }

private:
  double m_factor{};
};
