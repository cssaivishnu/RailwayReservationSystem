#ifndef Handicapped_BOOKING_H
#define Handicapped_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "DivyangBooking.h"

class HandicappedBooking : public DivyangBooking {
public:
    HandicappedBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // Handicapped_BOOKING_H