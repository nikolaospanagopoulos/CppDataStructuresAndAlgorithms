#pragma once
#include <initializer_list>
#include <iostream>
template <typename T> class Vector {
  T *arr;
  size_t size;
  size_t capacity;
  void expandCapacity() {
    capacity *= 2;
    std::cout << "expanding capacity to " << capacity << std::endl;
    T *arr2 = new T[capacity];
    for (size_t i{}; i < size; i++) {
      arr2[i] = arr[i];
    }
    std::swap(arr, arr2);
    delete[] arr2;
  }

public:
  Vector &operator=(const Vector &rhs) {
    if (this == &rhs) {
      return *this;
    }
    delete[] arr;
    size = rhs.size;
    capacity = rhs.capacity;
    arr = new T[capacity];
    for (size_t i{}; i < size; i++) {
      arr[i] = rhs.arr[i];
    }
    std::cout << "copy aassignment \n";
    return *this;
  }
  Vector &operator=(Vector &&rhs) {
    if (this == &rhs) {
      return *this;
    }
    delete[] arr;
    size = rhs.size;
    capacity = rhs.capacity;
    arr = rhs.arr;
    rhs.arr = nullptr;
    std::cout << "move assignment used\n";
    return *this;
  }
  Vector(Vector &&rhs) : arr(rhs.arr) {

    size = rhs.size;
    capacity = rhs.capacity;
    rhs.arr = nullptr;
    std::cout << "move constructor called\n";
  }
  Vector(const Vector &rhs) {
    size = rhs.size;
    capacity = rhs.capacity;
    arr = new T[capacity];
    for (size_t i{}; i < size; i++) {
      arr[i] = rhs.arr[i];
    }
    std::cout << "copy constructor used \n";
  }
  void rightRotate() {
    T lastElement = arr[size - 1];
    for (size_t i = size - 1; i >= 1; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
  }

  int findIndex(T el) {
    for (int i{}; i < size; i++) {
      if (arr[i] == el) {
        return i;
      }
    }
    return -1;
  }

  void removeFirst() { deleteElementByIndex(0); }
  void removeLast() { deleteElementByIndex(size - 1); }
  int findImproved(T val) {
    for (int i{1}; i < size; i++) {
      if (arr[i] == val) {
        T savedVal = arr[i - 1];
        arr[i - 1] = val;
        arr[i] = savedVal;
        return i;
      }
    }
    return -1;
  }

  void deleteElementByIndex(size_t index) {

    if (index >= size || index < 0) {
      std::cerr << "invalid index \n";
      return;
    }
    for (size_t i = index; i < size; i++) {
      arr[i] = arr[i + 1];
    }
    size--;
  }

  void leftRotationWithSteps(int numOfSteps) {
    for (int i = 0; i < numOfSteps; i++) {
      leftRotate();
    }
  }
  void rightRotationWithSteps(int numOfSteps) {
    for (int i = 0; i < numOfSteps; i++) {
      rightRotate();
    }
  }

  void leftRotate() {
    T firstElement = arr[0];
    for (size_t i{}; i < size; i++) {
      arr[i] = arr[i + 1];
    }
    arr[size - 1] = firstElement;
  }
  void insert(int index, T value) {
    if (index <= 0 || index > size) {
      std::cerr << "cannot insert\n";
      return;
    }
    if (size == capacity) {
      expandCapacity();
    }
    for (size_t p = size - 1; p >= index; --p) {
      arr[p + 1] = arr[p];
    }
    arr[index] = value;
    ++size;
  }
  void print() {
    for (size_t i{}; i < size; i++) {
      std::cout << arr[i] << std::endl;
    }
  }
  void pushBack(T value) {
    if (size == capacity) {
      expandCapacity();
    }
    arr[size++] = value;
  }
  size_t getSize() { return size; }
  size_t getCapacity() { return capacity; }
  Vector(std::initializer_list<T> list) : size(0), capacity(size + 10) {
    arr = new T[capacity];
    while (list.size() >= capacity) {
      expandCapacity();
    }
    auto el = list.begin();
    size_t i = 0;
    while (el != list.end()) {
      arr[i] = *el;
      i++;
      size++;
      el++;
    }
  }

  ~Vector() { delete[] arr; }
};
