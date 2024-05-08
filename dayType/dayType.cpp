#include <iostream>
#include <string>

using namespace std;

class dayType {
private:
    string day;
    string days_of_week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int current_index;
public:
    dayType(string initialDay) {
        day = initialDay;
    }

    void prevDay() {
        addDay(-1);
    }

    void nextDay() {
        addDay(1);
    }

    void addDay(int num_days) {
        for (int i = 0; i < 7; ++i) {
            if (days_of_week[i] == day) {
                current_index = i;
                break;
            }
        }
        day = days_of_week[(current_index + num_days) % 7];
    }

    void print() {
        cout << "Current day is: " << day << endl;
    }
};




