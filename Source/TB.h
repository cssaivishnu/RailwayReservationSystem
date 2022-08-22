#ifndef TB_H
#define TB_H

#include <iostream>
#include <vector>

#include "Divyang.h"
#include "Booking.h"
#include "Station.h"
#include "Date.h"
using namespace std;

class TB : public Divyang {
    TB() : Divyang("TB") {};
public:    
    static const TB& Type() {
        static const TB theobj;
        return theobj;
    };
    static vector<pair<string , float>> sConcessions;
    Booking* CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const;
};

#endif  // TB_H