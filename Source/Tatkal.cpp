#include <iostream>

#include "BookingCategory.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Tatkal.h"
#include "TatkalBooking.h"

using namespace std;

Booking* Tatkal::CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const {
    return new TatkalBooking(A , B ,  d1 , d2 , passenger ,bookingclass);
}