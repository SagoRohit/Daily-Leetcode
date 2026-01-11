#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> daysinmonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int daysofyear=4;
        if(leapyear(year))
        {
            daysinmonth[2]= 29;
        }
        for(int i= 1971; i<year; i++)
        {
            if(leapyear(i))
                daysofyear+= 366;
            else
                daysofyear+=365;
        }
        for(int i=1; i<month; i++)
        {
            daysofyear+= daysinmonth[i];
        }
        daysofyear+= day;
        return days[daysofyear%7];
    }
    bool leapyear(int year){
        if(year%400==0 || (year%100!=0 && year%4==0))
            return true;
        return false;
    }
};