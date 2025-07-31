#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
 * Challenge: Frank's carpet cleaning service
 * Charges:
 *      $25 per small room
 *      $35 per large room
 * Salex tax is 6%
 * Estimates are valid for 30 day
 *
 * Prompt the user for the number of small and large rooms they would like
 * cleaned and provide an estimate
 */
int main() {

  int large_rooms{0};
  int small_rooms{0};

  cout << "Enter number of large rooms: " << endl;
  cin >> large_rooms;

  cout << "Enter number of small rooms: " << endl;
  cin >> small_rooms;

  cout << "Price per small room: $25" << endl;
  cout << "Price per large room: $35" << endl;

  int rooms_stimate = (large_rooms * 35) + (small_rooms * 25);
  cout << "Cost: $" << rooms_stimate << endl;

  float tax_stimate = rooms_stimate * 0.06;
  cout << "Tax: $" << tax_stimate << endl;

  cout << "===================== " << endl;

  float total = rooms_stimate + tax_stimate;
  cout << "Total estimate: $" << total << endl;
  cout << "This estimate is valid for 30 days" << endl;
  return 0;
}
