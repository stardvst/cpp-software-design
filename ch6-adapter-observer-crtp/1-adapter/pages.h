#include <iostream>
#include "document.h"
#include "openPagesApi.h"

class Pages : public Document
{
  public:
    void exportToJSON(/* args */) const override
    {
      std::cout << "Pages::exportToJSON() ->\n";
      exportToJSONFormat(m_pages);
      std::cout << "-> converted to JSON\n";
    }

    void serialize(/* args */) const override
    {
      std::cout << "Pages::serialize() ->\n";
      m_pages.convertToBytes();
      std::cout << "-> serialized into bytes\n";
    }

private:
  OpenPages m_pages;
};
