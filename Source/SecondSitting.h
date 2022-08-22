#ifndef SECOND_SITTING_H
#define SECOND_SITTING_H

#include <iostream>

#include "BookingClasses.h"
using namespace std;

class SecondSitting : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static SecondSitting *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // constructor with default parameters
    SecondSitting(string name = "Second Sitting" , float loadfactor = 0.6f , bool seat = 1 , bool ac = 0 , int num_tiers = 0 , bool luxury = 0,int mintatkal = 10 , int maxtatkal = 15, int mindistance = 100 , int reservationcharge = 15);

public:
    ~SecondSitting();
    static const SecondSitting& Type();     // returns the only singleton object of the class
    float GetLoadFactor() const;
    string GetName() const;
    SecondSitting(const SecondSitting& other) = delete;
    SecondSitting& operator=(const SecondSitting& other) = delete;
    bool IsSitting() const;
    bool IsAC() const;                  // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestSecondSitting();      // unit test function for the second sitting class
    friend ostream& operator<<(ostream& os , const SecondSitting& secondSitting);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};

#endif //SECOND_SITTING_H