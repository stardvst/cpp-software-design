#include "conferenceTicket.h"
#include "cppBook.h"
#include "discounted.h"
#include "taxed.h"

#include <iostream>

int main()
{
  Discounted<ConferenceTicket> discountedItem{0.2, "Core C++", Money{499.0}}; // Create the discounted item first
  Taxed<Discounted<ConferenceTicket>> taxedItem{0.15, discountedItem}; // Wrap the discounted item with tax

  const Money priceBook = taxedItem.price();
  std::cout << "Item costs " << priceBook << '\n';
}

