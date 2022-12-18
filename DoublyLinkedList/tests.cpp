#include "DoublyLinkedList.hpp"

int main() {

  std::cout << "*********test insert************\n";
  DoublyLinkedList<int> firstList{};
  std::cout << "size before insertion " << firstList.getSize() << std::endl;

  firstList.insertSorted(5);
  firstList.insertSorted(9);
  firstList.insertSorted(6);
  firstList.insertSorted(8);
  firstList.insertSorted(3);

  firstList.printReverse();
  std::cout << "size after insertion " << firstList.getSize() << std::endl;

  return 0;
}
