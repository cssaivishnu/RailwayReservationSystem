#ifndef SENIORCITIZEN_H
#define SENIORCITIZEN_H

#include <iostream>

#include "Concession.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class SeniorCitizen : public Concession {
    SeniorCitizen() : Concession("SeniorCitizen") {};
public:    
    static const SeniorCitizen& Type() {
        static const SeniorCitizen theobj;
        return theobj;
    };
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // SeniorCitizen_H