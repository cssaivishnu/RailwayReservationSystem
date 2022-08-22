#ifndef LADIES_H
#define LADIES_H

#include <iostream>

#include "Concession.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class Ladies : public Concession {
    Ladies() : Concession("Ladies") {};
public:
    
    static const Ladies& Type() {
        static const Ladies theobj;
        return theobj;
    };
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // Ladies_H