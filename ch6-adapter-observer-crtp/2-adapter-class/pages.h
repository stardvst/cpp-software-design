#include <iostream>
#include "document.h"
#include "openPagesApi.h"

class Pages
    : public Document,
      private OpenPages
{
public:
  void exportToJSON(/* args */) const override
  {
    std::cout << "Pages::exportToJSON() ->\n";
    exportToJSONFormat(*this);
    std::cout << "-> converted to JSON\n";
  }

  void serialize(/* args */) const override
  {
    std::cout << "Pages::serialize() ->\n";
    this->convertToBytes();
    std::cout << "-> serialized into bytes\n";
  }
};
