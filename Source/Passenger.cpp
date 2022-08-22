#include <iostream>
#include <string>
#include <algorithm>

#include "Passenger.h"
#include "Date.h"
#include "Gender.h"
#include "Exception.h"

Passenger::Passenger(const string firstname ,const Gender& gender, const string aadhar , Date dob  ,  string middlename  , string lastname  ,string mobileNumber  , string disabilitytype , string disabilityid) : firstName_(firstname) , middleName_(middlename) , lastName_(lastname) , aadhar_(aadhar) , dateOfBirth_(dob) , gender_(gender){
    mobileNumber_ = mobileNumber;
    disabilityType_ = disabilitytype;
    disabilityId_ = disabilityid;
}

//
Passenger::Passenger(const Passenger& p) : firstName_(p.firstName_) , middleName_(p.middleName_) , lastName_(p.lastName_) , aadhar_(p.aadhar_) , dateOfBirth_(p.dateOfBirth_) , gender_(p.gender_) {
    mobileNumber_ = p.mobileNumber_;
    disabilityType_ = p.disabilityType_;
    disabilityId_ = p.disabilityId_;
    // cerr<<p.dateOfBirth_<<" "<<dateOfBirth_<<" from ctor"<<endl;
}




Passenger::~Passenger() {}

int Passenger::GetAge(const Date& d) const {
    // cout<<"*(thois) "<<(*this).dateOfBirth_<<endl;
    // cout<<d.GetYear()<<" "<<(*this).dateOfBirth_.GetYear()<<" from pass"<<endl;
    return d.GetYear()-(*this).dateOfBirth_.GetYear();
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

Passenger Passenger :: Construct(const string firstname ,const Gender& gender,const string aadhar , Date dob  ,  string middlename, string lastname, string mobileNumber, string disabilitytype, string disabilityid){
    int flag = 0;
    // cout<<dob<<" dob"<<endl;
    if(!dob.IsValidDate()){
        flag = 1;
    }
    // cout<<"flag 1 "<<flag<<endl;
    if(!is_digits(aadhar) || (aadhar.size() != 12)){
        flag = 1;
    }
    // cout<<"flag 2 "<<flag<<endl;
    if((mobileNumber.size() != 10 && mobileNumber.size() != 0) || !is_digits(mobileNumber)){
        flag = 1;
    }
    // cout<<"flag 3 "<<flag<<endl;
    if((firstname == "" && lastname == "")){
        flag = 1;
    }
    // date of birth and date of reservation
    // cout<<"flag 4 "<<flag<<endl;
    try{
        if(flag){
            BadPassenger ex;
            throw ex;
        }
        else{
            Passenger *p = new Passenger( firstname , gender, aadhar , dob,  middlename, lastname, mobileNumber, disabilitytype, disabilityid);
            // cerr<<p->GetDob()<<" from return"<<endl;
            return *p;
        }
    }
    catch(BadPassenger &ex){
        throw;
    }
}

void Passenger :: UnitTestPassenger(){
    cout<<"     Unit Test for Passenger Class"<<endl;
    try{
        Passenger p1 = Passenger :: Construct("CRM" , Female::Type() , "123456789111" , Date::Construct(17,12,1901));
        cout<<"CORRECT PASSENGER CONSTRUCTION : PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"CORRECT PASSENGER CONSTRUCTION : FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("CRM" , Female::Type() , "123456789111" , Date::Construct(17,12,3000));
        cout<<"INCORRECT PASSENGER DUE TO DOB CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"INCORRECT PASSENGER DUE TO DOB CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("CRM" , Female::Type() , "12345678911" , Date::Construct(17,12,2002));
        cout<<"INCORRECT PASSENGER DUE TO AADHAR LENGHT CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT PASSENGER DUE TO AADHAR LENGHT CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger :: Construct("CRM" , Female::Type() , "1234a6728911" , Date::Construct(17,12,2002));
        cout<<"INCORRECT PASSENGER DUE TO AADHAR DIGITS CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT PASSENGER DUE TO AADHAR DIGITS CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("CRM" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "78a7658902" ,"Blind");
        cout<<"INCORRECT PASSENGER DUE TO MOBILE DIGITS CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT PASSENGER DUE TO MOBILE DIGITS CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("CRM" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "Singh" , "787658902" ,"Blind");
        cout<<"INCORRECT PASSENGER DUE TO MOBILE LENGHT CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT PASSENGER DUE TO MOBILE LENGTH CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    try{
        Passenger p1 = Passenger::Construct("" , Male::Type() , "123456789111" , Date::Construct(17,12,1901) , "" , "" , "787658902" ,"Blind");
        cout<<"INCORRECT PASSENGER DUE TO FIRST AND LAST NAME CONSTRUCTION (NEGATIVE TEST): PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT PASSENGER DUE TO FIRST AND LAST NAME CONSTRUCTION (NEGATIVE TEST): FAILED" <<endl;
    }

    cout<<endl;
}