#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date {
    enum Month {Jan = 1 , Feb = 2 , Mar = 3 , Apr = 4 , May = 5 , Jun = 6 , Jul = 7 , Aug = 8 , Sep = 9 , Oct = 10 ,Nov = 11 , Dec = 12};
    enum Day {Monday = 1  ,Tuesday = 2 , Wednesday = 3 , Thursday = 4 , Friday = 5 , Saturday = 6 , Sunday = 7};
    unsigned int date_;
    Month month_;
    unsigned int year_;
public:
    Date(unsigned int d , unsigned int m , unsigned int y);
    Date(const Date& d);        //copy constructor
    Date& operator=(const Date& d);       // copy assignment operator
    void print() const;     // made const since a const date object may invoke it
    int GetYear() const;    
    bool IsValidDate(); 
    bool operator !=(const Date& d);
    bool operator >(const Date& d);
    ~Date();
    static string monthNames[12]; // stores the month names
    static string dayNames[7];     // stores the day names
    static void UnitTestDate();
    friend ostream& operator<<(ostream& os, const Date& d);
    static Date Construct(unsigned int d, unsigned int m, unsigned int y);
};

#endif // DATE_H