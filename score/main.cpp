/*
Write a program that reads a file consisting of students’ test scores in the range 0–200.
It should then determine the number of students having scores in each of the following ranges:
0–24, 25–49, 50–74, 75–99, 100–124, 125–149, 150–174, and 175–200.
Output the score ranges and the number of students.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    map<int, int> score_map;
    ifstream inData;
    ofstream outData;
    string fileName;

    cout << "Enter the file name" << endl;
    cin >> fileName;
    inData.open(fileName);
    // read txt file that consists of scores and do classification:
    if (inData.is_open()) {
        string line;
        // read line by line:
        while (getline(inData, line)) {
            // process each line:
            stringstream ss(line);
            vector<int> numbers;
            int number;
            // extract each integer from ss stringstream using extraction operator >> and store it in numbers
            while (ss >> number) {
                numbers.push_back(number);
            }
            // process each number here:
            for (int num: numbers) {
                // classify each integer by the quotient after diving by 25
                int quotient = num / 25;
                if (quotient == 8) {
                    score_map[quotient - 1] += 1;
                } else {
                    score_map[quotient] += 1;
                }
            }
        }
        inData.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
    outData.open("output.dat");
    for (const auto& x : score_map) {
        int left = x.first * 25;
        int right = left + 24;
        int count = x.second;
        if (x.first == 7) {
          outData << to_string(left) << "-" << to_string(right + 1) << ": " << to_string(count) << endl;
        } else {
          outData << to_string(left) << "-" << to_string(right) << ": " << to_string(count) << endl;
        }
    }
    outData.close();
    return 0;
}
