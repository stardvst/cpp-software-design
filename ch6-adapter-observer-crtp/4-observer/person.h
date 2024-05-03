#pragma once

#include <string>
#include <set>
#include "observer.h"

class Person
{
public:
  enum StateChange
  {
    forenameChanged,
    surnameChanged,
    addressChanged
  };

  using PersonObserver = Observer<Person, StateChange>;

  explicit Person(std::string forename, std::string surname)
      : m_forename(std::move(forename)), m_surname(std::move(surname))
  {
  }

  bool attach(PersonObserver *observer)
  {
    auto [pos, success] = m_observers.insert(observer);
    return success;
  }

  bool detach(PersonObserver *observer)
  {
    return (m_observers.erase(observer) > 0U);
  }

  void notify(StateChange property)
  {
    for (auto it = begin(m_observers); it != end(m_observers);)
    {
      const auto pos = it++;
      (*pos)->update(*this, property);
    }
  }

  void setForename(std::string newForename)
  {
    m_forename = newForename;
    notify(StateChange::forenameChanged);
  }

  void setSurname(std::string newSurname)
  {
    m_surname = newSurname;
    notify(StateChange::surnameChanged);
  }

  void setAddress(std::string newAddress)
  {
    m_address = newAddress;
    notify(StateChange::addressChanged);
  }

  const std::string &getForename() const { return m_forename; }
  const std::string &getSurname() const { return m_surname; }
  const std::string &getAddress() const { return m_address; }

private:
  std::string m_forename{};
  std::string m_surname{};
  std::string m_address{};

  std::set<PersonObserver *> m_observers{};
};
