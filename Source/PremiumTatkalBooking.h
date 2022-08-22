#ifndef PREMIUM_TATKAL_BOOKING_H
#define PREMIUM_TATKAL_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"

class PremiumTatkalBooking : public Booking {
public:
    PremiumTatkalBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;
};

#endif // TATKAL_BOOKING_H