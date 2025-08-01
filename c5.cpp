#include <cctype>
#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
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

float mean_arr(vector<int> arr) {

  float mean{0};

  for (auto elem : arr) {

    mean += elem;
  }

  mean = mean / arr.size();

  return mean;
}

int smalles_value(vector<int> arr) {

  int smallest{numeric_limits<int>::max()};
  for (auto elem : arr) {

    if (elem < smallest)
      smallest = elem;
  }

  return smallest;
}

int biggest_value(vector<int> arr) {

  int biggest_value{numeric_limits<int>::min()};
  for (auto elem : arr) {

    if (elem > biggest_value)
      biggest_value = elem;
  }

  return biggest_value;
}

int number_times(vector<int> arr, int number_to_find) {

  int times{0};
  for (auto elem : arr) {
    if (elem == number_to_find)
      times++;
  }

  return times;
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
    cout << "T - Display number of times a number is repeated" << endl;
    cout << "Q - Quit" << endl;
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
    case 'm': {

      float mean_total = mean_arr(numbers);
      cout << "The mean is: " << mean_total << endl;
      break;
    }
    case 's': {

      int small_number = smalles_value(numbers);
      cout << "The smallest number of the array is: " << small_number << endl;

      break;
    }
    case 'l': {

      int biggest = biggest_value(numbers);
      cout << "The biggest number of the array is: " << biggest << endl;
      break;
    }
    case 't': {

      int number_to_find;
      cout << "Enter the number to find: " << endl;
      cin >> number_to_find;
      int number_repeated_times = number_times(numbers, number_to_find);
      cout << "The number " << number_to_find << " has been found "
           << number_repeated_times << " times" << endl;
      break;
    }
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
