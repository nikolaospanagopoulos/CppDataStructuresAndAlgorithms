#include <iostream>

// find the two largest values in array

int main() {

  int numArr[] = {5, 500, 895, 5, 200};

  int arraySize = 5;

  int max1, max2;

  if (numArr[0] >= numArr[1]) {
    max1 = numArr[0];
    max2 = numArr[1];
  } else {
    max2 = numArr[0];
    max1 = numArr[1];
  }

  for (int i{2}; i < arraySize; i++) {
    if (numArr[i] >= max1) {
      max2 = max1;
      max1 = numArr[i];
    } else if (numArr[i] > max2) {
      max2 = numArr[i];
    }
  }

  std::cout << "max1 value: " << max1 << " max2 value: " << max2 << std::endl;

  return 0;
}
