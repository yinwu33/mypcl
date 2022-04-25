#pragma once

#include "types/cloud.h"

namespace mypcl
{

class KDTree {
public:
  KDTree();

  void SetInputCloud(const Cloud::Ptr& pCloud);

};

} // namespace my_
