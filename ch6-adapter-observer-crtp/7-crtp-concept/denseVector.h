#pragma once

#include <concepts>
#include <ostream>

struct DenseVectorTag
{
};

template <typename T>
struct IsDenseVector : public std::is_base_of<DenseVectorTag, T>
{
};

template <typename T>
constexpr bool IsDenseVector_v = IsDenseVector<T>::value;

template <typename T>
concept DenseVector =
    requires(T t, std::size_t index) {
      t.size();
      t[index];
      { t.begin() } -> std::same_as<typename T::iterator>;
      { t.end() } -> std::same_as<typename T::iterator>;
    } &&
    requires(const T t, std::size_t index) {
      t.size();
      t[index];
      { t.begin() } -> std::same_as<typename T::const_iterator>;
      { t.end() } -> std::same_as<typename T::const_iterator>;
    } &&
    IsDenseVector_v<T>;

template <DenseVector ActualVector>
std::ostream &operator<<(std::ostream &os, const ActualVector &vector)
{
  const size_t size(vector.size());

  os << "(";
  for (size_t i = 0UL; i < size; ++i)
  {
    os << " " << vector[i];
  }
  os << " )";

  return os;
}

template <DenseVector ActualVector>
decltype(auto) l2norm(const ActualVector &vector)
{
  using T = typename ActualVector::value_type;
  return std::sqrt(std::inner_product(std::begin(vector), std::end(vector), std::begin(vector), T{}));
}
