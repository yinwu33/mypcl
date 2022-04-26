#pragma once

#include <vector>
#include <iostream>

namespace mypcl {
template<typename T>
struct TreeNode {
  using Ptr = TreeNode *;

  TreeNode() = default;

  TreeNode(T key_, int value_) : key(key_), value(value_) {}

  T key;
  int value;
  TreeNode *left;
  TreeNode *right;
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

  inline void preOrder(std::vector<T> &list) { preOrderRecursively(root_, list); }

  inline void inOrder(std::vector<T> &list) { inOrderRecursively(root_, list); }

  inline void postOrder(std::vector<T> &list) { postOrderRecursively(root_, list); }

  TreeNode<T> *search(T queryKey) { searchRecursively(root_, queryKey)};

  // todo
  bool kNNSearch(T queryKey, int k, std::vector<T>& results);

private:

  void insertRecursively(TreeNode<T> *&root, T &key, int value) {
    if (root == nullptr) {
      root = new TreeNode<T>(key, value);
    } else {
      if (key < root->key)
        insertRecursively(root->left, key, value);
      else if (key > root->key)
        insertRecursively(root->right, key, value);
      else
        std::cout << "BSTreeNode with key: " << key << " already exists!" << std::endl;
    }
  }

  void deleteTreeRecursively(TreeNode<T> *&root) {
    if (root) {
      deleteTreeRecursively(root->left);
      deleteTreeRecursively(root->right);
      delete (root);
    }
  }

  void preOrderRecursively(TreeNode<T> *&root, std::vector<T> &list) {
    if (root != nullptr) {
      list.emplace_back(root->key);
      preOrderRecursively(root->left, list);
      preOrderRecursively(root->right, list);
    }
  }

  void inOrderRecursively(TreeNode<T> *&root, std::vector<T> &list) {
    if (root != nullptr) {
      preOrderRecursively(root->left, list);
      list.emplace_back(root->key);
      preOrderRecursively(root->right, list);
    }
  }

  void postOrderRecursively(TreeNode<T> *&root, std::vector<T> &list) {
    if (root != nullptr) {
      preOrderRecursively(root->left, list);
      preOrderRecursively(root->right, list);
      list.emplace_back(root->key);
    }
  }

  TreeNode<T> *searchRecursively(TreeNode<T> *root, T queryKey) {
    if (root == nullptr or root->key == queryKey)
      return root;

    if (queryKey < root->key)
      return searchRecursively(root->left, queryKey);

    return searchRecursively(root->right, queryKey);
  }

  bool kNNSearchRecursively(TreeNode<T> *root, T queryKey, int k, std::vector<T>& results) {
    if (root == nullptr)
      return false;
    
    
  }

private:
  TreeNode<T> *root_;

};

} // namespace mypcl
