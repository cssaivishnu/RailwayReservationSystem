#ifndef BLIND_H
#define BLIND_H

#include <iostream>
#include <vector>

#include "Divyang.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class Blind : public Divyang {
    Blind() : Divyang("Blind") {};
public:
    
    static const Blind& Type() {
        static const Blind theobj;
        return theobj;
    };
    static vector<pair<string , float>> sConcessions;
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // Blind_H