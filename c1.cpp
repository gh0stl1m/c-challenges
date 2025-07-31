#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

  int number;
  cout << "Enter your favorite number: " << endl;
  cin >> number;

  if (int(number) == 24) {

    std::cout << "That is my favorite number too" << std::endl;
    return 0;
  }

  std::cout << "My favorite number is 24" << std::endl;

  return 0;
}
