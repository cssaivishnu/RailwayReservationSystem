#include<iostream>

#include "Date.h"
#include "Exception.h"
using namespace std;

string Date::monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun" , "Jul", "Aug", "Sep" , "Oct", "Nov" , "Dec"};
string Date::dayNames[7] = {"Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"};

Date::Date(unsigned int d , unsigned int m , unsigned int y) : date_(d) , month_(Month(m)) , year_(y) {}

Date::Date(const Date& d) : date_(d.date_) , month_(d.month_) , year_(d.year_) {}

Date& Date::operator=(const Date& d) {
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
    return *this;
}

void Date::print() const {
    cout << date_ << "/" << Date::monthNames[month_-1] << "/" << year_;
}

int Date::GetYear() const { //
    return (*this).year_;
}

bool checkLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;
 
    if (year % 4 == 0)
        return true;
    return false;
}

bool Date :: IsValidDate(){
    int flag = 0;
    int d = (*this).date_;
    int m = (*this).month_;
    int y = (*this).year_;
    if(!((d >= 1 && d <= 31) && (m >= 1 && m <= 12) && (y >= 1900 && y <= 2099))){
        flag = 1;
    }
    if((m == 4 || m == 9 || m == 6 || m == 11 || m == 2) && d == 31){
        flag = 1;
    }
    if(!checkLeapYear(y) && m == 2 && d > 28){
        flag = 1;
    }
    if(flag)
        return false;
    else
        return true;
}

Date::~Date() {}

void Date::UnitTestDate() {
    cout<<"     Unit Test for Date Class:"<<endl;

    try{
        Date d1 = Date::Construct(26,12,2001);
        cout<<"Date(26,12,2001) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(26,12,2001) : FAILED"<<endl;
    }
    // WRONG DATES      
    try{
        Date d1 = Date::Construct(18,13,2000);
        cout<<"Date(18,13,2000) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(18,13,2000) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(18,13,1800);
        cout<<"Date(18,13,1800) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(18,13,1800) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(18,13,3000);
        cout<<"Date(18,13,3000) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(18,13,3000) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(31,03,2000);
        cout<<"Date(31,03,2000) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(31,03,2000) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(32,03,2000);
        cout<<"Date(32,03,2000) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(32,03,2000) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(31,04,2000);
        cout<<"Date(31,04,2000) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(31,04,2000) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(29,02,2020);
        cout<<"Date(29,02,2020) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(29,02,2020) : FAILED"<<endl;
    }

    try{
        Date d1 = Date::Construct(29,02,2019);
        cout<<"Date(29,02,2019) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"Date(29,02,2019) : FAILED"<<endl;
    }

    cout<<endl;
}

ostream& operator<<(ostream& os, const Date& d){
    os<<"Date : "<<d.date_<<"/"<<d.month_<<"/"<<d.year_;
    return os;
}

bool Date::operator!=(const Date& d) {
    if(date_ == d.date_ && month_ == d.month_ && year_ == d.year_) {
        return 0;
    }
    return 1;
}

bool Date::operator >(const Date& d){
    if(year_ > d.year_) {
        return 1;
    }
    else if(year_ == d.year_ && month_ > d.month_){
        return 1;
    }
    else if(year_ == d.year_ && month_ == d.month_ && date_ > d.date_){
        return 1;
    }
    return 0;
}

Date Date :: Construct(unsigned int d, unsigned int m, unsigned int y){
    int flag = 0;
    
    if(!((d >= 1 && d <= 31) && ((Month)m >= 1 && (Month)m <= 12) && (y >= 1900 && y <= 2099))){
        flag = 1;
    }
    if(((Month)m == 4 || (Month)m == 9 || (Month)m == 6 || (Month)m == 11 || (Month)m == 2) && d == 31){
        flag = 1;
    }
    if(!checkLeapYear(y) && (Month)m == 2 && d > 28){
        flag = 1;
    }

    try{
        if(flag){
            BadDate ex;
            throw ex;
        }
        else{
            Date d1(d,m,y);
            return d1;
        }
    }
    catch(BadDate &ex){
        throw;
    }
}
