#include "pca.h"
#include <Eigen/Dense>


namespace mypcl
{

void PCA::compute() {
  mean_ = cloud_.colwise().mean();

  Eigen::MatrixXf normalizedMatrix = cloud_.rowwise() - mean_.transpose();

  Eigen::Matrix3f H = normalizedMatrix.transpose() * normalizedMatrix;

  Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> eigensolver(H);

  eigenvalues_ = eigensolver.eigenvalues().real();
  eigenvectors_ = eigensolver.eigenvectors().real();

  computeDone_ = true;
}
} // namespace mypcl
