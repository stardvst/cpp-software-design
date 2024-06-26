#include "person.h"
#include <string>
#include <iostream>

int main()
{
  Person p1{"firstname", "lastname"};
  Person p2{std::move(p1)};

  std::cout << p1.getForename() << '\n';
  std::cout << p1.getSurname() << '\n';

  std::cout << p2.getForename() << '\n';
  std::cout << p2.getSurname() << '\n';
}
