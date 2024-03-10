/*
Write a program that accepts as input the base price and the finished area in square feet of the three models.
*/

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    // Write your main here
    string houseType[3] = {"colonial", "split-entry", "single-story"};
    double price_per_square[3] = {};
    double min_value = numeric_limits<double>::max();
    vector<string> min_type;
    double price;
    double area;

    for (int i = 0; i < sizeof(houseType) / sizeof(*houseType); i++) {
        cout << "Enter the price of " << houseType[i] << ": " << endl;
        cin >> price;
        cout << "Enter the finished area of " << houseType[i] << ": " << endl;
        cin >> area;

        price_per_square[i] = price / area;
        cout << price_per_square[i] << endl;
        if (min_value > price_per_square[i]) {
            min_value = price_per_square[i];
        }
        cout << min_value << endl;
    }

    int i = 0;
    while (i < sizeof(price_per_square) / sizeof(*price_per_square)) {
        if (price_per_square[i] == min_value) {
            min_type.push_back(houseType[i]);
        }
        i++;
    }

    if (min_type.size() == 1) {
        cout << "The price per square foot of the " << min_type[0] << " model is the least." << endl;
    } else if (min_type.size() == 2) {
        string both = "";
        for (int j = 0; j < min_type.size(); j++) {
            both += min_type[j] + " and ";
        }

        if (both == "split-entry and single-story and ") {
            both = "single-story and split-entry and ";
        }
        cout << "The price per square foot of the " << both.substr(0, both.size() - 5) << " models tie for the least." << endl;
    } else {
        cout << "The price per square foot all three models are the same";
    }

    return 0;
}