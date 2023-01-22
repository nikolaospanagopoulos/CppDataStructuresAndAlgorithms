#include "BinaryHeap.hpp"

int main() {

  MinHeap<int> myHeap2{};
  myHeap2.push(5);
  myHeap2.push(1);
  myHeap2.push(78);
  myHeap2.push(76);
  myHeap2.push(32);
  myHeap2.push(33);
  myHeap2.push(34);
  myHeap2.push(66);
  myHeap2.push(69);
  myHeap2.push(3);
  myHeap2.push(8);
  myHeap2.push(9);
  myHeap2.push(4);
  myHeap2.push(56);
  myHeap2.push(52);
  myHeap2.push(53);

  while (!myHeap2.isEmpty()) {
    std::cout << *myHeap2.top() << std::endl;
    myHeap2.pop();
  }

  std::vector<int> myVec{1, 5, 8, 9, 6, 5, 4};

  MinHeap<int> myHeap3{myVec};

  while (!myHeap3.isEmpty()) {
    std::cout << *myHeap3.top() << std::endl;
    myHeap3.pop();
  }

  return 0;
}
