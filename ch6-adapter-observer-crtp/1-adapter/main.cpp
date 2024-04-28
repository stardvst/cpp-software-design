#include <iostream>
#include "pages.h"

int main()
{
  Pages pages;

  pages.exportToJSON();
  pages.serialize();
}
