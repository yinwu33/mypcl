#include <gtest/gtest.h>
#include <vector>

// #include "bstree.hpp"
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

// mypcl::BSTreeNode<int>* CreateExample() {
//   std::vector<int> testCases{ 11,9,3,6,5,0,7,16 };

//   mypcl::BSTreeNode<int>* root = nullptr;

//   // insert
//   for (const int& i : testCases) {
//     mypcl::Insert(root, i, -1);
//   }

//   return root;
// }

// TEST(BSTree, InOrder) {
//   auto root = CreateExample();

//   std::vector<int> list;
//   mypcl::InOrder(root, list);

//   std::vector<int> inorderGroundTruth = { 0, 3, 5, 6, 7, 9, 11, 16 };
//   ASSERT_EQ(list, inorderGroundTruth) << "Inorder error";
// }

// TEST(BSTree, Search) {
//   auto root = CreateExample();

//   int testCase = 3;

//   std::vector<int> list;
//   auto nodeIter = mypcl::SearchIteratively(root, testCase);
//   auto nodeRecur = mypcl::SearchRecursively(root, testCase);
//   ASSERT_EQ(nodeIter->key, testCase);
//   ASSERT_EQ(nodeRecur->key, testCase);

//   auto nodeIterNon = mypcl::SearchIteratively(root, 12);
//   auto nodeRecurNon = mypcl::SearchRecursively(root, 12);
//   ASSERT_EQ(nodeIterNon, nullptr);
//   ASSERT_EQ(nodeRecurNon, nullptr);
// }

// TEST(BSTree, KNNSearch) {
//   auto root = CreateExample();

//   int queryKey = 13;

//   mypcl::KNNResultSet<int> result(2);

//   mypcl::KNNSearch(root, result, queryKey);

//   std::vector<int> indexList;
//   std::vector<int> distList;
//   result.GetResult(indexList, distList);

//   ASSERT_EQ(distList[0], 2);
//   ASSERT_EQ(distList[1], 3);
// }