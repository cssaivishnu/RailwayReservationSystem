#ifndef DivyangBOOKING_H
#define DivyangBOOKING_H

#include <iostream>

#include "concessionBooking.h"
using namespace std;

class DivyangBooking : public ConcessionBooking {
protected:
    DivyangBooking(Station A , Station B , Date& d1 , Date& d2  ,const BookingClasses& bookingclass, Passenger& passenger) : ConcessionBooking(A , B , d1 , d2 , bookingclass, passenger) {}
};

#endif // DivyangBOOKING_H