#include <iostream>
using namespace std;

bool isLeapYear(int y){
    if (y % 400 == 0) return true; else
    if (y % 100 == 0) return false; else
    if (y % 4 == 0) return true; else
    return false;
}

int daysInMonth(int month, int year){
    int days[] = {31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};
    if(month == 2 && isLeapYear(year)) return 29;
    else return days[month-1];
}
void calculateDate(int totaldays){
    int month = 1, day = 1, year = 1;
    while(totaldays > 365){
        int days_in_current_year = (isLeapYear(year) ? 366 : 365);
        if(totaldays > days_in_current_year) {
            totaldays -= days_in_current_year;
            year++;
        } else {
            break;
        }
    }
    while(totaldays > daysInMonth(month, year)){
        totaldays -= daysInMonth(month, year);
        month++;
    }
    day = totaldays;
    cout << "Date: " << year << "/" << month << "/" << day << '\n';
    cout << "Leap Year: " << (isLeapYear(year) ? "Yes" : "No") << '\n';
}
int main(){

    int totaldays;
    cin >> totaldays;

    if(totaldays < 0) {
        cout << "invalid input. input cannot be negative.";
        return -1;
    }
    else {
        calculateDate(totaldays);
    }

    return 0;
}
