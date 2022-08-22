#include <iostream>
#include <cmath>

#include "Booking.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "Railways.h"
#include "Gender.h"
#include "BookingCategory.h"
#include "Tatkal.h"
#include "PremiumTatkal.h"
#include "General.h"
#include "SeniorCitizen.h"
#include "Ladies.h"
#include "Blind.h"
#include "TB.h"
#include "Cancer.h"
#include "Handicapped.h"
#include "AC3Tier.h"
#include "Exception.h"
using namespace std;

Booking* Booking::ReserveBooking(Station A , Station B , Date d1 , Date d2 , const BookingClasses& bookingclass , const BookingCategory& bookingcategory, Passenger psngr , bool bookingStatus, string bookingmsg) {
    int flag = 0;
    int tempflag = 0;
    for(auto x : Railways :: sStations){
        if(x.GetName() == A.GetName()){
            tempflag = 1;
            break;
        }
    }
    if(!tempflag){
        flag = 1;
    }
    tempflag = 0;
    for(auto x : Railways :: sStations){
        if(x.GetName() == B.GetName()){
            tempflag = 1;
            break;
        }
    }
    if(!tempflag){
        flag = 1;
    }
    tempflag = 1;
    for(auto x : Railways::sDistStations){
        if(x.first.first.GetName() == A.GetName() && x.first.second.GetName() == B.GetName() || x.first.first.GetName() == B.GetName() && x.first.second.GetName() == A.GetName()){
            tempflag = 0;
            break;
        }
    }
    if(tempflag){
        flag = 1;
    }
    if(d2 > d1){
        flag = 1;
    }
    if(d1.GetYear() - d2.GetYear() > 1){
        flag = 1;
    }
    try{
        if(flag){
            BadBooking ex;
            throw ex;
        }
        else{
            return bookingcategory.CreateBooking(A , B , d1 , d2 , psngr ,  bookingclass);
        }
    }
    catch(BadBooking &ex){
        throw;
    }    
    return bookingcategory.CreateBooking(A , B , d1 , d2 , psngr ,  bookingclass);
}

Booking::Booking(Station A , Station B , Date d1 , Date d2, const BookingClasses& bookingclass, Passenger psngr, bool bookingStatus , string bookingmsg ) : fromStation_(A) , toStation_(B) , dateOfBooking_(d1) , dateOfReservation_(d2) , bookingClass(bookingclass) , passenger_(psngr){
    bookingStatus_ = bookingStatus;
    bookingMessage_ = bookingmsg;
    PNR_ = ++Booking::sBookingPNRSerial;
    Booking::sBookings.push_back(this);
}

Booking::~Booking() {
    Booking::sBookings.pop_back();     // remove the booking from the vector
    Booking::sBookingPNRSerial = static_cast<int>(Booking::sBookings.size());    // make the pnr correct
}

ostream& operator<<(ostream& os , const Booking& b) {
    os << "\n" << b.bookingMessage_ << ":\n";
    os << "PNR Number = " << b.PNR_ << endl;
    os << "From Station = " << b.fromStation_.GetName() << endl;
    os << "To Station = " << b.toStation_.GetName() << endl;
    os << "Travel Date = ";
    (b.dateOfBooking_).print();
    os << "\n";
    os << "Travel Class = " << b.bookingClass.GetName() << endl;
    if(b.bookingClass.IsSitting()) {
        os << " : Mode: Sitting\n";
    }
    else {
        os << " : Mode: Sleeping\n";
    }
    if(b.bookingClass.IsAC()) {
        os << " : Comfort: AC\n";
    }
    else {
        os << " : Comfort: Non-AC\n";
    }
    os << " : Bunks: " << b.bookingClass.GetNumberOfTiers() << endl;
    if(b.bookingClass.IsLuxury()) {
        os << " : Luxury: Yes\n";
    }
    else {
        os << " : Luxury: No\n";
    }
    os << "Fare = " << (int)(b.ComputeFare()) << endl;
    return os;
}

float Booking::sBaseFarePerKM = 0.5;
int Booking::sBookingPNRSerial = 0;
float Booking::sACSurcharge = 50.0;
float Booking::sLuxuryTaxPercent = 25.0;
vector<Booking*> Booking::sBookings;

void Booking::UnitTestBooking() {
    cout<<"     Unit Test for Booking Class"<<endl;

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"CORRECT BOOKING CONSTRUCTION : PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"CORRECT BOOKING CONSTRUCTION : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"INCORRECT BOOKING DUE TO FROM STATION CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"INCORRECT BOOKING DUE TO FROM STATION CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"INCORRECT BOOKING DUE TO END STATION CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadStation &ex){
        cout<<"INCORRECT BOOKING DUE TO END STATION CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
    for(auto p : Railways::sDistStations) {
        if((p.first.first.GetName() == "Delhi" && p.first.second.GetName() == "Mumbai") || (p.first.first.GetName() == "Mumbai" && p.first.second.GetName() == "Delhi")) {        // compares the stations and if they are found same 
            if(p.second == 0){
                cout<<"INCORRECT BOOKING DUE DISTANCE BETWEEN STATION CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
            }
            else{
                cout<<"INCORRECT BOOKING DUE DISTANCE BETWEEN STATION CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
            }                                  
        }
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,02,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,3000)));
        cout<<"INCORRECT BOOKING DUE TO PASSENGER DOB CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadDate &ex){
        cout<<"INCORRECT BOOKING DUE TO PASSENGER DOB CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,02,2020) , Date::Construct(17 , 3 , 2002) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2005)));
        cout<<"INCORRECT BOOKING DUE TO DOR(RESERVATION) < DOB(BIRTH) CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"INCORRECT BOOKING DUE TO DOR(RESERVATION) < DOB(BIRTH) CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2020) , Date::Construct(17 , 3 , 2021) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123456789111" , Date::Construct(17,12,2001)));
        cout<<"INCORRECT BOOKING DUE TO DOR(RESERVATION) > DOB(BOOKING) CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadBooking &ex){
        cout<<"INCORRECT BOOKING DUE TO DOR(RESERVATION) > DOB(BOOKING) CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    try{
        Booking *b1 = Booking::ReserveBooking(Station::Construct("Delhi") , Station::Construct("Mumbai") , Date::Construct(12,5,2021) , Date::Construct(17 , 3 , 2020) , AC3Tier::Type() , General::Type() , Passenger::Construct("Shreyansh" , Male::Type() , "123459111" , Date::Construct(17,12,2001)));
        cout<<"INCORRECT BOOKING DUE TO INCORRECT PASSENGER CONSTRUCTION (NEGATIVE TEST) : PASSED"<<endl;
    }
    catch(BadPassenger &ex){
        cout<<"INCORRECT BOOKING DUE TO INCORRECT PASSENGER CONSTRUCTION (NEGATIVE TEST) : FAILED"<<endl;
    }

    cout<<endl;
}