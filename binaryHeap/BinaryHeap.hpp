#pragma once
#include <iostream>
#include <vector>

template <typename T> class MinHeap {
private:
  T *arr{};
  int size;
  int capacity;
  void expandCapacity() {
    if (size == capacity) {
      std::cout << "expaning capacity \n";
      T *arr2 = new T[capacity * 2];
      for (size_t i{}; i < size; i++) {
        arr2[i] = arr[i];
      }
      std::swap(arr2, arr);
      delete[] arr2;
    }
  }

  void heapifyUp(int childPosition) {
    int parentPosition = parent(childPosition);
    if (childPosition == 0 || arr[parentPosition] <= arr[childPosition]) {
      return;
    }
    std::swap(arr[childPosition], arr[parentPosition]);
    heapifyUp(parentPosition);
  }

  void heapifyDown(int parentPosition) {
    int childPosition = left(parentPosition);
    int rightChildPosition = right(parentPosition);
    if (childPosition == -1) {
      return;
    }
    if (childPosition != -1 && arr[rightChildPosition] < arr[childPosition]) {
      childPosition = rightChildPosition;
    }
    if (arr[parentPosition] > arr[childPosition]) {
      std::swap(arr[parentPosition], arr[childPosition]);
      heapifyDown(childPosition);
    }
  }
  void heapify() {
    for (int i = size - 1; i >= 0; i--) {
      heapifyDown(i);
    }
  }

public:
  T *top() {
    if (isEmpty()) {
      return nullptr;
    }
    return &arr[0];
  }
  void pop() {
    if (isEmpty()) {
      std::cout << "array is empty \n";
      return;
    }
    arr[0] = arr[--size];
    heapifyDown(0);
  }
  bool isEmpty() const { return size == 0 ? true : false; }
  int getSize() const { return size; }
  T top() const {
    if (!isEmpty()) {
      return arr[0];
    }
  }
  int parent(int index) const { return index == 0 ? -1 : (index - 1) / 2; }
  int left(int index) const {
    int position = 2 * index + 1;
    if (position >= size) {
      return -1;
    }
    return position;
  }
  int right(int index) const {
    int position = 2 * index + 2;
    if (position >= size) {
      return -1;
    }
    return position;
  }
  void push(T val) {
    if (size == capacity) {
      expandCapacity();
    }
    arr[size++] = val;
    heapifyUp(size - 1);
  }
  MinHeap() : capacity{10}, size(0) { arr = new T[capacity]; }
  MinHeap(const std::vector<T> &vec) : capacity(10) {
    while (vec.size() > capacity) {
      expandCapacity();
    }
    arr = new T[capacity];
    size = vec.size();
    for (int i{}; i < vec.size(); i++) {
      arr[i] = vec[i];
    }
    heapify();
  }

  ~MinHeap() {
    delete[] arr;
    arr = nullptr;
  }
};
