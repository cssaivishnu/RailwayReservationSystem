#ifndef BLIND_BOOKING_H
#define BLIND_BOOKING_H

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "DivyangBooking.h"

class BlindBooking : public DivyangBooking {
public:
    BlindBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass);
    float ComputeFare() const;

};

#endif // Blind_BOOKING_H