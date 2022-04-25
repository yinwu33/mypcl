#pragma once

#include <string>

#include <Eigen/Core>
#include <Eigen/Dense>

#include "types/cloud.h"


namespace mypcl
{
void readBin(const std::string& file, Eigen::MatrixXf& cloud);

void readBin(const std::string& file, mypcl::Cloud& cloud);
  
} // namespace mypcl
