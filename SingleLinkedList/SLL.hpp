#pragma once
#include <cstddef>
#include <initializer_list>
#include <iostream>
template <typename T> struct Node {
  T data;
  Node *next;
  Node(T value) : data(value) {}
};

template <typename T> class SingleLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t size;

public:
  Node<T> *getNthFromBack(size_t index) {

    if (index < 0 || index > size) {
      return nullptr;
    }
    size_t correctPosition = size - index - 1;
    return getNth(correctPosition);
  }

  void deleteNodeAtIndex(size_t index) {
    if (index >= size) {
      return;
    }
    if (index == size - 1) {
      deleteBack();
      return;
    }
    if (index == 0) {
      deleteFront();
      return;
    }
    Node<T> *current = head;
    Node<T> *prev = nullptr;
    size_t temp = 0;
    while (current) {
      if (temp == index) {
        deleteNext(prev);
        current = prev->next;
        return;
      }
      prev = current;
      current = current->next;
      temp++;
    }
  }

  void deleteFront() {

    if (!head) {
      return;
    }
    Node<T> *cur = head;
    head = head->next;
    delete cur;

    size--;
    if (!head) {
      tail = nullptr;
    }
  }
  Node<T> *find(T value) const {
    Node<T> *current = head;
    while (current) {
      if (current->data == value) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }
  void insertFront(T value) {
    Node<T> *newNode = new Node<T>{value};
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
    size++;
  }
  Node<T> *getNth(size_t index) const {
    if (index >= size || index < 0) {
      return nullptr;
    }
    Node<T> *current = head;
    size_t currentIndex = 0;
    while (current) {
      if (currentIndex == index) {
        return current;
      }
      current = current->next;
      currentIndex++;
    }
    return nullptr;
  }
  SingleLinkedList &operator=(const SingleLinkedList<T> &rhs) {
    if (this == &rhs) {
      return *this;
    }
    while (head) {
      Node<T> *current = head->next;
      delete head;
      head = current;
    }
    size = 0;
    Node<T> *current = rhs.head;
    while (current) {
      insertEnd(current->data);
      current = current->next;
    }
    return *this;
  }
  SingleLinkedList(const SingleLinkedList &rhs) {
    size = 0;
    head = nullptr;
    tail = nullptr;
    Node<T> *current = rhs.head;
    while (current) {
      insertEnd(current->data);
      current = current->next;
    }
  }
  SingleLinkedList(std::initializer_list<T> list) {
    size = 0;
    head = nullptr;
    tail = nullptr;
    for (const auto &i : list) {
      insertEnd(i);
    }
  }
  size_t getSize() { return size; }
  void insertEnd(T value) {
    Node<T> *newNode = new Node<T>{value};
    if (head) {
      tail->next = newNode;
      tail = newNode;

    } else {
      head = tail = newNode;
      newNode->next = nullptr;
    }
    size++;
  }
  ~SingleLinkedList() {
    while (head) {
      Node<T> *current = head->next;
      delete head;
      head = current;
    }
  }
  bool isSameListWithoutSize(const SingleLinkedList<T> &rhsList) {
    Node<T> *current = head;
    Node<T> *rhsCurrent = rhsList.head;

    while (rhsCurrent && current) {
      if (current->data != rhsCurrent->data) {
        return false;
      }
      current = current->next;
      rhsCurrent = rhsCurrent->next;
    }
    return !current && !rhsCurrent;
  }
  bool isSameList(const SingleLinkedList<T> &listToCheck) {
    if (size != listToCheck.size) {
      return false;
    }
    Node<T> *current = head;
    Node<T> *rhsCurrent = listToCheck.head;

    while (current && rhsCurrent) {

      if (current->data != rhsCurrent->data) {
        return false;
      }

      current = current->next;
      rhsCurrent = rhsCurrent->next;
    }
    return true;
  }
  void insertSorted(T val) {
    if (!head || val <= head->data) {
      insertFront(val);
      return;
    }
    if (val >= tail->data) {
      insertEnd(val);
      return;
    }
    Node<T> *newNode = new Node<T>{val};
    Node<T> *current = head->next;
    Node<T> *prev = head;
    while (current) {

      if (val <= current->data) {
        prev->next = newNode;
        newNode->next = current;
        size++;
        return;
      }
      prev = current;
      current = current->next;
    }
  }
  void deleteEvenPositions() {
    if (size == 0 || size == 1) {
      return;
    }
    Node<T> *current = head;
    Node<T> *prev = nullptr;
    size_t tempIndex = 0;

    while (current) {

      if (tempIndex % 2 != 0) {
        deleteNext(prev);
        current = prev->next;

      } else {
        prev = current;
        current = current->next;
      }

      tempIndex++;
    }
  }

  void reverseNodes() {
    if (size <= 1) {
      return;
    }
    tail = head;
    Node<T> *prev = head;
    head = head->next;
    while (head) {
      Node<T> *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    head = prev;
    tail->next = nullptr;
  }

  SingleLinkedList<T> *reverse() {
    Node<T> *curr = head;
    Node<T> *last = getNth(size - 1);
    SingleLinkedList<T> *newList = new SingleLinkedList<T>{};
    while (curr) {
      newList->insertFront(curr->data);

      curr = curr->next;
    }
    return newList;
  }
  void swapPairs() {
    Node<T> *curr = head;
    Node<T> *prev = nullptr;
    size_t tempIndex{};
    while (curr) {
      if (tempIndex % 2 != 0 && prev) {
        std::swap(prev->data, curr->data);
      }
      prev = curr;
      curr = curr->next;
      tempIndex++;
    }
  }

  void deleteBack() {
    if (size == 1) {
      deleteFront();
    } else {
      Node<T> *prevTail = getNth(size - 2);
      tail = prevTail;
      delete prevTail->next;
      tail->next = nullptr;
      size--;
    }
  }
  void deleteNext(Node<T> *node) {
    if (!node) {
      return;
    }
    Node<T> *toDelete = node->next;
    bool isTail = toDelete == tail;
    node->next = node->next->next;
    delete toDelete;
    size--;
    if (isTail) {
      tail = node;
    }
  }
  void deleteDuplicates() {
    for (Node<T> *cur = head; cur; cur = cur->next) {
      for (Node<T> *curNext = cur->next, *prev = cur; curNext;) {
        if (curNext->data == cur->data) {
          deleteNext(prev);
          curNext = prev->next;
        } else {
          prev = curNext;
          curNext = prev->next;
        }
      }
    }
  }
  void deleteAllOccurancesOfValue(T val) {

    for (Node<T> *cur1 = head; cur1; cur1 = cur1->next) {
      for (Node<T> *cur2 = cur1->next, *prv = cur1; cur2;) {
        if (cur2->data == cur1->data) {
          deleteNext(prv);
          cur2 = prv->next;
        } else {
          prv = cur2, cur2 = prv->next;
        }
      }
    }
    if (head->data == val) {
      deleteFront();
    }
  }
  Node<T> *getPrv(const Node<T> *node) const {
    Node<T> *cur = head;
    Node<T> *prv = nullptr;
    while (cur) {

      if (cur == node) {
        return prv;
      }

      prv = cur;
      cur = cur->next;
    }
    return nullptr;
  }
  void removeLastOccurance(T val) {

    Node<T> *cur = head;
    Node<T> *prev = nullptr;
    Node<T> *toDeleteNext = nullptr;

    bool found = false;
    while (cur) {

      if (cur->data == val) {
        found = true;
        toDeleteNext = prev;
      }

      prev = cur;
      cur = cur->next;
    }
    if (found) {
      if (toDeleteNext) {
        deleteNext(toDeleteNext);
        return;
      }
      deleteFront();
    }
  }
  Node<T> *moveToEnd(Node<T> *cur, Node<T> *prev) {
    Node<T> *next = cur->next;
    tail->next = cur;
    if (prev) {
      prev->next = next;
    } else {
      head = next;
    }
    tail = cur;
    tail->next = nullptr;
    return next;
  }
  void moveKeyToEnd(T val) {
    if (size <= 1) {
      return;
    }
    size_t length = size;
    Node<T> *cur = head;
    Node<T> *prev = nullptr;
    while (cur && length > 0) {

      if (cur->data == val) {
        cur = moveToEnd(cur, prev);
      } else {
        prev = cur;
        cur = cur->next;
      }
      length--;
    }
  }
  T max(Node<T> *head = nullptr, bool firstCall = true) {
    if (firstCall) {
      return this->max(this->head, false);
    }
    if (head == nullptr) {
      return INT16_MIN;
    }
    return std::max(head->data, this->max(head->next, false));
  }
  void swapTailHead() {
    Node<T> *cur = head;

    Node<T> *prv = getPrv(tail);

    tail->next = head->next;
    prv->next = head;
    head->next = nullptr;

    std::swap(tail, head);
  }
  void collectOdsAndEvens() {
    if (size <= 2) {
      return;
    }
    Node<T> *firstEven = head->next;
    Node<T> *curOd = head;
    while (curOd->next && curOd->next->next) {
      Node<T> *nextEven = curOd->next;
      curOd->next = curOd->next->next;
      nextEven->next = nextEven->next->next;
      curOd = curOd->next;
      if (size % 2 == 1) {
        tail = nextEven;
      }
    }
    curOd->next = firstEven;
  }
  void leftRotate(int steps) {
    if (steps == 0 || steps % size == 0) {
      return;
    }
    if (size <= 1) {
      return;
    }
    steps = steps % size;
    Node<T> *nth = getNth(steps);
    tail->next = head;
    tail = nth;
    head = nth->next;
    tail->next = nullptr;
  }
  void print() const {
    Node<T> *current = head;
    while (current) {
      std::cout << current->data << std::endl;

      current = current->next;
    }
  }
};
