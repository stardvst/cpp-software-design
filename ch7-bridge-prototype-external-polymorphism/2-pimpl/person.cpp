#include "person.h"
#include <string>
#include <utility>

struct Person::PersonImpl
{
  std::string forename;
  std::string surname;
  std::string address;
  std::string city;
  std::string zip;
  int yearOfBirth;
  // ...

  PersonImpl(std::string f, std::string s)
      : forename(std::move(f)), surname(std::move(s))
  {
  }
};

Person::Person(std::string forename, std::string surname)
    : m_personImpl{std::make_unique<PersonImpl>(std::move(forename), std::move(surname))}
{
}

// !
Person::~Person() = default;

Person::Person(const Person &other)
    : m_personImpl{std::make_unique<PersonImpl>(*other.m_personImpl)}
{
}

Person &Person::operator=(const Person &other)
{
  *m_personImpl = *other.m_personImpl;
  return *this;
}

Person::Person(Person &&other)
    : m_personImpl{std::make_unique<PersonImpl>(std::move(*other.m_personImpl))}
{
}

Person &Person::operator=(Person &&other)
{
  *m_personImpl = std::move(*other.m_personImpl);
  return *this;
}

std::string Person::getForename() const
{
  return m_personImpl->forename;
}

std::string Person::getSurname() const
{
  return m_personImpl->surname;
}
