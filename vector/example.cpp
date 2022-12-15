#include "Vector.hpp"
#include <string>

int main() {

  Vector<int> vec{11, 12, 13};

  Vector<int> empty{};
  empty.pushBack(50);
  empty.print();
  std::cout << "print first vec\n";
  vec.print();

  std::cout << "print second vec\n";
  Vector<int> copyVec{vec};
  copyVec.print();

  std::cout << "print third vec\n";
  Vector<int> moveVec{std::move(Vector<int>{11, 12, 13})};
  moveVec.pushBack(15);
  moveVec.print();

  std::cout << "print fourth vec\n";
  Vector<int> copyAssignVec{5, 6, 7};
  copyAssignVec = vec;
  copyAssignVec.pushBack(22);
  copyAssignVec.print();

  std::cout << "print fifth vec\n";
  Vector<int> moveAssignmentVec{};
  moveAssignmentVec = Vector<int>{12, 15, 82};
  moveAssignmentVec.pushBack(200);
  moveAssignmentVec.print();

  return 0;
}
