/*
1. in data.txt, Each input line consists of an employee’s last name, first name, current salary, and percent pay increase.
2. Write a program that reads data from a file specified by the user at runtime (i.e. your program should accept the filename as user input)
   and stores the output in the file output.dat. To test your program, use the data.txt file.
3. For each employee, the data must be output in the following form: firstName lastName updatedSalary. Format the output of decimal numbers to two decimal places.
4. Since your program handles currency, make sure to use a data type that can store decimals.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    ifstream inData;
    ofstream outData;

    string lastName;
    string firstName;
    double salary;
    double rate;
    double updatedSalary;

    string fileName;
    cout << "Enter the file name" << endl;
    cin >> fileName;
    inData.open(fileName);
    outData.open("output.dat");

    outData << fixed << showpoint << setprecision(2);

    while (inData >> lastName >> firstName >> salary >> rate) {
        updatedSalary = salary * (1 + rate / 100);
        outData << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    // Close files
    inData.close();
    outData.close();
    return 0;
}

// ref link: https://stackoverflow.com/questions/29097127/c-reading-file-line-by-line