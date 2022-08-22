#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>

#include "BookingCategory.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class General : public BookingCategory {
    General() : BookingCategory("General") {};
public:
    
    static const General& Type() {
        static const General theobj;
        return theobj;
    };
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // General_H