#ifndef TATKAL_BOOKING_H
#define TATKAL_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"

class TatkalBooking : public Booking {
public:
    TatkalBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // TATKAL_BOOKING_H