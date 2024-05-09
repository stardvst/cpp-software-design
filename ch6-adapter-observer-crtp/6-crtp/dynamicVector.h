#pragma once

#include <numeric>
#include <iosfwd>
#include <iterator>
#include <vector>
#include <initializer_list>
#include "denseVector.h"

template <typename T>
class DynamicVector : public DenseVector<DynamicVector<T>>
{
public:
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  DynamicVector() = default;
  DynamicVector(std::initializer_list<T> init)
      : m_values(std::begin(init), std::end(init))
  {
  }

  std::size_t size() const noexcept { return m_values.size(); }

  decltype(auto) operator[](std::size_t index)       noexcept { return m_values[index]; }
  decltype(auto) operator[](std::size_t index) const noexcept { return m_values[index]; }

  decltype(auto) begin()       noexcept { return m_values.begin(); }
  decltype(auto) begin() const noexcept { return m_values.begin(); }
  decltype(auto) end()         noexcept { return m_values.end(); }
  decltype(auto) end()   const noexcept { return m_values.end(); }

private:
  std::vector<T> m_values;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const DynamicVector<T> &vector)
{
  os << '(';
  for (const auto &element : vector)
    os << ' ' << element;
  os << " )";
  return os;
}

template <typename T>
auto l2norm(const DynamicVector<T> &vector)
{
  using std::begin, std::end;
  return std::sqrt(std::inner_product(begin(vector), end(vector), begin(vector), T{}));
}
