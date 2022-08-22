#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include <iostream>

#include "BookingClasses.h"
using namespace std;

class FirstClass : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static FirstClass *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // constructor with default parameters
    FirstClass(string name = "First Class" , float loadfactor = 3.0f , bool seat = 0 , bool ac = 0 , int num_tiers = 2 , bool luxury = 1,int mintatkal = 400 , int maxtatkal = 500 , int mindistance = 500 , int reservationcharge = 50);

public:
    ~FirstClass();
    static const FirstClass& Type();            // returns the only singleton object of the class
    float GetLoadFactor() const;
    FirstClass(const FirstClass& other) = delete;
    FirstClass& operator=(const FirstClass& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;                  // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestFirstClass();      // unit test function for the FirstClass class
    friend ostream& operator<<(ostream& os , const FirstClass& firstClass);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};

#endif //FIRSTCLASS_H