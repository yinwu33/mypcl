#include "base.h"

namespace mypcl
{

class Voxelization : Base {
public:
  Voxelization(int resolution, int leafSize);

private:
  int resolution_;
  int leafSize_;
};

} // namespace mypcl
