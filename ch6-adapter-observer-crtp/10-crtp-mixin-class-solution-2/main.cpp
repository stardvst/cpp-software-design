#include "distances.h"
#include "person.h"
#include "swappable.h"
#include "strongType.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
  const auto m1 = Meter<long>{120L};
  const auto m2 = Meter<long>{50L};
  const auto m3 = m1 + m2;
  std::cout << m3 << '\n';

  // wrong: shouldn't be possible to add surnames
  auto surname1 = Surname{"Stroustrup"};
  auto surname2 = Surname{"Iglberger"};
  swap(surname1, surname2);
  // const auto surname3 = surname1 + surname2; // won't compile - correct
  std::cout << surname1 << ' ' << surname2 << '\n';
}
