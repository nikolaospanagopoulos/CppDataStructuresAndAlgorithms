#include <iostream>

int main() {

  int arrSize = 5;
  int myArr[] = {5, 8, 9, 7, 8};

  for (int i{}; i < arrSize / 2; i++) {
    int last = arrSize - i - 1;
    int tmp = myArr[i];
    myArr[i] = myArr[last];
    myArr[last] = tmp;
  }

  std::cout << "revered array: \n";

  for (int i{}; i < arrSize; i++) {
    std::cout << " " << myArr[i] << " ";
  }

  return 0;
}
