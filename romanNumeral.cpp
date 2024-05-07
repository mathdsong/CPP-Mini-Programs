// Write a program that converts a number entered in Roman numerals to a positive integer. Your program should consist of a class, say, romanType. An object of type romanType should do the following:
// Store the number as a Roman numeral.
// Convert and store the number as a positive integer.
// Print the number as a Roman numeral or positive integer as requested by the user. The integer values of the Roman numerals are:
// M 1000
// D   500
// C   100
// L    50
// X    10
// V     5
// I     1
// Test your program using the following Roman numerals: MCXIV, CCCLIX, and MDCLXVI.
// Include necessary header files
#include <iostream>
#include <unordered_map>

// Define a class romanType
class romanType {
private:
  // Declare private variables
  std::string romanNumeral;
  int integerValue;

  // Mapping of Roman numerals to their integer values
  std::unordered_map<char, int> romanToInt = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
  };

public:
  // Constructor
  romanType() {
    std:: string romanNumeral;
    std::cout << "Enter a roman numeral:" << std::endl;
    std::cin >> romanNumeral;
    integerValue = convertToInteger(romanNumeral);
  }

  // Function to convert a Roman numeral to an integer
  int convertToInteger(const std::string& roman) {
    // Initialize the result variable to store the integer value
    int result = 0;
    // Initialize the variable to store the previous value
    int prevValue = 0;

    // Iterate over each character in the Roman numeral
    for (char c : roman) {
        // Get the integer value of the current Roman numeral character
        int currValue = romanToInt[c];
        // Add the current value to the result
        result += currValue;

        // If the previous value is less than the current value
        if (prevValue < currValue) {
            // Subtract twice the previous value from the result
            result -= 2 * prevValue;
        }

        // Update the previous value for the next iteration
        prevValue = currValue;
    }

    return result;
  }

  void printRoman() {
    std::cout << "Roman numeral: " << romanNumeral << std::endl;
  }

  void printInteger() {
    std::cout << "Integer value: " << integerValue << std::endl;
  }
};

// Main function
int main() {
  // Test cases
  romanType num1;
  // Print the Roman numeral and its corresponding integer value for each test case
  num1.printRoman();
  num1.printInteger();

  return 0;
}
