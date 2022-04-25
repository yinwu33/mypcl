#pragma once

#include <Eigen/Core>

#include "types/cloud.h"

namespace mypcl
{

class PCA {
public:
  PCA() : computeDone_(false) {}
  PCA(const Eigen::MatrixXf& m) : computeDone_(false), cloud_(m) {};

  // void setInputCloud(Eigen::MatrixXf& m) { cloud_ = m; };
  void setInputCloud(Cloud& cloud) { cloud_ = cloud.matrix(); };

  inline const Eigen::Matrix3f& getEigenVector() {
    if (!computeDone_)
      compute();

    return eigenvectors_;
  }

  inline const Eigen::Vector3f& getEigenValue() {
    if (!computeDone_)
      compute();

    return eigenvalues_;
  }

  /**
   * @brief Get the Princicple Component object
   *
   * @param i : 0, 1, 2
   * @return const Eigen::Vector3f&
   */
  inline Eigen::Vector3f getPrincicpleComponent(int i) {
    assert(i == 0 or i == 1 or i == 2);
    return eigenvectors_.col(2 - i);
  }

private:
  void compute();

private:
  bool computeDone_;

  Eigen::MatrixXf cloud_;

  Eigen::Vector3f mean_;
  Eigen::Matrix3f eigenvectors_;
  Eigen::Vector3f eigenvalues_;

};

} // namespace mypcl
