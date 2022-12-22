#include "Stack.hpp"
#include <iostream>
std::string infixToPostfix(std::string &operation);
void asteroidCollision(int *arr, int len);
int main() {

  std::string op{"(1+3)*5-8/2"};

  std::string result = infixToPostfix(op);

  std::cout << result << std::endl;

  int arr[3] = {8, -8, 2};

  asteroidCollision(arr, 3);

  Stack<int> myStack{};
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(10);
  myStack.push(1000);
  myStack.display();
  std::cout << "peak: " << myStack.peek() << std::endl;
  std::cout << "stack size: " << myStack.getSize() << std::endl;
  std::cout << "last element: " << myStack.pop() << std::endl;
  std::cout << "stack size: " << myStack.getSize() << std::endl;

  std::string t{"o thanos einai gay"};

  std::string revershed = Stack<char>::reverseWords(t);
  std::cout << "revershed" << revershed << std::endl;

  int revershedNum = Stack<int>::reverseNum(2151);
  std::cout << "revershedNum: " << revershedNum << std::endl;

  std::string paren{"({)})"};

  bool isCorrect = Stack<char>::checkParentheses(paren);

  std::cout << isCorrect << std::endl;

  std::string text = "hellllllllllllllllllllllllllllo";

  std::string noDupl = Stack<char>::removeDuplicates(text);

  std::cout << noDupl << std::endl;

  return 0;
}

void asteroidCollision(int *arr, int len) {
  Stack<int> ast{};

  for (int i{}; i < len; i++) {
    int asteroid = arr[i];

    bool isExploded = false;
    while (!ast.isEmpty() && asteroid < 0 && ast.peek() > 0) {
      if (ast.peek() < -asteroid) {
        ast.pop();
        continue;
      } else if (ast.peek() == -asteroid) {
        ast.pop();
      }
      isExploded = true;
      break;
    }
    if (!isExploded) {
      ast.push(asteroid);
    }
  }
  ast.display();
}

int operatorPrecedence(char operatorCh) {
  if (operatorCh == '+' || operatorCh == '-') {
    return 1;
  } else if (operatorCh == '*' || operatorCh == '/') {
    return 2;
  }
  return 0;
}

std::string infixToPostfix(std::string &operation) {
  std::string result{};
  Stack<char> tokens{};
  for (int i{}; i < operation.size(); i++) {
    if (std::isdigit(operation[i])) {
      result += operation[i];
    } else if (operation[i] == '(') {
      tokens.push(operation[i]);
    } else if (operation[i] == ')') {
      while (tokens.peek() != '(') {
        std::cout << "i" << std::endl;
        result += tokens.pop();
      }
      tokens.pop();

    } else {

      while (operatorPrecedence(operation[i]) <=
             operatorPrecedence(tokens.peek())) {
        result += tokens.pop();
      }
      tokens.push(operation[i]);
    }
  }
  while (!tokens.isEmpty()) {
    result += tokens.pop();
  }
  return result;
}
