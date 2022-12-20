#pragma once
#include <iostream>

template <typename T> struct Node {

  T data;
  Node *prev;
  Node *next;
  Node(T data) : data(data), prev(nullptr), next(nullptr){};
};

template <typename T> class DoublyLinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  size_t size;

  void link(Node<T> *first, Node<T> *second) {
    if (first) {
      first->next = second;
    }
    if (second) {
      second->prev = first;
    }
  }

  void embedAfter(Node<T> *prev, T value) {
    Node<T> *newNode = new Node<T>{value};
    size++;
    Node<T> *nodeAfter = prev->next;
    link(prev, newNode);
    link(newNode, nodeAfter);
  }

  void deleteNode(Node<T> *toDelete) {
    delete toDelete;
    size--;
  }

public:
  size_t getSize() const { return size; }
  DoublyLinkedList() : size(0), head(nullptr), tail(nullptr){};
  void insertSorted(T val) {
    if (!size || val <= head->data) {
      insertFront(val);
      return;
    }
    if (tail->data <= val) {
      insertEnd(val);
      return;
    }
    Node<T> *cur = head;
    while (cur) {

      if (val <= cur->data) {
        embedAfter(cur->prev, val);
        break;
      }

      cur = cur->next;
    }
  }
  void insertFront(T value) {
    Node<T> *newValue = new Node<T>{value};
    if (!head) {
      head = tail = newValue;
    } else {
      link(newValue, head);
      head = newValue;
    }
    size++;
  }
  ~DoublyLinkedList() {

    while (head) {
      Node<T> *cur = head->next;
      delete head;
      head = cur;
    }
  }
  void deleteFront() {
    if (!head) {
      return;
    }
    Node<T> *cur = head->next;
    deleteNode(head);
    head = cur;
    if (head) {
      head->prev = nullptr;
    } else if (!size) {
      tail = nullptr;
    }
  }

  void deleteBack() {
    if (!head) {
      return;
    }
    Node<T> *prev = tail->prev;
    deleteNode(tail);
    tail = prev;
    tail->next = nullptr;
  }

  void insertEnd(T value) {
    Node<T> *item = new Node<T>{value};
    if (!head) {
      head = tail = item;
    } else {
      link(tail, item);
      tail = item;
    }
    size++;
  }

  bool isPalindrome() const {
    Node<T> *cur1 = head;
    Node<T> *cur2 = tail;
    if (size == 1) {
      return true;
    }
    while (cur2 && cur1) {

      if (cur1->data != cur2->data) {
        return false;
      }

      cur1 = cur1->next;
      cur2 = cur2->prev;
    }
    return true;
  }
  void deleteEvenPositions() {
    if (!head) {
      return;
    }
    Node<T> *cur = head;
    size_t tempIndex = 0;
    while (cur) {

      if (tempIndex % 2 == 0) {
        if (cur == head) {
          deleteFront();
        } else if (cur == tail) {
          deleteBack();
          return;
        } else {
          Node<T> *prev = cur->prev;
          Node<T> *next = cur->next;
          prev->next = next;
          next->prev = prev;
          size--;
          delete cur;
        }
      }

      cur = cur->next;
      tempIndex++;
    }
  }

  void deleteAllNodesWithKey(T value) {
    Node<T> *cur = head;
    while (cur) {

      if (cur->data == value) {
        if (cur == head) {
          deleteFront();
          continue;
        }
        if (cur == tail) {
          deleteBack();
          return;
        }
        Node<T> *prev = cur->prev;
        Node<T> *next = cur->next;
        prev->next = cur->next;
        next->prev = prev;
        size--;
        delete cur;
      }

      cur = cur->next;
    }
  }

  void deleteAtIndex(size_t index) {
    if (index == 0) {
      deleteFront();
      return;
    }
    if (index == size - 1) {
      deleteBack();
      return;
    }
    size_t curIndex = 0;
    Node<T> *cur = head;
    while (cur) {

      if (curIndex == index) {
        Node<T> *prev = cur->prev;
        Node<T> *next = cur->next;
        prev->next = cur->next;
        next->prev = prev;

        size--;
        delete cur;
        break;
      }

      curIndex++;
      cur = cur->next;
    }
  }

  Node<T> *findMiddle() {
    Node<T> *slow = head;
    Node<T> *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  void printReverse() const {
    Node<T> *cur = tail;
    while (cur) {
      std::cout << cur->data << std::endl;
      cur = cur->prev;
    }
  }
};
