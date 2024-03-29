#include <iostream>
#include <iomanip>
using namespace std;

double taxAmount(double pensionRate, string maritalStatus, double grossPay, int numKidsUnder14) {
    double taxableIncome = grossPay * ( 1 - pensionRate / 100);
    double tax = 0;

    if (maritalStatus == "m") {
        taxableIncome -= (7000 + (2 + numKidsUnder14) * 1500);
    } else {
        taxableIncome -= (4000 + 1500);
    }

    if (taxableIncome >= 0 && taxableIncome <= 15000) {
        tax = taxableIncome * 0.15;
    } else if (taxableIncome >= 15001 && taxableIncome <= 40000) {
        tax = 2250 + (taxableIncome - 15000) * 0.25;
    } else {
        tax = 8460 + (taxableIncome - 40000) * 0.35;
    }

    return tax;
}

void getData(string whatData) {
    cout << whatData << endl;
}

int main() {

    cout << fixed;
    cout << setprecision(2);
    string marital_status = "";
    int kids_under_14 = 0;
    double gross_pay = 0;
    double pension_plan = 0;

    getData("What's your marital status? If married, enter 'm', else 'no'");
    cin >> marital_status;

    if (marital_status == "m") {
        getData("How many kids do you have that under the age of 14?");
        cin >> kids_under_14;
    }

    getData("How much did you get paid?");
    cin >> gross_pay;

    getData("What percentage of your gross income did you put into your pension plan?");
    cin >> pension_plan;

    cout << taxAmount(pension_plan, marital_status, gross_pay, kids_under_14) << endl;
    return 0;
}