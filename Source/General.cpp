#include <iostream>

#include "BookingCategory.h"
#include "Booking.h"
#include "General.h"
#include "GeneralBooking.h"
#include "BookingClasses.h"

Booking* General::CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const {
    return new GeneralBooking(A , B ,  d1 , d2 , passenger ,bookingclass);
}