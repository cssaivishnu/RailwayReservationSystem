#include <iostream>
#include <vector>

#include "BookingCategory.h"
#include "Booking.h"
#include "Cancer.h"
#include "CancerBooking.h"
#include "BookingClasses.h"

vector<pair<string , float>> Cancer::sConcessions = {{"AC First Class" ,0.50} , {"Executive Chair Car" , 0.75} , {"AC 2 Tier", 0.50} , {"First Class" , 0.75} , {"AC 3 Tier", 1.0} , {"AC Chair Car" , 1.0} , {"Sleeper" , 1.0} , {"Second Sitting" , 1.0}};

Booking* Cancer::CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const {
    return new CancerBooking(A , B ,  d1 , d2 , passenger ,bookingclass);
}