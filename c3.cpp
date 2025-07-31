#include <iostream>
#include <vector>

using std::cout;
using std::endl;

/*
 * Challenge: Declare 2 empty vectors of integers names 1 and vector 2,
 * respectively.
 *
 * Add 10 and 20 to vecto1 dynamically using push_back
 * Display teh elements in vector 1 using the at() method ad well as its size
 * using the size() method.
 *
 * Add 100 and 200 to vector 2 dynamically using push_back
 * Display the elements in vector 2 using the at() method as well as its size
 * using the size() method.
 *
 * Declare an empty 2D vector called vector_2d
 * Remember, that a 2D vector is a vecor of vector<int>
 *
 * Add vector1 to vector_2 dynamically using push_back
 * Add vector2 to vector_2 dunamically using push_back
 *
 * Display the elements in vector-2d using the at() method
 *
 * Change vector1.at(0) to 1000
 *
 * Display the elments in vector_2d again using the at() method
 *
 * Display the elements in vector 1
 *
 *
 */

int main() {

  std::vector<int> vector1;
  std::vector<int> vector2;

  vector1.push_back(10);
  vector1.push_back(20);

  cout << "Vector 1: " << vector1.at(0) << ", " << vector1.at(1) << endl;
  cout << "Vector 1 size: " << vector1.size() << endl;

  vector2.push_back(100);
  vector2.push_back(200);
  cout << "Vector 2: " << vector2.at(0) << ", " << vector2.at(1) << endl;
  cout << "Vector 2 size: " << vector2.size() << endl;

  std::vector<std::vector<int>> matrix;

  matrix.push_back(vector1);
  matrix.push_back(vector2);

  cout << "Matrix[0][0]: " << matrix.at(0).at(0) << endl;
  cout << "Matrix[0][1]: " << matrix.at(0).at(1) << endl;
  cout << "Matrix[1][0]: " << matrix.at(1).at(0) << endl;
  cout << "Matrix[1][1]: " << matrix.at(1).at(1) << endl;

  vector1.at(0) = 1000;
  cout << "Vector 1 modified: " << vector1.at(0) << ", " << vector1.at(1)
       << endl;

  return 0;
}
