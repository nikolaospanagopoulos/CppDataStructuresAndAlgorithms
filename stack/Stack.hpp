#pragma once
#include <cstddef>
#include <iostream>
#include <type_traits>
template <typename T> class Stack {

  size_t size{};
  size_t capacity{};
  int top{};
  T *arr;
  void expandCapacity() {
    std::cout << "expaning capacity \n";
    if (capacity == size) {
      capacity *= 2;
      T *arr2 = new T[capacity];
      for (size_t i{}; i < size; i++) {
        arr2[i] = arr[i];
      }
      std::swap(arr, arr2);
      delete[] arr2;
    }
  }
  static char getOpenMatch(char ch) {
    if (ch == ')') {
      return '(';
    }
    if (ch == ']') {
      return '[';
    }
    return '{';
  }

public:
  static int reverseNum(int num) {
    if (num == 0) {
      return 0;
    }
    Stack<int> s{};
    while (num) {
      s.push(num % 10);
      num /= 10;
    }
    int tens = 1;

    while (!s.isEmpty()) {
      num = s.pop() * tens + num;
      tens *= 10;
    }
    return num;
  }

  static std::string removeDuplicates(std::string toRemove) {
    Stack<char> toAddChars{};
    for (size_t i{}; i < toRemove.size(); i++) {
      char ch = toRemove[i];
      if (!toAddChars.isEmpty() && toAddChars.peek() == ch) {
        toAddChars.pop();
      } else {
        toAddChars.push(ch);
      }
    }
    std::string result{};
    while (!toAddChars.isEmpty()) {
      result = toAddChars.pop() + result;
    }
    return result;
  }
  static bool checkParentheses(std::string paren) {
    Stack<char> parentheses{};
    for (size_t i{}; i < paren.size(); i++) {
      char ch = paren[i];
      if (ch == '(' || ch == '[' || ch == '{') {
        parentheses.push(ch);
      } else if (parentheses.isEmpty() ||
                 parentheses.pop() != Stack::getOpenMatch(ch)) {
        return false;
      }
    }
    return parentheses.isEmpty();
  }
  static std::string reverseWords(std::string line) {
    line += " ";
    std::string result{};
    Stack<char> stringStack{};
    for (size_t i{}; i < line.size(); i++) {
      if (line[i] == ' ') {
        while (!stringStack.isEmpty()) {
          result += stringStack.pop();
        }
        result += " ";
      } else {
        stringStack.push(line[i]);
      }
    }
    return result;
  }
  T peek() {
    if (!isEmpty()) {
      return arr[top];
    }
    std::cout << "stack is empty \n";
    return arr[-1];
  }
  T pop() {
    if (!isEmpty()) {
      size--;
      return arr[top--];
    }
    std::cout << "stack is empty \n";
    return arr[-1];
  }
  size_t getSize() const { return size; }
  bool isFull() const { return capacity == size; }
  bool isEmpty() const { return top == -1; }
  void display() const {
    for (size_t i{}; i < size; i++) {
      std::cout << arr[i] << std::endl;
    }
  }
  Stack() : size(0), top(-1), capacity(size + 10) { arr = new T[capacity]; }

  void push(T val) {
    if (isFull()) {
      expandCapacity();
    }
    arr[++top] = val;
    size++;
  }
  ~Stack() { delete[] arr; }
};
