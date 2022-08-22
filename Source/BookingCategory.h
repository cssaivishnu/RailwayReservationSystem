#ifndef BOOKING_CATEGORY_H
#define BOOKING_CATEGORY_H

#include <iostream>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"
using namespace std;

class Booking;

class BookingCategory {
protected:
    BookingCategory(string name) : name(name) {}
    string name;
public:
    const string GetName() const {return name;}
    virtual Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger , const BookingClasses& bookingclass) const = 0;
};

#endif  // BOOKING_CATEGORY_H