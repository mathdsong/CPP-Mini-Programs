// adding a function to sort students’ names so that students’ data is output into ascending order according to their name.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void getData(fstream& inf, string n[], double tstData[][6], int count);
void calculateAverage(double tstData[][6], int count);
void calculateGrade(double tstData[][6], char gr[], int count);
void output(string fileName, string n[], double tstData[][6], char gr[], int count);

int main() {
	string names[10];
  double testData[10][6];
  char grade[10];

  fstream inFile;

  inFile.open("data.txt");

  if (!inFile) {
    cout << "Cannot open the input file: data.txt." << endl;
    cout << "Program terminates!" << endl;
    return 1;
  }

  getData(inFile, names, testData, 10);
  calculateAverage(testData, 10);
  calculateGrade(testData, grade, 10);
  inFile.close();
  output("output.txt", names, testData, grade, 10);
	return 0;
}

vector<string> sortStudentNames(string n[], int count) {
  // copy the array into a vector:
  vector<string> sortedNames(n, n + count);
  for (int i = 0; i < count; i++) {
      for (int j = i + 1; j < count; j++) {
          if (sortedNames[j] < sortedNames[i]) {
              swap(sortedNames[i], sortedNames[j]);
          }
      }
  }
  return sortedNames;
}

void getData(fstream& inf, string n[], double tstData[][6], int count) {
  string temp[count];
  double tempData[count][6];
  for (int i = 0; i < count; i++)
  {
      inf >> temp[i];

      for (int j = 0; j < 5; j++)
          inf >> tempData[i][j];

      tempData[i][5] = 0.0;
  }
  // perform reorder:
  vector<string> sortedNames = sortStudentNames(temp, count);
  for (int k = 0; k < count; k++) {
      for (int p = 0; p < count; p++) {
          if (temp[p] == sortedNames[k]) {
              n[k] = temp[p];
              for (int l = 0; l < 5; l++) {
                  tstData[k][l] = tempData[p][l];
              }
          }
      }
  }
}

void calculateAverage(double tstData[][6], int count) {
  double sum;
  for (int i = 0; i < count; i++) {
    sum = 0.0;
    for (int j = 0; j < 5; j++)
        sum = sum + tstData[i][j];
    tstData[i][5] = sum / 5;
  }
}

void calculateGrade(double tstData[][6], char gr[], int count) {
  for (int i = 0; i < count; i++)
    if (tstData[i][5] >= 90)
      gr[i] = 'A';
    else if (tstData[i][5] >= 80)
      gr[i] = 'B';
    else if (tstData[i][5] >= 70)
      gr[i] = 'C';
    else if (tstData[i][5] >= 60)
      gr[i] = 'D';
    else
      gr[i] = 'F';
}

// output the results
void output(string fileName, string n[], double tstData[][6], char gr[], int count) {
  ofstream outData;
  outData.open(fileName);
  outData << fixed << showpoint << setprecision(2);
  double sum = 0.0;
  outData << left << setw(10) << "Name"
      << right << setw(8) << "Test 1"
      << setw(8) << "Test 2"
      << setw(8) << "Test 3"
      << setw(8) << "Test 4"
      << setw(8) << "Test 5"
      << setw(10) << "Average"
      << setw(8) << "Grade" << endl;

  for (int i = 0; i < count; i++) {
    outData << left << setw(10) << n[i];
    outData << right;

    for (int j = 0; j < 5; j++)
        outData << setw(8) << tstData[i][j];

    outData << setw(10) << tstData[i][5]
          << setw(6) << gr[i] << endl;
    sum = sum + tstData[i][5];
  }

  outData << endl << endl;
  outData << "Class average: " << sum / count << endl;
}