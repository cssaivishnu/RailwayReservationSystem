#ifndef PREMIUM_TATKAL_H
#define PREMIUM_TATKAL_H

#include <iostream>

#include "BookingCategory.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class PremiumTatkal : public BookingCategory {
    PremiumTatkal() : BookingCategory("Premium Tatkal") {};
public:
    
    static const PremiumTatkal& Type() {
        static const PremiumTatkal theobj;
        return theobj;
    };
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger,const BookingClasses& bookingclass) const;
};

#endif  // TATKAL_H