#include <iostream>
#include <cmath>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "LadiesBooking.h"
#include "Railways.h"
using namespace std;

LadiesBooking::LadiesBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) : ConcessionBooking(A , B , d1 , d2 , bookingclass, passenger) {

}

float LadiesBooking::ComputeFare() const {
    int distance = Railways::IndianRailways().GetDistance((*this).fromStation_ , (*this).toStation_);
    float base_fare = distance*Booking::sBaseFarePerKM;
    float loaded_fare = base_fare*(*this).bookingClass.GetLoadFactor();
    float final_fare = loaded_fare + (*this).bookingClass.GetReservationCharge();
    return round(final_fare);
}