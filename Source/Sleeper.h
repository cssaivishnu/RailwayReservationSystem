#ifndef SLEEPER_H
#define SLEEPER_H

#include <iostream>

#include "BookingClasses.h"
using namespace std;

class Sleeper : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static Sleeper *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // Constructor with default parameters
    Sleeper(string name = "Sleeper" , float loadfactor = 1.0f , bool seat = 0 , bool ac = 0 , int num_tiers = 3 , bool luxury = 0,int mintatkal = 100 , int maxtatkal = 200 , int mindistance = 500 , int reservationcharge = 20); 

public:
    ~Sleeper();
    static const Sleeper& Type();      // returns the only singleton object of the class
    float GetLoadFactor() const;
    string GetName() const;
    bool IsSitting() const;
    Sleeper(const Sleeper& other) = delete;
    Sleeper& operator=(const Sleeper& other) = delete;
    bool IsAC() const;               // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestSleeper();      // unit test function for the sleeper class
    friend ostream& operator<<(ostream& os , const Sleeper& sleeper);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};

#endif //SLEEPER_H