#include <string>
#include <gtest/gtest.h>
#include <Eigen/Core>

#include "io.h"

using namespace std;
using namespace mypcl;
TEST(TEST_IO, READ_BIN_EIGEN) {
  string file = "../test/000000.bin";
  
  Eigen::MatrixXf cloud;
  readBin(file, cloud);
}

TEST(TEST_IO, READ_BIN_CLOUD) {
  string file = "../test/000000.bin";
  
  Cloud cloud;
  readBin(file, cloud);
}