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

  std::cout << "************test delete front*************\n";
  DoublyLinkedList<int> listToDelete{};
  listToDelete.insertFront(10);
  listToDelete.insertFront(20);
  listToDelete.insertFront(30);
  listToDelete.insertFront(40);
  listToDelete.insertFront(50);
  listToDelete.insertFront(60);
  std::cout << "size before deletion: " << listToDelete.getSize() << std::endl;
  listToDelete.printReverse();
  listToDelete.deleteEvenPositions();
  listToDelete.insertFront(500);
  listToDelete.insertEnd(510);
  std::cout << "size after deletion: " << listToDelete.getSize() << std::endl;
  listToDelete.printReverse();

  std::cout << "***************is palindrome****************\n";
  DoublyLinkedList<int> palindrome{};
  palindrome.insertEnd(1);

  std::cout << "is palindrome: " << palindrome.isPalindrome() << std::endl;

  std::cout << "******************find middle*****************\n";
  DoublyLinkedList<int> findMiddleList{};
  findMiddleList.insertEnd(1);
  findMiddleList.insertEnd(2);
  findMiddleList.insertEnd(3);
  findMiddleList.insertEnd(4);
  findMiddleList.insertEnd(5);
  findMiddleList.insertEnd(6);
  findMiddleList.insertEnd(7);
  findMiddleList.insertEnd(8);
  findMiddleList.insertEnd(9);

  std::cout << "middle is: " << findMiddleList.findMiddle()->data << std::endl;
  return 0;
}
