#include "io.h"

#include <iostream>
#include <fstream>

namespace mypcl
{
void readBin(const std::string& file, Eigen::MatrixXf& cloud) {
  Cloud temp;
  readBin(file, temp);

  size_t numPoints = temp.size();

  cloud.resize(numPoints, 3);
  for (size_t i = 0; i < numPoints; ++i) {
    cloud.block(i, 0, 1, 3) << temp[i].x, temp[i].y, temp[i].z;
  }
}

void readBin(const std::string& file, mypcl::Cloud& cloud) {
  cloud.clear();

  std::fstream ifs(file, std::ios::in | std::ios::binary);

  if (!ifs.good()) {
    std::cerr << "Could not read file: " << file << std::endl;
    std::exit(EXIT_FAILURE);
  }

  ifs.seekg(0, std::ios::beg);

  for (size_t i = 0; ifs.good() and !ifs.eof(); ++i) {
    float temp[4];
    ifs.read((char*)&temp, 4 * sizeof(float));
    Point tempPoint;
    tempPoint.x = temp[0];
    tempPoint.y = temp[1];
    tempPoint.z = temp[2];
    tempPoint.intensity = temp[3];

    cloud.push_back(tempPoint);
  }
  ifs.close();
  std::cout << cloud.size() << " points read!" << std::endl;
}

} // namespace mypcl

