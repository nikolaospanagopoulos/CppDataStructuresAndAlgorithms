#include "Stack.hpp"
#include <iostream>
int main() {

  Stack<int> myStack{};
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(1000);
  myStack.display();
  std::cout << "peak: " << myStack.peek() << std::endl;
  std::cout << "stack size: " << myStack.getSize() << std::endl;
  std::cout << "last element: " << myStack.pop() << std::endl;
  std::cout << "stack size: " << myStack.getSize() << std::endl;

  std::string t{"o thanos einai gay"};

  std::string revershed = Stack<char>::reverseWords(t);
  std::cout << "revershed" << revershed << std::endl;

  int revershedNum = Stack<int>::reverseNum(2151);
  std::cout << "revershedNum: " << revershedNum << std::endl;

  return 0;
}
