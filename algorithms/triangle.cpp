#include <iostream>
void printTriangle(int levels) {

  if (levels == 0) {

    return;
  }

  printTriangle(levels - 1);

  for (int i = 0; i < levels; i++) {

    std::cout << '*';
  }

  std::cout << "\n";
}

int main(){
	printTriangle(20);
}
