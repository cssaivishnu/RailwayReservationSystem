#include <iostream>
#include <vector>

#include "BookingCategory.h"
#include "Booking.h"
#include "Blind.h"
#include "BlindBooking.h"
#include "BookingClasses.h"

vector<pair<string , float>> Blind::sConcessions = {{"AC First Class" ,0.50} , {"Executive Chair Car" , 0.75} , {"AC 2 Tier", 0.50} , {"First Class" , 0.75} , {"AC 3 Tier", 0.75} , {"AC Chair Car" , 0.75} , {"Sleeper" , 0.75} , {"Second Sitting" , 0.75}};

Booking* Blind::CreateBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) const {
    return new BlindBooking(A , B ,  d1 , d2 , passenger ,bookingclass);
}