/*
Write a program to calculate students’ average test scores and their grades.
Use three arrays: a one-dimensional array to store the students’ names,
                  a (parallel) two-dimensional array to store the test scores,
                  and a parallel one-dimensional array to store grades.
Your program must contain at least the following functions:
a function to read and store data into two arrays
a function to calculate the average test score and grade
a function to output the results.
Have your program also output the class average. Use the following scale to determine the letter grade:
**90%–100%, A; 80%–89.99%, B; 70%–79.99%, C; 60%–69.99%, D; and 0%–59.99%, F **.
Format your output with setprecision(2) to ensure the proper number of decimals for testing!
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// calculate the average test score
double calculator(double scores[], int size) {
  double avg = 0;
  string grade;
  for (int i = 0; i < size; i++) {
      avg += scores[i];
  }
  avg /= size;
  return avg;
}

// read and store data into 3 arrays
double readAndStore(string fileName, string names[], double scores[][5], string grades[], int size, double avg[]) {
  ifstream inData;
  inData.open(fileName);
  int row = 0;
  string grade;
  if (inData.is_open()) {
      string line;
      while (inData && row < size) {
        inData >> names[row];
        for (int col = 0; col < 5; col++) {
            inData >> scores[row][col];
        }
        avg[row] = calculator(scores[row], 5);
        if (avg[row] >= 90) {
          grade = 'A';
        } else if (avg[row] >= 80) {
          grade = 'B';
        } else if (avg[row] >= 70) {
          grade = 'C';
        } else if (avg[row] >= 60) {
          grade = 'D';
        } else {
          grade = 'F';
        }
        grades[row] = grade;
        row++;
      }
      return calculator(avg, 10);
  } else {
      cerr << "Error opening the input file!" << endl;
      return -1;
  }
}

// output the results
void output(string fileName, int size, string arr[], double avg, double arr2[][5], string arr3[]) {
  ofstream outData;
  outData.open(fileName);
  outData << fixed << showpoint << setprecision(2);
  outData << left << setw(15) << "Name" << setw(15) << "Score-1" << setw(15)
          << "Score-2" << setw(15) << "Score-3" << setw(15)
          << "Score-4" << setw(15) << "Score-5" << setw(15) << "grade" << endl;
  if (outData.is_open()) {
    for (int j = 0; j < size; j++) {
      outData << setw(15) << arr[j];
      for (int count = 0; count < 5; count++) {
        outData << setw(15) << arr2[j][count];
      }
      outData << setw(15) << arr3[j] << endl;
    }

    outData << "\nClass Average: " << avg << endl;
  } else {
    cerr << "Error opening the output file!" << endl;
  }
}

int main() {
  cout << fixed << showpoint << setprecision(2);
  string names[10];
  double scores[10][5];
  string grades[10];
  double avg_arr[10];
  double avg = readAndStore("data.txt", names, scores, grades, 10, avg_arr);
  output("output.txt", 10, names, avg, scores, grades);
  return 0;
}