#include "BinaryHeap.hpp"

int main() {

  MinHeap<int> myHeap{};
  myHeap.push(10);
  myHeap.push(20);
  myHeap.push(30);
  myHeap.push(50);
  myHeap.push(60);
  myHeap.push(70);
  myHeap.push(80);
  myHeap.push(80);
  myHeap.push(80);
  myHeap.push(80);
  myHeap.push(80);
  myHeap.pop();
  std::cout << *myHeap.top() << std::endl;

  std::vector<int> myVec{1, 23, 5, 8, 9};

  MinHeap<int> mySecHeap{myVec};

  return 0;
}
