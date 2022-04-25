#include "types/cloud.h"

namespace mypcl
{
const Eigen::MatrixXf& Cloud::matrix() {
  if (computeMatrix)
    return matrix_;

  matrix_.resize(size(), 3);

  for (size_t i = 0; i < size(); ++i) {
    matrix_.block(i, 0, 1, 3) << points_[i].x, points_[i].y, points_[i].z;
  }
  return matrix_;
}
} // namespace mypcl
