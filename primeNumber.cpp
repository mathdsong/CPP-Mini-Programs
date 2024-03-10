/*
Write a program that prompts the user to input a positive integer.
It should then output a message indicating whether the number is a prime number.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;
    cout << "Type a positive integer: " << endl;
    cin >> num;

    if (num % 2 == 0) {
        if (num == 2) {
            cout << "It's prime" << endl;
        } else {
            cout << "It's not prime" << endl;
        }
        return 0;
    } else {
        double squareRoot = sqrt(num);
        int i = 2;
        while (i <= squareRoot) {
            if (num % i == 0) {
                cout << "It's not prime" << endl;
                break;
            }
            i++;
        }
        cout << "It's prime" << endl;
    }
    return 0;
}