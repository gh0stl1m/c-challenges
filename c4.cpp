#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
 * Challenge: Write a progman that ask the user to enter the following:
 * An integer representing the number of cents
 *
 * You may assume that the number of cents enterede is greater than or equal to
 * zero.
 *
 * The program should the ndisplay how to provide that change to the user.
 *
 * In the US:
 *  1 dollar is 100 cents
 *  1 quarter is 25 cents
 *  1 dime is 10 cents
 *  1 nickel is 5 cents
 *  1 penny is 1 cent.
 */

int main() {

  int change{0};

  cout << "Enter an amount in cents: " << endl;
  cin >> change;

  int balance{0};

  int dollar = change / 100;
  balance = change % 100;
  int quarter = balance / 25;
  balance = balance % 25;
  int dime = balance / 10;
  balance = balance % 10;
  int nickel = balance / 5;
  balance = balance % 5;
  int penny = balance / 1;
  balance = balance % 1;

  cout << "Change for cents: \n";
  cout << "Dollars: " << dollar << endl;
  cout << "Quarter: " << quarter << endl;
  cout << "Dime: " << dime << endl;
  cout << "Nickel: " << nickel << endl;
  cout << "Penny: " << penny << endl;

  return 0;
}
