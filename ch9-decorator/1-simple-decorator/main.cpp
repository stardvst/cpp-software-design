#include "conferenceTicket.h"
#include "cppBook.h"
#include "discounted.h"
#include "taxed.h"

#include <cstdlib>
#include <memory>
#include <iostream>

int main()
{
  try
  {
    std::unique_ptr<Item> book = std::make_unique<CppBook>("Effective C++", Money{19.0});
    std::unique_ptr<Item> taxedBook = std::make_unique<Taxed>(0.07, std::move(book));
    const Money priceBook = taxedBook->price();
    std::cout << "Item1 costs " << taxedBook->price() << '\n';

    std::unique_ptr<Item> ticket = std::make_unique<ConferenceTicket>("CppCon", Money{999.0});
    std::unique_ptr<Item> discountedTicket = std::make_unique<Discounted>(0.2, std::move(ticket));
    std::unique_ptr<Item> discountedAndTaxedTicket = std::make_unique<Taxed>(0.19, std::move(discountedTicket));
    const Money priceTicket = discountedAndTaxedTicket->price();
    std::cout << "Item2 costs " << discountedAndTaxedTicket->price() << '\n';
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}
