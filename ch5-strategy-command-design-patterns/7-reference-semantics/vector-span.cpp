#include <cstdlib>
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
  std::vector v{1, 2, 3, 4};

  const std::vector w{v};
  const std::span s{v}; // same as: int *const ptr{v.data()};

  //w[2] = 99;
  s[2] = 99;
  print(s); // 1 2 99 4

  v = {5, 6, 7, 8, 9};
  print(s); // 0 0 0 0
  s[2] = 99;
  print(s); // 0 0 99 0
}
