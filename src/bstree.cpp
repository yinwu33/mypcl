#include "bstree.h"

#include <iostream>

namespace mypcl
{
template<typename T>
void BSTree<T>::insertRecursively(TreeNode<T>*& root, T& key, int value) {
  if (root == nullptr) {
    root = new TreeNode<T>(key, value);
  }
  else {
    if (key < root->key) 
      insertRecursive(root->left, key, value);
    else if (key > root->key)
      insertRecursive(root->right, key, value);
    else
      std::cout << "BSTreeNode with key: " << key << " already exists!" << std::endl;
  }
}

template<typename T>
void BSTree<T>::deleteTreeRecursively(TreeNode<T>*& root) {
  if (root) {
    deleteTreeRecursively(root->left);
    deleteTreeRecursively(root->right);
    delete(root);
  }
}
  
template<typename T>
void BSTree<T>::preOrderRecursively(TreeNode<T>*& root, std::vector<T>& list) {
  if (root != nullptr) {
    list.emplace_back(root->key);
    preOrderRecursively(root->left, list);
    preOrderRecursively(root->right, list);
  } 
}

template<typename T>
void BSTree<T>::inOrderRecursively(TreeNode<T>*& root, std::vector<T>& list) {
  if (root != nullptr) {
    preOrderRecursively(root->left, list);
    list.emplace_back(root->key);
    preOrderRecursively(root->right, list);
  } 
}

template<typename T>
void BSTree<T>::postOrderRecursively(TreeNode<T>*& root, std::vector<T>& list) {
  if (root != nullptr) {
    preOrderRecursively(root->left, list);
    preOrderRecursively(root->right, list);
    list.emplace_back(root->key);
  } 
}

} // namespace mypcl
