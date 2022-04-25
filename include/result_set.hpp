#pragma once

#include <vector>

namespace mypcl
{

template <typename ElemType>
struct DistIndex {
  DistIndex(ElemType distance, int index) : distance(distance), index(index) {}

  ElemType distance;
  int index;

  bool operator < (const DistIndex& other) {
    return distance < other.distance;
  }
};

template <typename ElemType>
class KNNResultSet {
public:
  explicit KNNResultSet(int capacity) : capacity_(capacity) {
    distIndexList_.reserve(capacity_);

    for (size_t i = 0; i < capacity_; ++i) {
      distIndexList_.emplace_back(DistIndex<ElemType>(worstDist_, 0));
    }
  }

  inline int Size() { return count_; }

  inline bool IsFull() { return count_ == capacity_; }

  inline ElemType GetWorstDist() { return worstDist_; }

  inline void GetResult(std::vector<int>& indexList, std::vector<ElemType>& distList) {
    indexList.clear();
    distList.clear();
    for (const DistIndex<ElemType>& d : distIndexList_) {
      indexList.emplace_back(d.index);
      distList.emplace_back(d.distance);
    }
  }

  /**
   * @brief add a point to the container and make container in order
   *        from small to big
   *
   * @param distance
   * @param index
   */
  void AddPoint(ElemType distance, int index) {
    comparisonCounter_++;

    // Discard this point if its distance bigger than the worst distance
    if (distance > worstDist_)
      return;

    if (count_ < capacity_)
      count_++;

    // Find from back
    int currPosition = count_ - 1;


    while (currPosition > 0) {
      if (distIndexList_[currPosition - 1].distance > distance) {
        distIndexList_[currPosition] = distIndexList_[currPosition - 1];
        currPosition--;
      }
      else
        break;
    }

    distIndexList_[currPosition].distance = distance;
    distIndexList_[currPosition].index = index;
    worstDist_ = distIndexList_[capacity_ - 1].distance;
  }

private:
  int capacity_;
  int count_ = 0;
  int comparisonCounter_ = 0;
  ElemType worstDist_ = static_cast<ElemType>(1e10);
  std::vector<DistIndex<ElemType>> distIndexList_; // order from small to big
};

class RadiusNNResultSet {
private:

};

} // namespace mypcl
