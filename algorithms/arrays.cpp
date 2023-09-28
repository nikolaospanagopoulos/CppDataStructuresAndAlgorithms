#include <iostream>

int arrMax(int *arr, int len) {

  if (len == 0) {

    return arr[0];
  }

  int subResult = arrMax(arr, len - 1);

  return std::max(subResult, arr[len - 1]);
}

int arrSum(int *arr, int len) {

  if (len == 0) {
    return 0;
  }

  return arrSum(arr, len - 1) + arr[len - 1];
}

int arrAvg(int *arr, int len) {
  if (len == 1) {
    return arr[0];
  }
  double subResult = arrAvg(arr, len - 1);
  subResult = subResult * (len - 1);
  return (subResult + arr[len - 1]) / len;
}
void arrInc(int *arr, int len) {
  if (len == 0) {
    return;
  }
  arrInc(arr, len - 1);
  arr[len - 1] += len - 1;
}
void arrAcc(int *arr, int len) {
  if (len == 1) {
    return;
  }

  arrAcc(arr, len - 1);
  arr[len - 1] += arr[len - 2];
}
void leftMax(int *arr, int len) {
  if (len == 1) {
    return;
  }
  leftMax(arr, len - 1);

  arr[len - 1] = std::max(arr[len - 1], arr[len - 2]);
}
int suffixSum(int *arr, int size, int elementNum) {
  if (elementNum == 0) {
    return 0;
  }
  if (size == 1) {
    return arr[0];
  }
  return suffixSum(arr, size - 1, elementNum - 1) + arr[size - 1];
}
int prefixSum(int *arr, int size, int elementNum) {
  if (elementNum == 0) {
    return 0;
  }
  if (size == 1) {
    return arr[0];
  }
  return prefixSum(arr, size - 1, elementNum - 1) + arr[elementNum - 1];
}
void rightMax(int *arr, int len, int position = 0) {
  if (len == 1) {
    return;
  }
  rightMax(arr, len - 1, position + 1);

  arr[position] = std::max(arr[position], arr[position + 1]);
}
int main() {
  int arr[] = {200, 1000, 300, 600, 200, 600, 500, 800, 100, 800};

  std::cout << arrAvg(arr, 10) << std::endl;

  std::cout << prefixSum(arr, 10, 4) << std::endl;
}
