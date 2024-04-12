#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

double average(int v[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += v[i];
  }
  return (double) sum / size;
}

int main() {
  srand(time(NULL));
  int arr[20];
  int evenSum = 0;
  int oddFour = 0;

  cout << "Array: ";
  for (int i = 0; i < 20; i++) {
    arr[i] = rand() % 100 + 1;
    cout << arr[i] << " ";
    if (i % 2 == 0) {
      evenSum += arr[i];
    }
    if (i % 4 == 1) {
      oddFour += arr[i];
    }
  }

  cout << endl;
  cout << "sum of the even index values: " << evenSum << endl;
  cout << "sum of every other odd index value: " << oddFour << endl;
  cout << "average: " << average(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}
