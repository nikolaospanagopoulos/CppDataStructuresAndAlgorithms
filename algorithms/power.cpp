#include <iostream>

int powerCalc(int num, int power) {

  if (power == 0) {

    return 1;
  }

  return powerCalc(num, power - 1) * num;
}

int main() { std::cout << powerCalc(2, 5) << std::endl; }
