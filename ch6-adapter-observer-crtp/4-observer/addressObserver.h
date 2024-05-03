#include <iostream>
#include "observer.h"
#include "person.h"

class AddressObserver : public Observer<Person, Person::StateChange>
{
public:
  void update(const Person &person, Person::StateChange property) override
  {
    if (property == Person::addressChanged)
    {
      std::cout << "person's address or surname is changed to: " << person.getAddress() << '\n';
    }
  }
};
