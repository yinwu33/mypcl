#include <gtest/gtest.h>
#include <vector>

#include "bstree.hpp"

using namespace std;
using namespace mypcl;


#define TEST_END cout << "\n" << endl;


std::vector<int> samples = { 11,9,3,6,5,0,7, 4, 123, 4, 6, 54, -4, -33, 2 };

BSTree<int>* tree;

TEST(binary_search_tree, create_tree) {
  tree = new BSTree<int>();

  for (int i = 0; i < samples.size(); ++i) {
    tree->insert(samples[i], i);
  }
  TEST_END
}


TEST(binary_search_tree, inorder_cout) {

  std::vector<int> inorderList;
  tree->inOrder(inorderList);

  for (const int& i : inorderList) {
    std::cout << i << " ";
  }

  TEST_END
}

TEST(binary_search_tree, knn_search) {
  int queryKey = 11, k = 2;

  std::vector<int> indexList, distList;
  tree->kNNSearch(queryKey, k, indexList, distList);
  std::cout << "query key is: " << queryKey << ", then found " << k << " nn are ";
  std::cout << samples[indexList[0]] << " and ";
  std::cout << samples[indexList[1]] << std::endl;

  TEST_END
}

TEST(binary_search_tree, radius_knn_search) {
  int queryKey = 11, radius = 5;
  std::vector<int> indexList, distList;
  tree->radiusSearch(queryKey, radius, indexList, distList);
  std::cout << "query key is: " << queryKey << ", values should be from " << queryKey - radius << " to " << queryKey + radius << ", then found: ";

  for (int ind : indexList) {
    std::cout << samples[ind] << " ";
  }

  TEST_END
}