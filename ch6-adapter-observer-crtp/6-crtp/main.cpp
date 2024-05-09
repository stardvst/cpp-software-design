#include <iostream>
#include "dynamicVector.h"
#include "staticVector.h"

int main()
{
  const DynamicVector<int> a{1, 2, 3};
  const StaticVector<int, 4UL> b{4, 5, 6, 7};

  std::cout << "a = " << a << ", L2-norm = " << l2norm(a) << '\n'
            << "b = " << b << ", L2-norm = " << l2norm(b) << '\n';
}
