#pragma once

#include <variant>
#include <vector>
#include "circle.h"
#include "square.h"

using Shape = std::variant<Circle, Square>;
using Shapes = std::vector<Shape>;
