#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

/*
 * Challenge 6: Substitution cypher
 *
 * A simple a very old method of sending secret messages is the substitution
 * cipher. You might have used this cipher with your friends when you were a
 * kid. Basically, each letter of the alphabet gets replaced by another letter
 * of the alphabet, For example, every 'a' get replaced with an 'X', and every
 * 'b' gets replaced with a 'Z', etc.
 *
 * Write a program thats ask a user to enter a secret message.
 *
 * Encrypt this message using the substitution cipher and display the encrypted
 * message, then decrupted the encrypted message back to the original message.
 *
 * You may use the 2 strings below for your substitution, for example, to
 * encrypt you can replace the character at position n in the alphabe with the
 * character at position n in the key.
 *
 * To decrypt you can replace the character at position n in key
 * with the character at position n in alphabet.
 *
 */

string encrypt_caesar(string plainText, int key) {

  string encrypted_message{};

  for (char character : plainText) {

    if (std::isalpha(character)) {

      char base = std::isupper(character) ? 'A' : 'a';
      character = static_cast<char>(base + (character - base + key) % 26);
    }

    encrypted_message += character;
  }

  return encrypted_message;
}

string decrypt_ceasar(string encrypted_message, int key) {

  string decryped_message{};

  for (char character : encrypted_message) {

    if (std::isalpha(character)) {

      char base = std::isupper(character) ? 'A' : 'a';
      // In order to handle negative results I'm adding a guard adding 26 before
      // applying the mod operation
      character = static_cast<char>(base + (character - base - key + 26) % 26);
    }
    decryped_message += character;
  }

  return decryped_message;
}

int main() {

  string message{};
  int key;

  cout << "Enter a message to encrypt: ";
  getline(cin, message);
  cout << endl;
  cout << "Enter a key (an integer): ";
  cin >> key;

  string encryped_message = encrypt_caesar(message, key);

  cout << "Message encrypted: " << endl;
  cout << encryped_message << endl;

  string decryped_message = decrypt_ceasar(encryped_message, key);
  cout << "Message decrypted: " << decryped_message << endl;
  cout << endl;

  return 0;
}
