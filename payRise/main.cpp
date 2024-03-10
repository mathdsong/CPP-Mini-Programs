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
    outData.open("/payRise/output.dat");

    // string line;
    // while (getline(inData, line)) {
    //     // cout << line << endl;
    //     inData >> lastName >> firstName >> salary >> rate;
    //     cout << lastName << firstName << salary << rate << endl;
    // }

    outData << fixed << showpoint << setprecision(2);

    // for (string l; getline(inData, l);) {
    //     // cout << l << endl;
    //     inData >> lastName >> firstName >> salary >> rate;
    //     cout << lastName << firstName << salary << rate << endl;
    // }

    while (inData >> lastName >> firstName >> salary >> rate) {
        // cout << lastName << firstName << salary << rate << endl;
        updatedSalary = salary * (1 + rate / 100);
        outData << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    // Close files
    inData.close();
    outData.close();
    return 0;
}

// ref link: https://stackoverflow.com/questions/29097127/c-reading-file-line-by-line