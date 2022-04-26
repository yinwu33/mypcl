#include <gtest/gtest.h>
#include <vector>

#include "bstree.h"

using namespace std;
using namespace mypcl;


TEST(TEST_BSTree, InOrder) {
  BSTree<int> tree;

  std::vector<int> samples = { 11,9,3,6,5,0,7,16 };

  for (const int& i : samples) {
    tree.insert(i);
  }

  std::vector<int> inorderList;
  tree.inOrder(inorderList);

  for (const int& i : inorderList) {
    std::cout << i << std::endl;
  }
}