#include <iostream>
#include <cmath>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "SeniorCitizenBooking.h"
#include "Railways.h"
#include "Gender.h"
using namespace std;

SeniorCitizenBooking::SeniorCitizenBooking(Station A , Station B , Date& d1 , Date& d2 , Passenger& passenger ,const BookingClasses& bookingclass) : ConcessionBooking(A , B , d1 , d2 , bookingclass, passenger) {

}

float SeniorCitizenBooking::ComputeFare() const {
    int distance = Railways::IndianRailways().GetDistance((*this).fromStation_ , (*this).toStation_);
    float base_fare = distance*Booking::sBaseFarePerKM;
    float loaded_fare = base_fare*(*this).bookingClass.GetLoadFactor();

    if((*this).passenger_.IsMale()) {
        
        int age = (*this).passenger_.GetAge((*this).dateOfBooking_);
        // cout<<"age "<<age<<endl;
        if(age > 60) {
            loaded_fare = loaded_fare*(1.0 - 0.40);
        }
    }
    else {
        int age = (*this).passenger_.GetAge((*this).dateOfBooking_);
    
        if(age > 58) {
            loaded_fare = loaded_fare*(1.0 - 0.50);
        }
    }
    float final_fare = loaded_fare + (*this).bookingClass.GetReservationCharge();
    return round(final_fare);
}