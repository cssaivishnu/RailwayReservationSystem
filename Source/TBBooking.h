#ifndef TB_BOOKING_H
#define TB_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "DivyangBooking.h"

class TBBooking : public DivyangBooking {
public:
    TBBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // TB_BOOKING_H