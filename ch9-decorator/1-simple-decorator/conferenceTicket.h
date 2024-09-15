#pragma once

#include "item.h"

class ConferenceTicket : public Item
{
public:
  explicit ConferenceTicket(std::string name, Money price)
      : m_name{std::move(name)}, m_price(price)
  {
  }

  const std::string &name() const { return m_name; }
  Money price() const override { return m_price; }

private:
  std::string m_name{};
  Money m_price{};
};
