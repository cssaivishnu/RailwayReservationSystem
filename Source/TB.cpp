#include <iostream>

#include "BookingCategory.h"
#include "Booking.h"
#include "TB.h"
#include "TBBooking.h"
#include "BookingClasses.h"

vector<pair<string , float>> TB::sConcessions = {{"AC First Class" ,0} , {"Executive Chair Car" , 0} , {"AC 2 Tier", 0} , {"First Class" , 0.75} , {"AC 3 Tier", 0} , {"AC Chair Car" , 0} , {"Sleeper" , 0.75} , {"Second Sitting" , 0.75}};

Booking* TB::CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const {
    return new TBBooking(A , B ,  d1 , d2 , passenger ,bookingclass);
}