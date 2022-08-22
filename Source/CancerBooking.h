#ifndef Cancer_BOOKING_H
#define Cancer_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "DivyangBooking.h"

class CancerBooking : public DivyangBooking {
public:
    CancerBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;

};

#endif // Cancer_BOOKING_H