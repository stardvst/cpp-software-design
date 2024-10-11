#pragma once

#include "money.h"

template <typename T>
concept PricedItem = requires(T item) {
  { item.price() } -> std::same_as<Money>;
};
