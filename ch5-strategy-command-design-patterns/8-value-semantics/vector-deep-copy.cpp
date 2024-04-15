#include <cassert>
#include <iostream>
#include <span>
#include <vector>

void print(std::span<int> s)
{
  std::cout << "(";
  for (int i : s)
    std::cout << ' ' << i;
  std::cout << " )\n";
}

int main()
{
  std::vector v1{1, 2, 3, 4, 5};

  auto v2{v1}; // a real (deep) copy!

  assert(v1 == v2);
  assert(v1.data() != v2.data());

  v2[2] = 99;
  assert(v1 != v2);

  const auto v3{v1};
  //v3[2] = 99;
}
