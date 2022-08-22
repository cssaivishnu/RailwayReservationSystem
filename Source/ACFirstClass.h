#ifndef ACFIRSTCLASS_H
#define ACFIRSTCLASS_H

#include <iostream>
#include "BookingClasses.h"
using namespace std;

class ACFirstClass : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static ACFirstClass *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // constructor with default parameters
    ACFirstClass(string name = "AC First Class" , float loadfactor = 6.50f , bool seat = 0 , bool ac = 1 , int num_tiers = 2 , bool luxury = 1,int mintatkal = 400 , int maxtatkal = 500 , int mindistance = 500 , int reservationcharge = 60);

public:
    ~ACFirstClass();
    static const ACFirstClass& Type();      // returns the only singleton object of the class
    float GetLoadFactor() const;
    ACFirstClass(const ACFirstClass& other) = delete;
    ACFirstClass& operator=(const ACFirstClass& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;          // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestACFirstClass();      // unit test function for the ACFirstClass class
    friend ostream& operator<<(ostream& os , const ACFirstClass& acfirstClass);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};

#endif //ACFIRSTCLASS_H