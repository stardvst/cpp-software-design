#include <cstdlib>
#include "addressObserver.h"
#include "nameObserver.h"
#include "person.h"

int main()
{
  NameObserver nameObserver;
  AddressObserver addressObserver;

  Person homer{"Homer", "Simpson"};
  Person marge{"Marge", "Simpson"};
  Person monty{"Montgomery", "Burns"};

  homer.attach(&nameObserver);
  marge.attach(&addressObserver);
  monty.attach(&addressObserver);

  std::cout << "Changing Homer's name...\n";
  homer.setForename("Homer Jay");

  std::cout << "\nChanging Marge's address...\n";
  marge.setAddress("712 Red Bark Lane, Henderson, Clark County, Nevada 89011");

  std::cout << "\nChanging Montgomery's address...\n";
  monty.setAddress("Springfield Nuclear Power Plant");

  homer.detach(&nameObserver);
  std::cout << "\nChanging Homer Jay's name...\n";
  homer.setForename("Homer");
}
