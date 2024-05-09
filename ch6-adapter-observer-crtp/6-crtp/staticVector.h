#pragma once

#include <numeric>
#include <iosfwd>
#include <iterator>
#include <array>
#include <initializer_list>

template <typename T, std::size_t Size>
class StaticVector
{
public:
  // using value_type = T;
  // using iterator = typename std::array<T, Size>::iterator;
  // using const_iterator = typename std::array<T, Size>::const_iterator;

  StaticVector() = default;
  StaticVector(std::initializer_list<T> init)
  {
    std::copy(std::begin(init), std::end(init), std::begin(m_values));
  }

  std::size_t size() const noexcept { return m_values.size(); }

  decltype(auto) operator[](std::size_t index)       noexcept { return m_values[index]; }
  decltype(auto) operator[](std::size_t index) const noexcept { return m_values[index]; }

  decltype(auto) begin()       noexcept { return m_values.begin(); }
  decltype(auto) begin() const noexcept { return m_values.begin(); }
  decltype(auto) end()         noexcept { return m_values.end(); }
  decltype(auto) end()   const noexcept { return m_values.end(); }

private:
  std::array<T, Size> m_values;
};

template <typename T, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const StaticVector<T, Size> &vector)
{
  os << '(';
  for (const auto &element : vector)
    os << ' ' << element;
  os << " )";
  return os;
}

template <typename T, std::size_t Size>
auto l2norm(const StaticVector<T, Size> &vector)
{
  using std::begin, std::end;
  return std::sqrt(std::inner_product(begin(vector), end(vector), begin(vector), T{}));
}
