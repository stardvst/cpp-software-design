#include <iostream>
#include "observer.h"
#include "person.h"

class NameObserver : public Observer<Person, Person::StateChange>
{
public:
  void update(const Person &person, Person::StateChange property) override
  {
    if (property == Person::forenameChanged || property == Person::surnameChanged)
    {
      std::cout << "person's forename or surname is changed to: " << person.getForename() << ", " << person.getSurname() << '\n';
    }
  }
};
