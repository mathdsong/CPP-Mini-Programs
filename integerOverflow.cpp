/*
Write a program that inputs two positive integers of, at most, 20 digits and outputs the sum of the numbers.
If the sum of the numbers has more than 20 digits, output the sum with the message The sum of the numbers overflows.
Your program must, at least, contain a function to read and store a number into an array and another function to output the sum of the numbers. */

#include <iostream>
#include <string>
#include <vector>

const int maxDigits = 20;

// read a number as a string
int readNum(int list[]) {
  std::string numStr;
  std::cin >> numStr;
  // store each digit of the number in reverse order into the array
  int len = numStr.length();
  for (int i = len - 1; i >= 0; --i) {
    list[len - i - 1] = numStr[i] - '0';
  }
  return len;
}

// store the sum in a vector
void sumNum(int list1[], int numOfElementsList1, int list2[], int numOfElementsList2) {
  int maxLength = std::max(numOfElementsList1, numOfElementsList2);
  std::vector<int> sum(maxLength);
  int carry = 0;

  for (int i = 0; i < maxLength; ++i) {
    int digit1 = (i < numOfElementsList1) ? list1[i] : 0;
    int digit2 = (i < numOfElementsList2) ? list2[i] : 0;
    int digitSum = digit1 + digit2 + carry;
    sum[i] = digitSum % 10;
    carry = digitSum / 10;
  }
  // the last carry
  if (carry > 0) {
    maxLength += 1;
    sum[maxLength] = carry;
  }

  if (maxLength > maxDigits) {
    std::cout << "The sum of the numbers overflows" << std::endl;
  } else {
    std::cout << "Sum: ";
    for (int i = maxLength - 1; i >= 0; --i) {
      std::cout << sum[i];
    }
    std::cout << std::endl;
  }
}

int main() {
  std::cout << "Enter two positive integers of at most 20 digits each:" << std::endl;
  int number1[maxDigits];
  int number2[maxDigits];
  int length1 = readNum(number1);
  int length2 = readNum(number2);
  sumNum(number1, length1, number2, length2);
  return 0;
}