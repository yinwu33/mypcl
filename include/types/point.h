#pragma once

#include <memory>

namespace mypcl
{
struct Point {
  using Ptr = std::shared_ptr<Point>;

  float x, y, z;
  float intensity;
};

} // namespace mypcl
