/*
Write a version of the binary search algorithm that can be used to search a string vector object.
Also, write a program to test your algorithm. (Use the selection sort algorithm to sort the vector.) Your program should prompt the user to input a series of strings, ending the input stream with zzz. The program should then prompt the user to search for a specific string in the list.
If the string is found in the list:
x is found in the list
else:
x is not in the list
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> selectionSort(std::vector<std::string>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < n; ++j) {
          if (vec[j] < vec[minIndex]) {
              std::swap(vec[j], vec[minIndex]);
          }
      }
  }
  return vec;
}

void binarySearch(const std::vector<std::string>& vec) {
    int left = 0;
    int right = vec.size() - 1;
    std::string target;
    std::cout << "Search for a specific string" << std::endl;
    std::cin >> target;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (vec[mid] == target) {
            std::cout << target << " is found in the list" << std::endl;
            return;
        } else if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << target << " is not in the list" << std::endl;
}

int main() {
    std::vector<std::string> strs;
    std::string str;
    std::cout << "Enter a series of strings and type 'zzz' to end" << std::endl;
    while (true) {
        std::cin >> str;
        if (str == "zzz") break;
        strs.push_back(str);
    }
    binarySearch(selectionSort(strs));
    return 0;
}