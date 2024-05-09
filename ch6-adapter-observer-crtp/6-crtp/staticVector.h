#pragma once

#include <numeric>
#include <iosfwd>
#include <iterator>
#include <array>
#include <initializer_list>
#include "denseVector.h"

template <typename T, std::size_t Size>
class StaticVector : public DenseVector<StaticVector<T, Size>>
{
public:
  using value_type = T;
  using iterator = typename std::array<T, Size>::iterator;
  using const_iterator = typename std::array<T, Size>::const_iterator;

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
