/* Write a function, reverseDigit, that takes an integer as a parameter and returns the number with its digits reversed.
For example:
the value of reverseDigit(7800) is 87;
the value of reverseDigit(20090) is 9002;
and the value of reverseDigit(–53796) is –69735. */
#include <iostream>
using namespace std;

int reverseDigit(int num) {
    int reversed = 0;
    int count = 0;
    int abs_num = abs(num);

    while (abs_num > 0) {
        int digit = abs_num % 10;
        count++;
        if (count == 1) {
            reversed += digit;
        } else {
            reversed = 10 * reversed + digit;
        }
        abs_num /= 10;
    }

    if (num < 0) {
        return -1 * reversed;
    } else {
        return reversed;
    }
}

int main() {
    int testSamples[] = {-53796, 7800, 20090};
    for (int i = 0; i < sizeof(testSamples) / sizeof(testSamples[0]); i++) {
        cout << "the value of reverseDigit (" << testSamples[i] << ") is " << reverseDigit(testSamples[i]) << endl;
    }
    return 0;
}