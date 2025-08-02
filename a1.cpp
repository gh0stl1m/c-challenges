#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
 * Assessment
 *
 * Write a C++ program that displays a Letter Pyramid from a user-provided
 * std::string. Prompt the user to enter a std::string and then from that string
 * display a Letter Pyramid as follows: It's much easier to understand the
 * Letter Pyramid given examples. If the user enters the string "ABC", then your
 * program should display:
 *  A
 * ABA
 * ABCBA
 */

// Original function
void print_pyramid_original(string message) {
  int position{0};
  int num_letters = message.length();

  for (char character : message) {
    int num_spaces = num_letters - position;
    while (num_spaces > 0) {
      cout << " ";
      --num_spaces;
    }

    for (int i = 0; i < position; i++) {
      cout << message.at(i);
    }

    cout << character;

    for (int j = position - 1; j >= 0; j--) {
      cout << message.at(j);
    }

    cout << endl;
    ++position;
  }
}

// Optimized function
void print_pyramid_optimized(const string &message) {

  const int num_letters = message.length();
  string line;
  line.reserve(num_letters * 2);

  for (int position = 0; position < num_letters; ++position) {
    line.clear();
    line.append(num_letters - position, ' ');
    line.append(message, 0, position);
    line += message[position];
    for (int j = position - 1; j >= 0; --j) {
      line += message[j];
    }
    cout << line << '\n';
  }
}

// Benchmark function template
template <typename Func>
long long benchmark_function(Func func, const string &message,
                             int iterations = 1000) {
  auto start = high_resolution_clock::now();

  for (int i = 0; i < iterations; ++i) {
    func(message);
  }

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  return duration.count();
}

int main() {

  vector<string> test_messages = {
      "HelloWorld", "PerformanceTesting",
      "ThisIsAVeryLongMessageForPerformanceTesting"};

  cout << "=== PERFORMANCE COMPARISON ===\n\n";

  for (const auto &message : test_messages) {
    cout << "Testing with message: \"" << message
         << "\" (length: " << message.length() << ")\n";
    cout << string(60, '-') << "\n";

    const int iterations = 10000;

    cout << "I/O Performance Test:\n";

    // Redirect cout to file for fair I/O comparison
    ofstream nullstream("/dev/null"); // Use "NUL" on Windows
    auto cout_backup = cout.rdbuf();
    cout.rdbuf(nullstream.rdbuf());

    auto io_time_original =
        benchmark_function(print_pyramid_original, message, 1000);
    auto io_time_optimized =
        benchmark_function(print_pyramid_optimized, message, 1000);

    cout.rdbuf(cout_backup);

    cout << "  Original I/O:  " << io_time_original
         << " microseconds (1000 iterations)\n";
    cout << "  Optimized I/O: " << io_time_optimized
         << " microseconds (1000 iterations)\n";
    cout << "  I/O Speedup:   " << (double)io_time_original / io_time_optimized
         << "x\n\n";

    cout << string(60, '=') << "\n\n";
  }

  return 0;
}
