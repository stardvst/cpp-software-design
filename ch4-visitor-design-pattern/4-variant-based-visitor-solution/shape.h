#pragma once

#include <variant>
#include <vector>
#include "circle.h"
#include "square.h"
#include "triangle.h"

using Shape = std::variant<Circle, Square, Triangle>;
using Shapes = std::vector<Shape>;
