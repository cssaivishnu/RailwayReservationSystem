#include <iostream>
#include <cmath>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Divyang.h"
#include "Handicapped.h"
#include "HandicappedBooking.h"
#include "DivyangBooking.h"
#include "Railways.h"
using namespace std;

HandicappedBooking::HandicappedBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) : DivyangBooking(A , B , d1 , d2 , bookingclass, passenger) {

}

float HandicappedBooking::ComputeFare() const {
    int distance = Railways::IndianRailways().GetDistance((*this).fromStation_ , (*this).toStation_);
    float base_fare = distance*Booking::sBaseFarePerKM;
    float loaded_fare = base_fare*(*this).bookingClass.GetLoadFactor();
    if((*this).passenger_.GetDisabilityType() == "Handicapped") {
        string bookingCategoryName = (*this).bookingClass.GetName();
        for(pair<string , float> p : Handicapped::sConcessions) {
            if(bookingCategoryName == p.first) {
                loaded_fare = loaded_fare*(1.0 - p.second);
                break;
            }
        }
    }
    float final_fare = loaded_fare + (*this).bookingClass.GetReservationCharge();
    return round(final_fare);
}