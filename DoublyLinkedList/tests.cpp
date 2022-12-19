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

  return 0;
}
