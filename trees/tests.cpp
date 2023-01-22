#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"
#include <stack>

BinaryTree<char> *postfixToTree(std::string expression) {
  std::stack<BinaryTree<char> *> tree;
  for (auto &i : expression) {
    BinaryTree<char> *current = new BinaryTree<char>{i};
    if (!std::isdigit(i)) {
      current->right = tree.top();
      tree.pop();
      current->left = tree.top();
      tree.pop();
    }
    tree.push(current);
  }
  BinaryTree<char> *root = tree.top();
  return root;
}

int main() {

  BinaryTree<int> myTree{1};

  std::cout << std::boolalpha;
  std::cout << "******************test creation***********\n";
  myTree.add(std::vector<int>{1, 2, 3}, std::vector<char>{'L', 'L', 'L'});
  myTree.add(std::vector<int>{1, 2, 4}, std::vector<char>{'L', 'L', 'R'});
  myTree.add(std::vector<int>{1, 2, 4}, std::vector<char>{'L', 'L', 'R'});
  myTree.add(std::vector<int>{1, 5, 8}, std::vector<char>{'L', 'R', 'R'});

  std::cout << "*******************test print***************\n";
  myTree.print();
  std::cout << "*******************test size***************\n";
  std::cout << myTree.getSize() << std::endl;
  std::cout << "*******************test right***************\n";
  std::cout << "------->height: " << myTree.getHeight() << std::endl;
  std::cout << "*******************test leaf nodes***************\n";
  std::cout << "------->leaf nodes number: " << myTree.getLeafNodesCount()
            << std::endl;
  std::cout << "*******************search nodes***************\n";
  std::cout << "------->test value exists: " << myTree.exists(0) << std::endl;
  std::cout << "*******************test if tree is peefect***************\n";
  std::cout << "------->test is perfect: " << myTree.isPerfect() << std::endl;
  std::cout << "**********test traverseLeftBoundry*************************\n";
  myTree.traverseLeftBoundry();

  std::cout << "****************postfix to tree***************\n";
  std::string postfix{"23+4*"};
  BinaryTree<char> *result = postfixToTree(postfix);

  result->print();

  std::cout << "size: " << result->getSize() << std::endl;

  delete result;

  std::cout << "***********print by levels**********************\n";
  myTree.printByLevel();

  std::cout << '\n';
  std::cout << '\n';
  std::cout << '\n';
  std::cout << '\n';
  std::cout << "********************BINARY SEARCH TREE**************\n";
  BinarySearchTree<int> mySearchTree(1);

  mySearchTree.insert(5);
  mySearchTree.insert(8);
  mySearchTree.insert(7);
  mySearchTree.insert(2);
  mySearchTree.insert(3);
  mySearchTree.insert(6);

  mySearchTree.printByLevel();

  std::cout << "******************find node \n";
  std::cout << "found node:" << mySearchTree.searchNode(3)->data << std::endl;

  std::cout << "is BST: " << std::endl;
  std::cout << std::boolalpha;
  std::cout << mySearchTree.isBst() << std::endl;
  std::cout << "*************test find LCA***************\n";
  std::cout << mySearchTree.getLca(5, 8)->data << std::endl;
  std::cout << "******************value exists*************\n";
  std::cout << "value 5 exists: " << mySearchTree.valExists(5) << std::endl;
  std::cout << "********************test BST creation********\n";
  std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9};
  BinarySearchTree<int> *myBstTree = mySearchTree.buildBst(values);
  myBstTree->printByLevel();
  delete myBstTree;
  std::cout << "**************test min************************\n";

  std::cout << "min value: " << mySearchTree.getMin() << std::endl;
  std::cout << "************find ancestor***********************\n";
  BinarySearchTree<int> testSTree{15};
  testSTree.insert(6);
  testSTree.insert(8);
  testSTree.insert(10);
  testSTree.insert(14);
  testSTree.printByLevel();
  std::pair<bool, int> resultSucccessor = testSTree.successor(14);

  std::cout << "successor exists: " << resultSucccessor.first
            << ", successor is: " << resultSucccessor.second << std::endl;
  // testSTree.deleteValue(14);
  testSTree.printByLevel();
  std::cout << "test successorQueries \n";
  std::vector<int> answers;
  std::vector<int> traversal;
  std::deque<int> queries{14};
  testSTree.successorQueries(queries, answers, traversal);
  std::cout << "answer: \n";
  for (auto &i : answers) {
    std::cout << i << std::endl;
  }
  return 0;
}
