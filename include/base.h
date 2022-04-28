#include "types/cloud.h"


namespace mypcl
{

class Base {
public:
  void setInputCloud(const Cloud& cloud) {
    cloud_ = cloud;
  }

private:
  Cloud cloud_;
};

} // namespace mypcl
