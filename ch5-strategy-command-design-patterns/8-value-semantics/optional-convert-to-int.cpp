#include <charconv>
#include <cstdlib>
#include <optional>
#include <sstream>
#include <iostream>
#include <string>
#include <string_view>

std::optional<int> toInt(std::string_view sv)
{
  std::optional<int> oi{};
  int i{};

  const auto result = std::from_chars(sv.data(), sv.data() + sv.size(), i);
  if (result.ec != std::errc::invalid_argument)
    oi = i;

  return oi;
}

int main()
{
  std::string value = "42";

  if (auto optionalInt = toInt(value))
    std::cout << "converted " << value << " to " << *optionalInt << '\n';
  else
    std::cout << "conversion of " << value << " failed\n";

  value = "0";
  if (auto optionalInt = toInt(value))
    std::cout << "converted " << value << " to " << *optionalInt << '\n';
  else
    std::cout << "conversion of " << value << " failed\n";

  value = "forty-two";
  if (auto optionalInt = toInt(value))
    std::cout << "converted " << value << " to " << *optionalInt << '\n';
  else
    std::cout << "conversion of " << value << " failed\n";
}
