#include <iostream>
#include <cmath>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "GeneralBooking.h"
#include "Railways.h"
using namespace std;

GeneralBooking::GeneralBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) : Booking(A , B , d1 , d2 , bookingclass, passenger) {

}

float GeneralBooking::ComputeFare() const {
    int distance = Railways::IndianRailways().GetDistance((*this).fromStation_ , (*this).toStation_);
    float base_fare = distance*Booking::sBaseFarePerKM;
    float loaded_fare = base_fare*(*this).bookingClass.GetLoadFactor();
    float final_fare = loaded_fare + (*this).bookingClass.GetReservationCharge();
    return round(final_fare);
}