#pragma once

#include "money.h"
#include "pricedItem.h"
#include <utility>

template <PricedItem Item>
class Taxed : private Item // using inheritance
{
public:
  template <typename... Args>
  explicit Taxed(double taxRate, Args &&...args)
      : Item{std::forward<Args>(args)...}, m_taxRate{taxRate}
  {
  }

  Money price() const
  {
    return Item::price() * (1 + m_taxRate);
  }

private:
  double m_taxRate{};
};
