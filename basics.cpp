// #include <functional>
#include <iostream>

using namespace std;

// std::function<int(int)> makeLambda(int a) {
//   return [a](int b) { return a + b; };
// }

bool is_palindrome(int number) {

  int reverse = 0, reminder = 0, temp = number;

  while (temp != 0) {

    reminder = temp % 10;
    reverse = reverse * 10 + reminder;
    temp = temp / 10;
  }

  return reverse == number;
}

int power_number_recursive(int base, int exponent) {

  if (base == 0) {
    return 0;
  }

  if (exponent == 0) {
    return 1;
  }

  return base * power_number_recursive(base, exponent - 1);
}

int count_digits(int number) {

  if (abs(number) / 10 == 0) {
    return 1;
  }

  return 1 + count_digits(number / 10);
}

int nth_fibonacci(int number) {

  if (number == 0) {
    return 0;
  }
  if (number == 1) {
    return 1;
  }

  return nth_fibonacci(number - 1) + nth_fibonacci(number - 2);
}

double average_marks(double marks[], int arrSize) {

  double average = 0;
  double sum = 0;

  for (int i = 0; i < arrSize; i++) {

    sum += marks[i];
  }

  average = sum / arrSize;

  return average;
}

void left_rotate(int arr[], int arrSize) {

  int lastIndex = arr[0];
  int i;
  for (i = 0; i < arrSize - 1; i++) {

    arr[i] = arr[i + 1];
  }

  arr[i] = lastIndex;
}

int add_diagonal_matrix(int matrix[3][3], int rowSize, int colSize) {

  int sum = 0;

  for (int i = 0; i < rowSize; i++) {

    for (int j = 0; j < colSize; j++) {

      if (i == j) {
        sum += matrix[i][j];
      }
    }
  }

  return sum;
}

void set_odd_arr(int *arr, int size) {

  for (int i = 0; i < size; i++) {

    if (arr[i] % 2 != 0) {
      arr[i] = -1;
    }
  }
}

void delete_element_arr(int *&arr, int size, int index) {

  int *resizeArray = new int[size - 1];

  for (int i = 0; i < size; i++) {

    if (i == index) {
      continue;
    };
    resizeArray[i] = arr[i];
  }

  for (int i = 0; i < 3; i++) {
    cout << resizeArray[i] << " ";
  }

  cout << endl;

  arr = resizeArray;
  delete[] arr;
}

struct Student {
  string name;
  int rollNumber;
  int marks;
};

struct ComplexNumber {
  double real;
  double imaginary;
};

ComplexNumber substract(ComplexNumber cn1, ComplexNumber cn2) {

  ComplexNumber result;
  result.real = cn1.real - cn2.real;
  result.imaginary = cn1.imaginary - cn2.imaginary;

  return result;
}

int main() {

  cout << "Hello World" << endl;

  // Example: Take user input
  // float number;
  // cout << "Please enter a number: ";
  //
  // cin >> number;
  // cout << "You have entered: " << number << endl;
  // Example: Cast double into int
  double double_value = 70.896;
  int int_value = (int)double_value;
  cout << "Casted value: " << int_value << endl;

  // Example: Find previous alphabet
  char character = 'B';
  int character_number = character - 1;
  char new_character = (char)character_number;

  cout << "Previos character is " << new_character << endl;

  int pal_number = 2002;
  int non_pal_number = 2523;

  bool pal_1 = is_palindrome(pal_number);
  cout << "Is pal_1 palindrome? " << pal_1 << endl;

  bool pal_2 = is_palindrome(non_pal_number);
  cout << "Is pal_2 palindrome? " << pal_2 << endl;

  // Example: Generic lambdas

  // auto add5 = makeLambda(5);
  //
  // auto add10 = makeLambda(10);
  //
  // cout << "Add5 result: " << add5(5) << endl;
  // cout << "Add10 result: " << add5(10) << endl;

  // Example: power of a number recursive
  int powerNumber = power_number_recursive(2, 2);
  cout << "Power number is: " << powerNumber << endl;

  // Example: Count number digits
  int numberOfDigits = count_digits(234);
  cout << "The number of digits is: " << powerNumber << endl;

  // Example: nth fibonacci
  int fiboNumber = nth_fibonacci(5);
  cout << "The nth fibonacci is: " << fiboNumber << endl;

  // Example: Average marks
  double studentMarks[] = {10.5, 67.8, 98.6, 31.2};
  double average = average_marks(studentMarks, 4);
  cout << "The studens mark average is: " << average << endl;

  // Example: Shif left array
  int arr1[] = {1, 2, 3, 4, 5};
  left_rotate(arr1, 5);

  for (int i = 0; i < 5; i++) {

    cout << arr1[i] << " ";
  }
  cout << endl;

  // Exmaple add main diagonal
  int sumMatrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int sumOfDiagonalMtx = add_diagonal_matrix(sumMatrix, 3, 3);

  cout << "The sum of diagonal of th matrix is: " << sumOfDiagonalMtx << endl;

  // Dynamic allocation
  int *ptr = nullptr;
  // Stores the starting address of dynamically reserved 4 bytes(because int
  // datatype uses 4bytes) in ptr
  ptr = new int;
  *ptr = 100;
  cout << "The value of ptr is: " << *ptr << endl;

  // Free the space using by ptr
  delete ptr;
  ptr = nullptr;

  // Dynamic arrays
  int *Array = new int(5);
  for (int i = 0; i < 5; i++) {
    Array[i] = i;
  }

  for (int i = 0; i < 5; i++) {
    cout << Array[i] << " ";
  }
  cout << endl;
  delete Array;
  Array = nullptr;

  // Example: Set odd
  int arrOdd[] = {10, 67, 31, 98};
  set_odd_arr(arrOdd, 4);

  for (int i = 0; i < 4; i++) {
    cout << arrOdd[i] << "  ";
  }
  cout << endl;

  // Example: Delete index from array
  int *deleteArray = new int[4]{10, 67, 98, 31};
  cout << "Delete array" << endl;
  for (int i = 0; i < 4; i++) {
    cout << deleteArray[i] << " ";
  }
  cout << endl;

  delete_element_arr(deleteArray, 4, 2);
  deleteArray = nullptr;

  Student stdn1;
  Student *stdnptr = &stdn1;

  stdnptr->name = "John Doe";
  stdnptr->rollNumber = 12;
  stdnptr->marks = 5;

  cout << "s1 Information:" << endl;
  cout << "Name = " << stdnptr->name << endl;
  cout << "Roll Number = " << stdnptr->rollNumber << endl;
  cout << "Marks = " << stdnptr->marks << endl;

  ComplexNumber cn1 = {12.3, 67.4};
  ComplexNumber cn2 = {54.2, 90.8};

  ComplexNumber sResult = substract(cn1, cn2);

  cout << "Result is: " << sResult.real << ", " << sResult.imaginary << endl;

  return 0;
}
