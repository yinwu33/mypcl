#pragma once

#include <vector>
#include <memory>
#include <Eigen/Dense>

#include "types/point.h"


namespace mypcl
{

struct Cloud {

  using Ptr = std::shared_ptr<Cloud>;

  Cloud() : computeMatrix(false) {}

public:
  inline int size() { return points_.size(); }

  inline void clear() { points_.clear(); }

  inline Point& operator[](int i) { return points_[i]; }

  inline void push_back(const Point& p) { points_.emplace_back(p); }

  const Eigen::MatrixXf& matrix();

private:

  std::vector<Point> points_;

  Eigen::MatrixXf matrix_;

  bool computeMatrix;
};

} // namespace mypcl
