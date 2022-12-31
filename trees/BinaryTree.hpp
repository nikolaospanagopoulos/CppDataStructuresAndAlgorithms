#pragma once
#include <iostream>
#include <queue>
#include <vector>

template <typename T> class BinaryTree {

public:
  T data;
  BinaryTree<T> *left;
  BinaryTree<T> *right;

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

  void traverseLeftBoundry() const {
    std::cout << data << std::endl;

    if (left) {
      left->traverseLeftBoundry();
    } else if (right) {
      right->traverseLeftBoundry();
    }
  }
  bool isPerfect(int h = -1) const {
    if (h == -1) {
      h = getHeight();
    }
    if (!left && !right) {
      return h == 0;
    }
    if ((!left && right) || (left && !right)) {
      return false;
    }
    return left->isPerfect(h - 1) && right->isPerfect(h - 1);
  }
  bool exists(T val) const {

    bool res = data == val;
    if (left && !res) {
      res = left->exists(val);
    }
    if (right && !res) {
      res = right->exists(val);
    }
    return res;
  }

  int getLeafNodesCount() const {
    int res = !left && !right;
    if (left) {
      res += left->getLeafNodesCount();
    }
    if (right) {
      res += right->getLeafNodesCount();
    }
    return res;
  }
  int getHeight() const {
    int res = 0;
    if (left) {
      res = left->getHeight() + 1;
    }
    if (right) {
      res = std::max(res, 1 + right->getHeight());
    }
    return res;
  }
  size_t getSize() const {
    size_t res = 1;
    if (left) {
      res += left->getSize();
    }
    if (right) {
      res += right->getSize();
    }
    return res;
  }

  T getMax() {
    T res = data;
    if (left) {
      res = std::max(res, left->data);
    }
    if (right) {
      res = std::max(res, right->data);
    }
    return res;
  }

  BinaryTree(T dataVal) : data(dataVal), left(nullptr), right(nullptr) {}
  void print() {
    if (left) {
      left->print();
    }
    std::cout << data << std::endl;
    if (right) {
      right->print();
    }
  }
  void printByLevel() {
    std::queue<BinaryTree<T> *> nodesQueue{};
    nodesQueue.push(this);
    int level = 0;
    while (!nodesQueue.empty()) {
      int sz = nodesQueue.size();
      std::cout << "Level: ";
      while (sz--) {
        BinaryTree<T> *cur = nodesQueue.front();
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
  ~BinaryTree() { clear(); }
  void add(std::vector<T> data, std::vector<char> directions) {
    if (data.size() != directions.size()) {
      return;
    }
    BinaryTree<T> *current = this;
    for (size_t i{}; i < data.size(); i++) {
      if (directions[i] == 'L') {
        if (!current->left) {
          current->left = new BinaryTree<T>{data[i]};
        } else {
          if (current->left->data != data[i]) {
            std::cerr << "data values dont fit" << std::endl;
          }
        }
        current = current->left;
      } else {
        if (directions[i] == 'R') {
          if (!current->right) {
            current->right = new BinaryTree<T>{data[i]};
          } else {
            if (current->right->data != data[i]) {
              std::cerr << "data values dont fit" << std::endl;
            }
          }
          current = current->right;
        }
      }
    }
  }
};
