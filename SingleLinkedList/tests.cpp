#include "SLL.hpp"
#include <iostream>
#include <string>

int main() {

  std::cout << "*************test1: create empty, append**********************"
            << std::endl;
  SingleLinkedList<int> firstList{};
  firstList.insertEnd(50);
  firstList.insertEnd(50);
  firstList.insertEnd(50);
  firstList.insertEnd(50);
  firstList.insertEnd(50);

  firstList.print();
  std::cout << firstList.getSize() << std::endl;

  std::cout << "*************test2 initializer list***************************"
            << std::endl;

  SingleLinkedList<std::string> stringList{"123", "nikos"};
  std::cout << "size: " << stringList.getSize() << std::endl;
  stringList.print();
  std::cout << "copy constructor test" << std::endl;
  SingleLinkedList<std::string> copyList{stringList};

  std::cout << "size: " << copyList.getSize() << std::endl;
  copyList.print();
  std::cout << "***************copy assignment test**************" << std::endl;
  SingleLinkedList<int> testFive{1, 5, 8};
  std::cout << "size: " << testFive.getSize() << std::endl;
  testFive.print();
  SingleLinkedList<int> testSix{5, 8, 9};
  std::cout << "before \n";
  std::cout << "size: " << testSix.getSize() << std::endl;
  testSix.print();

  testSix = testFive;

  testSix.insertEnd(58);
  testSix.insertEnd(59);

  std::cout << "after\n";
  std::cout << "size: " << testSix.getSize() << std::endl;

  testSix.print();
  std::cout << "************test find el by index*************\n";
  std::cout << "found index: " << testSix.getNth(1) << std::endl;
  std::cout << "************test find el by value*************\n";
  std::cout << "found el: " << testSix.find(555) << std::endl;

  std::cout << "***************test insert front*************\n";

  SingleLinkedList<int> testSeven{5, 8, 9};
  testSeven.insertFront(8);
  testSeven.insertFront(68);
  testSeven.insertFront(39);

  std::cout << "size: " << testSeven.getSize() << std::endl;
  testSeven.print();

  std::cout << "*************test eight*************\n";

  SingleLinkedList<int> testEight{};
  testEight.insertFront(5);
  testEight.insertFront(3);
  testEight.insertFront(6);
  testEight.insertFront(8);
  testEight.insertFront(9);

  std::cout << "size: " << testEight.getSize() << std::endl;
  testEight.print();

  std::cout << "**************test nine ******************" << std::endl;
  SingleLinkedList<int> testNine{5, 87, 7};

  testNine.deleteFront();
  testNine.deleteFront();
  testNine.deleteFront();
  testNine.deleteFront();

  std::cout << "size: " << testNine.getSize() << std::endl;
  testNine.print();
  std::cout << "**************test ten ******************" << std::endl;

  SingleLinkedList<int> testTen{5, 8, 9, 7, 2};

  std::cout << "size: " << testTen.getSize() << std::endl;
  testTen.print();

  std::cout << "reverse find test: " << testTen.getNthFromBack(3)->data
            << std::endl;
  std::cout << "****************test eleven comparison********" << std::endl;
  SingleLinkedList<int> firstListToCompare{1, 2, 3};
  SingleLinkedList<int> secondListToCompare{1, 2, 1};

  if (firstListToCompare.isSameListWithoutSize(secondListToCompare)) {
    std::cout << "lists are equal \n";
  } else {
    std::cout << "lists are not equal \n";
  }
  std::cout << "***************test deletion********************\n";
  SingleLinkedList<int> toDelete{1, 2, 3};

  std::cout << "size before delete: " << toDelete.getSize() << std::endl;
  toDelete.print();
  toDelete.deleteNodeAtIndex(2);
  toDelete.deleteNodeAtIndex(1);
  toDelete.deleteNodeAtIndex(0);
  toDelete.insertFront(10);
  toDelete.insertEnd(10);
  std::cout << "size after delete: " << toDelete.getSize() << std::endl;
  toDelete.print();

  std::cout << "*****************delete many by value*******************\n";
  SingleLinkedList<int> deleteMany{1, 1, 2, 3, 6, 9, 3, 2, 1, 1};

  std::cout << "size before delete: " << deleteMany.getSize() << std::endl;
  deleteMany.print();
  deleteMany.deleteDuplicates();
  deleteMany.deleteAllOccurancesOfValue(1);
  std::cout << "size after delete: " << deleteMany.getSize() << std::endl;
  deleteMany.print();
  std::cout << "******test insert sorted******************\n";
  SingleLinkedList<int> testSort{};
  testSort.insertSorted(10);
  testSort.insertSorted(100);
  testSort.insertSorted(22);
  testSort.insertSorted(50);
  testSort.insertSorted(110);
  testSort.insertSorted(1);
  testSort.insertFront(12121);
  testSort.insertEnd(565);

  testSort.print();

  std::cout << "size: " << testSort.getSize() << std::endl;

  std::cout << "**************test delete even****************\n";
  SingleLinkedList<int> toDeleteEven{1, 2, 5, 8, 9};

  std::cout << "size before: " << toDeleteEven.getSize() << std::endl;
  toDeleteEven.print();
  toDeleteEven.deleteEvenPositions();
  std::cout << "size after: " << toDeleteEven.getSize() << std::endl;
  toDeleteEven.print();

  std::cout << "**************test swap******************\n";
  SingleLinkedList<int> toSwap{1, 2, 3, 4};
  toSwap.swapPairs();
  toSwap.print();
  std::cout << "*************test reverse*******************\n";
  SingleLinkedList<char> toReverse{'d', 'c', 'g', 'f', 'y'};

  SingleLinkedList<char> *newList = toReverse.reverse();
  newList->insertEnd('f');
  newList->print();

  SingleLinkedList<char> toReverse2{'d', 'c', 'g', 'f', 'y'};
  std::cout << "before reversing nodes....\n";
  toReverse2.print();
  std::cout << "after reversing nodes....\n";
  toReverse2.reverseNodes();
  toReverse2.print();
  return 0;
}
