#pragma once

class CppBook
{
public:
  explicit CppBook(std::string title, Money price)
      : m_title{std::move(title)}, m_price(price)
  {
  }

  const std::string &title() const { return m_title; }
  Money price() const { return m_price; }

private:
  std::string m_title{};
  Money m_price{};
};
