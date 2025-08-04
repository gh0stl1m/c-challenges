#include <cstddef>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

/*
 * Challenge 7:
 * Write a function named apply_all that expect two array integers and its size
 * Then dynamically allocates a new array of integers whose size is the product
 * of the product of the two arrays sizes.
 *
 * The function should loop through the second array and multiply each element
 * across each element of array 1 and store the product in a newly created
 * array.
 *
 * The function should return a pointer to the newly allocated array.
 *
 * The idea would be to also write a function that expects a pointer of the
 * array, displaying its elements.
 *
 */

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<int> split_string(const string &string_arr, char delimiter) {

  vector<int> vector_elements;
  size_t count =
      1 + std::count(string_arr.begin(), string_arr.end(), delimiter);
  vector_elements.reserve(count);

  string element;
  std::istringstream stream_elements(string_arr);

  while (getline(stream_elements, element, delimiter)) {

    try {

      vector_elements.push_back(std::stoi(element));
    } catch (const std::invalid_argument &error) {

      cerr << "Warning: The element " << element
           << " is not a valid number, skipping!" << endl;
    }
  }

  return vector_elements;
}

int *apply_all(vector<int> &arr1, vector<int> &arr2) {

  int *product_arr{nullptr};
  product_arr = new int[arr1.size(), arr2.size()];

  size_t position{0};
  for (size_t i{0}; i < arr2.size(); ++i) {

    for (size_t j{0}; j < arr1.size(); ++j) {
      product_arr[position] = arr2[i] * arr1[j];
      ++position;
    }
  }

  return product_arr;
}

void println(const vector<int> &arr) {

  size_t arr_size = arr.size();
  string stdout_message;

  stdout_message.reserve(arr_size);

  for (const int &elem : arr) {

    stdout_message += std::to_string(elem);
    stdout_message += ",";
  }

  stdout_message.pop_back();
  cout << stdout_message << endl;
}

int main() {

  string input1;
  string input2;

  cout << "Please enter the elements separated by commas(,) of the array 1: ";
  std::getline(cin, input1);
  cout << endl;

  cout << "Please enter the elements separeated by commas(,) of the array 2: ";
  std::getline(cin, input2);
  cout << endl;

  vector<int> arr_input1 = split_string(input1, ',');
  vector<int> arr_input2 = split_string(input2, ',');
  println(arr_input1);
  println(arr_input2);

  int *product_result = apply_all(arr_input1, arr_input2);

  size_t result_size = arr_input1.size() * arr_input2.size();
  vector<int> result(product_result, product_result + result_size);

  println(result);

  delete[] product_result;
  return 0;
}
