#include <iostream>

class OpenPages
{
public:
  void convertToBytes(/* args*/) const
  {
    std::cout << "API: OpenPages::convertToBytes()\n";
  }
};

inline void exportToJSONFormat(const OpenPages &pages/*, args*/)
{
  std::cout << "API: exportToJSONFormat(const OpenPages &)\n";
}
