#include <cctype>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::tolower;
using std::vector;

/*
 * Challenge: The challenge is about to create a list of integrers allowing the
 * user to select options from the menu to perform operations in that list.
 *
 * Your program should display a menu of options as follows:
 *
 * P - Print Numbers
 * A - Add number
 * M - Display the mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 *
 * Enter your choice:
 *
 * The program should only accept valid choices from the user, both upper and
 * lower cases should be allowed. If an illegal choice is made, you should
 * display 'Unknow selection, please try again.' and the menu options should be
 * displayed again.
 *
 * Some additional functionalities are:
 * - Search for a number and if found display the number of times it occurs in
 * the list
 * - Clearing out the list
 */

void print_numbers(vector<int> arr) {

  for (auto number : arr) {
    cout << number << ", ";
  }
  cout << endl;
}

void add_number(vector<int> *arr, int new_number) {

  arr->push_back(new_number);
  cout << "Number " << new_number << " was successfully added" << endl;
  cout << endl;
}

int main() {

  int app_flag = 1;
  vector<int> numbers;

  do {

    cout << "=================================" << endl;
    cout << "Program Menu: " << endl;
    cout << "=================================" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add number" << endl;
    cout << "M - Display the mean of numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Quit" << endl;
    cout << "=================================" << endl;
    cout << "Enter yout choice: ";

    char choice_menu;
    cin >> choice_menu;

    switch (tolower(choice_menu)) {
    case 'p':

      print_numbers(numbers);
      break;
    case 'a':

      int new_number;
      cout << "Enter number to be added: " << endl;
      cin >> new_number;
      add_number(&numbers, new_number);
      break;
    case 'm':
      cout << "option p" << endl;
      break;
    case 's':
      cout << "option p" << endl;
      break;
    case 'l':
      cout << "option p" << endl;
      break;
    case 'q': {
      cout << "Good Bye!";
      app_flag = 0;
      break;
    }
    default:
      cout << "Invalid option, please try again." << endl;
    }

  } while (app_flag != 0);
}
