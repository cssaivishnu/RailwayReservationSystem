#ifndef LADIES_BOOKING_H
#define LADIES_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "ConcessionBooking.h"

class LadiesBooking : public ConcessionBooking {
public:
    LadiesBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // Ladies_BOOKING_H