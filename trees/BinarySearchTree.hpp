#pragma once
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
template <typename T> class BinarySearchTree {
public:
  T data;
  BinarySearchTree<T> *left;
  BinarySearchTree<T> *right;

  void insert(T target) {
    if (target < data) {
      if (!left) {
        left = new BinarySearchTree<T>{target};
      } else {
        left->insert(target);
      }
    } else if (target > data) {
      if (!right) {
        right = new BinarySearchTree<T>{target};
      } else {
        right->insert(target);
      }
    }
  }

  BinarySearchTree<T> *getLca(T x, T y) {
    if (x < data && y < data) {
      return left->getLca(x, y);
    }
    if (y > data && x > data) {
      return right->getLca(x, y);
    }
    return this;
  }
  bool isBst(int mn = INT32_MIN, int mx = INT32_MAX) const {
    bool status = mn < data && data < mx;
    if (!status) {
      return false;
    }
    bool leftBst = !left || left->isBst(mn, data);
    if (!leftBst) {
      return false;
    }
    bool isRightBst = !right || right->isBst(data, mx);
    return isRightBst;
  }

  BinarySearchTree<T> *searchNode(T target) {
    BinarySearchTree<T> *node = this;
    while (node) {
      if (target == node->data) {
        return node;
      }
      if (target < node->data) {
        node = node->left;

      } else {
        node = node->right;
      }
    }
    return nullptr;
  }

  BinarySearchTree(T val) : data(val), left{nullptr}, right{nullptr} {}
  ~BinarySearchTree() { clear(); }
  void clear() {
    if (left) {
      delete left;
      left = nullptr;
    }
    if (right) {
      delete right;
      left = right;
    }
  }
  void printByLevel() {
    std::queue<BinarySearchTree<T> *> nodesQueue{};
    nodesQueue.push(this);
    int level = 0;
    while (!nodesQueue.empty()) {
      int sz = nodesQueue.size();
      std::cout << "Level: ";
      while (sz--) {
        BinarySearchTree<T> *cur = nodesQueue.front();
        nodesQueue.pop();
        std::cout << cur->data << " ";
        if (cur->left) {
          nodesQueue.push(cur->left);
        }
        if (cur->right) {
          nodesQueue.push(cur->right);
        }
      }
      level++;
      std::cout << '\n';
    }
  }
};
