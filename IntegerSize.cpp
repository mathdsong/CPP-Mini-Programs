/*
Write a program that will ensure the total size of an integer array will always be no more than 2MB.
*/
#include <iostream>
#include <vector>
#include <sstream>

const int twoMB = 2 * std::pow(std::pow(2, 10), 2);
// check input size
void checkInputSize() {
  std::vector<int> vec;
  std::cout << "Please enter integers to be stored into an array (size cannot exceed 2MB): ";
  std::string lineString;
  std::getline(std::cin, lineString); // read the input line and store it into lineString
  std::istringstream iss(lineString); // create an input stream for lineString
  std::string curr_int;
  int size = 0;

  while (iss >> curr_int) {
    size += sizeof(std::stoi(curr_int));
  }
  // print out total size of user's input even if it exceeds 2MB:
  std::cout << "size of your input: " << size << " bytes" << std::endl;

  // reset iss
  iss.clear();
  iss.seekg(0);

  // if the size exceeds 2MB, then invoke the program again to let user reattempt
  if (size > twoMB) {
    std::cout << "size exceeded, please retry!" << std::endl;
    checkInputSize();
  } else {
    // if the size <= 2MB, then store each integer into vector vec
    while (iss >> curr_int) {
      vec.push_back(std::stoi(curr_int));
    }
  }
}

int main() {
  checkInputSize();
  return 0;
}

