#pragma once

#include <vector>

namespace mypcl
{

template<typename T>
struct TreeNode {
  using Ptr = TreeNode*;

  TreeNode() = default;
  TreeNode(T key_, int value_);

  T key;
  int value;
  TreeNode* left;
  TreeNode* right;
};

/**
 * @brief A Binary Tree for 1D elements
 *
 * @tparam T: int, float, double, etc.
 */
template<typename T>
class BSTree {
public:

  BSTree() = default;

  inline void insert(T key, int value = 0) { insertRecursively(root_, key, value); }

  inline void deleteTree() { deleteTreeRecursively(root_); }

  inline void preOrder(std::vector<T>& list) { preOrderRecursively(root_, list); }

  inline void inOrder(std::vector<T>& list) { inOrderRecursively(root_, list); }

  inline void postOrder(std::vector<T>& list) { postOrderRecursively(root_, list); }

private:

  void insertRecursively(TreeNode<T>*& root, T& key, int value);

  void deleteTreeRecursively(TreeNode<T>*& root);

  void preOrderRecursively(TreeNode<T>*& root, std::vector<T>& list);

  void inOrderRecursively(TreeNode<T>*& root, std::vector<T>& list);

  void postOrderRecursively(TreeNode<T>*& root, std::vector<T>& list);

private:
  TreeNode<T>* root_;

};

} // namespace mypcl
