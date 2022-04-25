#pragma once

#include <vector>

#include "result_set.hpp"

namespace mypcl {

template<typename ElemType>
struct BSTreeNode {
  using Ptr = BSTreeNode*;

  ElemType key;
  int value;
  BSTreeNode<ElemType>* leftNode;
  BSTreeNode<ElemType>* rightNode;
};

template<typename ElemType>
void Insert(BSTreeNode<ElemType>*& root, ElemType key, int index) {
  if (root == nullptr) {
    root = new BSTreeNode<ElemType>;
    root->key = key;
    root->value = index;
    root->leftNode = nullptr;
    root->rightNode = nullptr;
  }
  else {
    if (key < root->key) {
      Insert(root->leftNode, key, index);
    }
    else if (key > root->key) {
      Insert(root->rightNode, key, index);
    }
    else {
      std::cout << "BSTreeNode with key: " << key << " already exists!" << std::endl;
    }
  }
}

template<typename ElemType>
void DeleteTree(BSTreeNode<ElemType>* root) {
  if (root != nullptr) {
    DeleteTree(root->leftNode);
    DeleteTree(root->rightNode);
    delete(root);
  }
}

template<typename ElemType>
void InOrder(BSTreeNode<ElemType>* root, std::vector<ElemType>& list) {
  if (root != nullptr) {
    InOrder(root->leftNode, list);
    std::cout << "key: " << root->key << " index: " << root->value << std::endl;
    list.emplace_back(root->key);
    InOrder(root->rightNode, list);
  }
}

template<typename ElemType>
void PreOrder(BSTreeNode<ElemType>* root, std::vector<ElemType>& list) {
  if (root != nullptr) {
    std::cout << "key: " << root->key << " index: " << root->value << std::endl;
    list.emplace_back(root->key);
    PreOrder(root->leftNode, list);
    PreOrder(root->rightNode, list);
  }
}

template<typename ElemType>
void PostOrder(BSTreeNode<ElemType>* root, std::vector<ElemType>& list) {
  if (root != nullptr) {
    PostOrder(root->leftNode, list);
    PostOrder(root->rightNode, list);
    std::cout << "key: " << root->key << " index: " << root->value << std::endl;
    list.emplace_back(root->key);
  }
}

template<typename ElemType>
BSTreeNode<ElemType>* SearchRecursively(BSTreeNode<ElemType>* root, ElemType queryKey) {
  if (root == nullptr or root->key == queryKey) {
    return root;
  }

  if (queryKey < root->key) {
    return SearchRecursively(root->leftNode, queryKey);
  }
  else if (queryKey > root->key) {
    return SearchRecursively(root->rightNode, queryKey);
  }
  return root;
}

template<typename ElemType>
BSTreeNode<ElemType>* SearchIteratively(BSTreeNode<ElemType>* root, ElemType queryKey) {
  BSTreeNode<ElemType>* currNode = root;

  while (currNode != nullptr) {
    if (currNode->key == queryKey)
      return currNode;
    else if (queryKey < root->key)
      currNode = currNode->leftNode;
    else if (queryKey > root->key)
      currNode = currNode->rightNode;
  }
  std::cout << "queryKey: " << queryKey << " not found!" << std::endl;
  return currNode;
}

template <typename ElemType>
bool KNNSearch(BSTreeNode<ElemType>* root, KNNResultSet<ElemType>& resultSet, ElemType queryKey) {
  if (root == nullptr)
    return false;

  resultSet.AddPoint(abs(root->key - queryKey), root->value); // todo: what for a value
  if (resultSet.GetWorstDist() == 0)
    return true;
  if (queryKey < root->key) { // ! <? <=
    if (KNNSearch(root->leftNode, resultSet, queryKey))
      return true;
    else if (abs(root->key - queryKey) < resultSet.GetWorstDist())
      return KNNSearch(root->rightNode, resultSet, queryKey);

    return false;
  }
  else if (queryKey > root->key) {
    if (KNNSearch(root->rightNode, resultSet, queryKey))
      return true;
    else if (abs(root->key - queryKey) < resultSet.GetWorstDist())
      return KNNSearch(root->leftNode, resultSet, queryKey);

    return false;
  }
  else {
    std::cout << "warning" << std::endl;
  }

  return false;
}
} // namespace my_
