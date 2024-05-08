/*
Design and implement a class dayType that implements the day of the week in a program. The class dayType should store the day,
such as Sun for Sunday. The program should be able to perform the following operations on an object of type dayType:
1. Set the day.
2. Print the day.
3. Return the day.
4. Return the next day.
5. Return the previous day.
6. Calculate and return the day by adding certain days to the current day. For example, if the current day is Monday and we add 4 days,
    the day to be returned is Friday. Similarly, if today is Tuesday and we add 13 days, the day to be returned is Monday.
7. Add the appropriate constructors.

Write the definitions of the functions to implement the operations for the class dayType from above:
a. prevDay
b. nextDay
c. addDay
d. print
*/


int main() {
  dayType day("Saturday");
  day.print();

  day.nextDay();
  day.print();

  day.prevDay();
  day.print();

  day.addDay(6);
  day.print();

  return 0;
}