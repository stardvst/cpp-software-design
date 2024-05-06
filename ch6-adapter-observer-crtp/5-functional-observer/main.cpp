#include <cstdlib>
#include <iostream>
#include "person.h"

void propertyChanged(const Person &person, Person::StateChange property)
{
  if (property == Person::forenameChanged || property == Person::surnameChanged)
  {
    std::cout << "person's forename or surname is changed to: " << person.getForename() << ", " << person.getSurname() << '\n';
  }
}

int main()
{
  using PersonObserver = Observer<Person, Person::StateChange>;

  PersonObserver nameObserver(propertyChanged);
  PersonObserver addressObserver([](const Person &person, Person::StateChange property)
                                 {
    if (property == Person::addressChanged)
    {
      std::cout << "person's address is changed to: " << person.getAddress() << '\n';
    } });

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
