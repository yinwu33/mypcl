#include <string>
#include <gtest/gtest.h>

#include "io.h"
#include "pca.h"

using namespace std;
using namespace mypcl;


TEST(TEST_PCA, PCA) {
  string file = "../test/000000.bin";

  Cloud cloud;
  readBin(file, cloud);
  PCA pca;
  pca.setInputCloud(cloud);
  Eigen::Vector3f z1, z2, z3;
  z1 = pca.getPrincicpleComponent(0);
  z2 = pca.getPrincicpleComponent(1);
  z3 = pca.getPrincicpleComponent(2);

  std::cout << "1. components: " << z1.transpose() << std::endl;
  std::cout << "2. components: " << z2.transpose() << std::endl;
  std::cout << "3. components: " << z3.transpose() << std::endl;

  Eigen::Vector3f eigenvalues;
  eigenvalues = pca.getEigenValue();
  std::cout << "1. eigenvalue: " << eigenvalues[2] << std::endl;
  std::cout << "2. eigenvalue: " << eigenvalues[1] << std::endl;
  std::cout << "3. eigenvalue: " << eigenvalues[0] << std::endl;
}