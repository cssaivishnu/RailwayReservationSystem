#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <vector>

#include "Date.h"
#include "Station.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "BookingCategory.h"
using namespace std;

class BookingCategory;

class Booking {
protected:
    int PNR_;
    Station fromStation_;
    Station toStation_;
    const Date dateOfBooking_;
    const Date dateOfReservation_;
    const BookingClasses& bookingClass;
    bool bookingStatus_;
    string bookingMessage_;
    Passenger passenger_;
    Booking(Station A , Station B , Date d1 ,Date d2 ,  const BookingClasses& bookingclass , Passenger psngr , bool bookingStatus = 1 , string bookingmsg = "BOOKING SUCCEEDED");
public:
    static float sBaseFarePerKM;         // base fare per km
    static vector<Booking*> sBookings;   // stores the booking made so far
    static int sBookingPNRSerial;
    static float sACSurcharge;
    static float sLuxuryTaxPercent;
    static Booking* ReserveBooking(Station A , Station B , Date d1  , Date d2 , const BookingClasses& bookingclass , const BookingCategory& bookingcategory , Passenger psngr , bool bookingStatus = 1 , string bookingmsg = "BOOKING SUCCEEDED");
    
    Booking(const BookingClasses& booking) = delete;
    Booking& operator=(const Booking& other) = delete;
    virtual ~Booking();       // destructor made virtual to avoid slicing
    virtual float ComputeFare() const = 0;      // made virtual in case polymorphic hierarchy is to be created
    friend ostream& operator<< (ostream& os, const Booking& b);
    static void UnitTestBooking();
};

#endif // BOOKING_H