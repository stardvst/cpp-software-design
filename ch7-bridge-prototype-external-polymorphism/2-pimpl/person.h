#pragma once

#include <memory>

class Person
{
public:
  Person(std::string forename, std::string surname);
  ~Person();

  Person(const Person &other);
  Person &operator=(const Person &other);

  Person(Person &&other);
  Person &operator=(Person &&other);

  std::string getForename() const;
  std::string getSurname() const;
  // ...

private:
  struct PersonImpl;
  std::unique_ptr<PersonImpl> const m_personImpl;
};
