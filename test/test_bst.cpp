#include <gtest/gtest.h>
#include <vector>

#include "bstree.h"

using namespace std;
using namespace mypcl;


TEST(TEST_BSTree, InOrder) {
  BSTree<int> tree;

  std::vector<int> samples = { 11,9,3,6,5,0,7,16 };

  for (int i = 0; i < samples.size(); ++i) {
    tree.insert(samples[i], i);
  }

  std::vector<int> inorderList;
  tree.inOrder(inorderList);

  for (const int& i : inorderList) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  std::cout << "testing knn search" << std::endl;
  std::vector<int> indexList, distList;
  int queryKey = 6, k = 2;
  tree.kNNSearch(6, 2, indexList, distList);
  std::cout << "query key is: " << queryKey << ", then found " << k <<" nn are ";
  std::cout << samples[indexList[0]] << " and ";
  std::cout << samples[indexList[1]] << std::endl;
}