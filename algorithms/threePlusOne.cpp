#include <iostream>

void threeNplusOne(int num) {

  if (num == 1) {

    std::cout << 1 << std::endl;

    return;
  }

  std::cout << num << std::endl;

  if (num % 2 == 0) {

    threeNplusOne(num / 2);

  } else {

    threeNplusOne(3 * num + 1);
  }
}
int threeNplusOneLength(int num) {

  if (num == 1) {

    return 1;
  }

  if (num % 2 == 0) {

    return threeNplusOneLength(num / 2) + 1;

  } else {

    return threeNplusOneLength(3 * num + 1) + 1;
  }
}

int main(){

}
