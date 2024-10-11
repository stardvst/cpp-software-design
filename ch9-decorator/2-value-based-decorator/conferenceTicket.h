#pragma once

#include "money.h"
#include <string>
#include <utility>

class ConferenceTicket
{
public:
  explicit ConferenceTicket(std::string name, Money price)
      : m_name{std::move(name)}, m_price(price)
  {
  }

  const std::string &name() const { return m_name; }
  Money price() const { return m_price; }

private:
  std::string m_name{};
  Money m_price{};
};
