#include "distances.h"
#include "person.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
  const auto m1 = Meter<long>{120L};
  const auto m2 = Meter<long>{50L};
  const auto m3 = m1 + m2;
  std::cout << m3.get() << '\n';

  // wrong: shouldn't be possible to add surnames
  const auto surname1 = Surname{"Stroustrup"};
  const auto surname2 = Surname{"Iglberger"};
  const auto surname3 = surname1 + surname2;
  std::cout << surname3.get() << '\n';
}
