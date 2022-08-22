#ifndef GENERAL_BOOKING_H
#define GENERAL_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"

class GeneralBooking : public Booking {
public:
    GeneralBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // General_BOOKING_H