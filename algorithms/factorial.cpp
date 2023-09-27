#include <iostream>

int factorial(int num) {

  if (num == 1) {

    return 1;
  }

  return factorial(num - 1) * num;
}


int main(){
	std::cout<<factorial(5)<<std::endl;
}
