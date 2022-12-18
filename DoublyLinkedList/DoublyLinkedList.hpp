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
  void printReverse() const {
    Node<T> *cur = tail;
    while (cur) {
      std::cout << cur->data << std::endl;
      cur = cur->prev;
    }
  }
};
