#ifndef Cancer_H
#define Cancer_H

#include <iostream>
#include <vector>

#include "Divyang.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class Cancer : public Divyang {
    Cancer() : Divyang("Cancer") {};
public:
    
    static const Cancer& Type() {
        static const Cancer theobj;
        return theobj;
    };
    static vector<pair<string , float>> sConcessions;
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // Cancer_H