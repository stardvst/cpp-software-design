#include "distances.h"
#include "person.h"
#include <cstdlib>
#include <string>

int main()
{
  const auto m1 = Meter<long>{120L};
  const auto m2 = Meter<long>{50L};
  const auto km = Kilometer<long>{30L};
  const auto surname1 = Surname{"Stroustrup"};
  const auto surname2 = Surname{"Iglberger"};

  // m1 + km; // doesn't compile: correct
  // surname1 + surname2; // doesn't compile: correct
  // m1 + m2; // doesn't compile: incorrect

  // overloading operator+ for StrongType would allow addition of two surnames - wrong
}
