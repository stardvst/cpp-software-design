#pragma once

#include <memory>
#include <vector>

class Shape;
void translateAllShapes(const std::vector<std::unique_ptr<Shape>> &shapes);
