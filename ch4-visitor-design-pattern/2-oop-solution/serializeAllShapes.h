#pragma once

#include <memory>
#include <vector>

class Shape;
void serializeAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes);
