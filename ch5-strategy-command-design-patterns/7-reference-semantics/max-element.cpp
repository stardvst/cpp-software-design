#include <cstdlib>
#include <iostream>
#include <span>
#include <vector>

void print(std::vector<int> v)
{
  std::cout << "(";
  for (int i : v)
    std::cout << ' ' << i;
  std::cout << " )\n";
}

int main()
{
  std::vector v{1, -3, 27, 42, 4, -8, 22, 42, 37, 4, 18, 9};
  const auto pos = std::max_element(begin(v), end(v));
  v.erase(std::remove(begin(v), end(v), *pos), end(v));
  print(v);

  std::vector w{1, -3, 27, 42, 4, -8, 22, 42, 37, 4, 18, 9};
  const auto max = std::max_element(begin(w), end(w));
  const auto greatest = *max;
  w.erase(std::remove(begin(w), end(w), greatest), end(w));
  print(w);
}
