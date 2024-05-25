#pragma once

#include "strongType.h"
#include "addable.h"
#include "swappable.h"
#include "printable.h"

template <typename T>
using Meter = StrongType<T, struct MeterTag, Addable, Printable, Swappable>;

template <typename T>
using Kilometer = StrongType<T, struct KilometerTag, Addable, Printable, Swappable>;
