#pragma once

#include <cmath>
#include <concepts>
#include <ostream>

struct Money
{
  double value{};
};

template <typename T>
  requires std::is_arithmetic_v<T>
Money operator*(Money money, T factor)
{
  return Money{money.value * factor};
}

constexpr Money operator+(Money lhs, Money rhs) noexcept
{
  return Money{lhs.value + rhs.value};
}

std::ostream &operator<<(std::ostream &os, Money money)
{
  return os << money.value;
}
