#pragma once
#include <cstdint>
#include <deque>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
template <typename T> class BinarySearchTree {
public:
  T data;
  BinarySearchTree<T> *left;
  BinarySearchTree<T> *right;
  void successorQueries(std::deque<T> &queries, std::vector<T> &answer,
                        std::vector<T> &traversal) {
    if (queries.empty()) {
      return;
    }
    if (left && queries.front() < data) {
      left->successorQueries(queries, answer, traversal);
      if (queries.empty()) {
        return;
      }
    }
    if (!traversal.empty() && traversal.back() == queries.front()) {
      answer.push_back(data);
      queries.pop_front();
      if (queries.empty()) {
        return;
      }
    }
    traversal.push_back(data);
    if (right && queries.front() >= data) {
      right->successorQueries(queries, answer, traversal);
    }
  }
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
    // if both are on the left || right continue left or right
    // else return
    if (x < data && y < data) {
      return left->getLca(x, y);
    }
    if (y > data && x > data) {
      return right->getLca(x, y);
    }
    return this;
  }

  T getMin() {
    BinarySearchTree<T> *cur = this;
    while (cur && cur->left) {
      cur = cur->left;
    }
    return cur->data;
  }

  BinarySearchTree(T val) : data(val), left{nullptr}, right{nullptr} {}
  BinarySearchTree(T val, BinarySearchTree<T> *leftPtr,
                   BinarySearchTree<T> *rightPtr)
      : data(val), left{leftPtr}, right{rightPtr} {}
  BinarySearchTree<T> *buildBst(const std::vector<T> &values, int start = 0,
                                int end = -10) {

    if (end == -10) {
      end = (int)values.size() - 1;
    }
    if (start > end) {
      return nullptr;
    }

    int mid = (start + end) / 2;

    BinarySearchTree<T> *left = buildBst(values, start, mid - 1);
    BinarySearchTree<T> *right = buildBst(values, mid + 1, end);
    BinarySearchTree<T> *root =
        new BinarySearchTree<T>{values[mid], left, right};
    return root;
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

  bool valExists(T val) const {
    if (val == data) {
      return true;
    }
    if (val < data) {
      return left && left->valExists(val);
    }
    return right && right->valExists(val);
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
  std::pair<bool, T> successor(T target) {
    std::vector<BinarySearchTree<T> *> ancestors{};
    if (!findChain(ancestors, target)) {
      return std::make_pair(false, -1); // not found
    }
    BinarySearchTree<T> *child = getNext(ancestors);
    if (child->right) { // we have right so ancestor is the smallest of right
                        // tree
      return std::make_pair(true, child->right->getMin());
    }
    BinarySearchTree<T> *parent =
        getNext(ancestors); // take previous node (parent)
    while (parent && parent->right == child) {
      child = parent;
      parent = getNext(ancestors);
    }
    if (parent) {
      return std::make_pair(true, parent->data);
    }
    return std::make_pair(false, -1);
  }
  BinarySearchTree<T> *minNode() {
    BinarySearchTree<T> *cur = this;
    while (cur && cur->left) {
      cur = cur->left;
    }
    return cur;
  }
  void deleteValue(T value) {
    if (value == data && !left && !right) {
      return;
    }
    deleteNode(value, this);
  }

private:
  BinarySearchTree<T> *deleteNode(T value, BinarySearchTree<T> *node) {
    if (!node) {
      return nullptr;
    }
    if (value < node->data) {
      node->left = deleteNode(value, node->left);
    } else if (value > node->data) {
      node->right = deleteNode(value, node->right);
    } else {
      BinarySearchTree<T> *tmp = node;
      if (!node->left && !node->right) {
        node = nullptr;
      } else if (!node->right) {
        node = node->left;
      } else if (!node->left) {
        node = node->right;
      } else {
        BinarySearchTree<T> *min = node->right->minNode();
        node->data = min->data;
        node->right = deleteNode(node->data, node->right);
        tmp = nullptr;
      }
      if (tmp) {
        delete tmp;
      }
    }
    return node;
  }
  bool findChain(std::vector<BinarySearchTree<T> *> &ancestors, T target) {
    ancestors.push_back(this);
    if (target == data) {
      return true;
    }
    if (target < data) {
      return left && left->findChain(ancestors, target);
    }
    return right && right->findChain(ancestors, target);
  }
  BinarySearchTree<T> *getNext(std::vector<BinarySearchTree<T> *> &ancestors) {
    if (ancestors.size() == 0) {
      return nullptr;
    }
    BinarySearchTree<T> *node = ancestors.back();
    ancestors.pop_back();
    return node;
  }
};
