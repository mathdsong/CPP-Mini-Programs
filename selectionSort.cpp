/*
Write a version of the selection sort algorithm in a function called selectionSort that can be used to sort a string vector object.
Also, write a program to test your algorithm. The program should prompt the user for a series of names.
The string zzz should end the input stream. Output the sorted list to the console.
*/

#include <iostream>
#include <vector>
#include <string>

void selectionSort(std::vector<std::string>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; ++i) {
      int minIndex = i;
      // Iterate through the unsorted part of the vector
      for (int j = i + 1; j < n; ++j) {
          // If the current element is smaller than the assumed minimum element
          if (vec[j] < vec[minIndex]) {
              // Swap the current element with the minimum element
              std::swap(vec[j], vec[minIndex]);
          }
      }
  }
}

int main() {
  // Create a vector to store names
  std::vector<std::string> names;
  // Variable to store each name entered by the user
  std::string name;
  std::cout << "Enter names (type 'zzz' to end):\n";

  // Input loop: continue until the user enters "zzz"
  while (true) {
      std::cin >> name; // Read a name from the user
      if (name == "zzz") {
          break;
      }
      names.push_back(name); // Add the name to the vector
  }

  selectionSort(names);

  std::cout << "Sorted names:\n";
  for (const auto& n : names) {
      std::cout << n << std::endl;
  }

  return 0;
}