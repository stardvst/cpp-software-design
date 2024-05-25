#include "strongType.h"
#include "swappable.h"
#include "printable.h"

using Surname = StrongType<std::string, struct SurnameTag, Printable, Swappable>;
