#ifndef TATKAL_H
#define TATKAL_H

#include <iostream>

#include "BookingCategory.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class Tatkal : public BookingCategory {
    Tatkal() : BookingCategory("Tatkal") {};
public:    
    static const Tatkal& Type() {
        static const Tatkal theobj;
        return theobj;
    };
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // TATKAL_H