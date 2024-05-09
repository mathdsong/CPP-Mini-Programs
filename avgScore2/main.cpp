// adding a function to sort students’ names so that students’ data is output into ascending order according to their name.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void getData(ifstream& inf, string n[], double tstData[][6], int count);
void calculateAverage(double tstData[][6], int count);
void calculateGrade(double tstData[][6], char gr[], int count);
void print(string n[], double tstData[][6], char gr[], int count);

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

  cout << fixed << showpoint << setprecision(2);
  getData(inFile, names, testData, 10);
  calculateAverage(testData, 10);
  calculateGrade(testData, grade, 10);
  print(names, testData, grade, 10);
  inFile.close();
	return 0;
}

void getData(ifstream& inf, string n[], double tstData[][6], int count) {
  for (int i = 0; i < count; i++) {
    inf >> n[i];
    for (int j = 0; j < 5; j++)
      inf >> tstData[i][j];
    tstData[i][5] = 0.0;
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

void print(string n[], double tstData[][6], char gr[], int count) {
  double sum = 0.0;
  cout << left << setw(10) << "Name"
      << right << setw(8) << "Test 1"
      << setw(8) << "Test 2"
      << setw(8) << "Test 3"
      << setw(8) << "Test 4"
      << setw(8) << "Test 5"
      << setw(10) << "Average"
      << setw(8) << "Grade" << endl;

  for (int i = 0; i < count; i++) {
    cout << left << setw(10) << n[i];
    cout << right;

    for (int j = 0; j < 5; j++)
        cout << setw(8) << tstData[i][j];

    cout << setw(10) << tstData[i][5]
          << setw(6) << gr[i] << endl;
    sum = sum + tstData[i][5];
  }

  cout << endl << endl;
  cout << "Class average: " << sum / count << endl;
}