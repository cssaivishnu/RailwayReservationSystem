#ifndef Handicapped_H
#define Handicapped_H

#include <iostream>
#include <vector>

#include "Divyang.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class Handicapped : public Divyang {
    Handicapped() : Divyang("Handicapped") {};
public:    
    static const Handicapped& Type() {
        static const Handicapped theobj;
        return theobj;
    };
    static vector<pair<string , float>> sConcessions;
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // Handicapped_H