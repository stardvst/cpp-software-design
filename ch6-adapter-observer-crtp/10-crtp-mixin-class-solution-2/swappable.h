#pragma once

#include <utility>

template <typename Derived>
struct Swappable
{
  friend void swap(Derived &lhs, Derived &rhs)
  {
    using std::swap;
    swap(lhs.get(), rhs.get());
  }
};
