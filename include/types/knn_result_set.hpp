#pragma once

#include <vector>

namespace mypcl
{
template <typename T>
struct DistanceIndex {
  DistanceIndex(T distance_, int index_) : distance(distance_), index(index_) {}

  T distance;
  int index;

  bool operator < (const DistanceIndex& other) {
    return distance < other.distance;
  }
};

template <typename T>
class KNNResultSet {
public:
  explicit KNNResultSet(int capacity)
    : capacity_(capacity), count_(0), comparisonCounter_(0), worstDistance_(static_cast<T>(1e10)) {
    distIndexList_.reserve(capacity_);

    for (int i = 0; i < capacity_; ++i) {
      distIndexList_.emplace_back(DistanceIndex<T>(worstDistance_, 0));
    }
  }

  inline int size() { return count_; }

  inline bool isFull() { return count_ == capacity_; }

  inline T getWorstDistance() { return worstDistance_; }

  inline void getResult(std::vector<int>& indexList, std::vector<T>& distList) {
    indexList.clear();
    distList.clear();

    for (const DistanceIndex<T>& d : distIndexList_) {
      indexList.emplace_back(d.index);
      distList.emplace_back(d.distance);
    }
  }

  void addPoint(T distance, int index) {
    comparisonCounter_++;

    if (distance > worstDistance_)
      return;

    if (count_ < capacity_)
      ++count_;

    int currPosition = count_ - 1;

    while (currPosition > 0) {
      if (distIndexList_[currPosition-1].distance > distance) {
        distIndexList_[currPosition] = distIndexList_[currPosition - 1];
        --currPosition;
      }
      else
        break;
    }

    distIndexList_[currPosition].distance = distance;
    distIndexList_[currPosition].index = index;

    worstDistance_ = distIndexList_[capacity_ - 1].distance;
  }

private:
  int capacity_;
  int count_;
  int comparisonCounter_;

  T worstDistance_;

  std::vector<DistanceIndex<T>> distIndexList_;
};

} // namespace mypcl
