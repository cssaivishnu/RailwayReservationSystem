#ifndef AC3TIER_H
#define AC3TIER_H

#include <iostream>
#include "BookingClasses.h"
using namespace std;

class AC3Tier : public BookingClasses {
    bool isLuxury_;           // to store whether the class is luxury or not
    const bool isAC_;       // to store whether the class is AC or not made const since won't change in future
    const int numberOfTiers_;       // to store the number of tiers in the class made const since won't change in future
    const bool hasSeat_;           // to store whether the class is sitting or not made const since won't change in future
    static AC3Tier *myclass;       // the singleton pointer to the class
    int minTatkalCharge;
    int maxTatkalCharge;
    int minTatkalDistance;
    int reservationCharges;
    // constructor with default parameters
    AC3Tier(string name = "AC 3 Tier" , float loadfactor = 2.50f , bool seat = 0 , bool ac = 1 , int num_tiers = 3 , bool luxury = 0,int mintatkal = 300 , int maxtatkal = 400 , int mindistance = 500 , int reservationcharge = 40);

public:
    ~AC3Tier();
    static const AC3Tier& Type();       // returns the only singleton object of the class
    float GetLoadFactor() const;
    AC3Tier(const AC3Tier& other) = delete;
    AC3Tier& operator=(const AC3Tier& other) = delete;
    string GetName() const;
    bool IsSitting() const;
    bool IsAC() const;              // the member functions are made const since a const object of the class will be invoking them
    int GetNumberOfTiers() const;
    bool IsLuxury() const;
    static void UnitTestAC3Tier();      // unit test function for the class
    friend ostream& operator<<(ostream& os , const AC3Tier& ac3Tier);
    int GetMinimumTatkalCharge() const {return minTatkalCharge;};
    int GetMaximumTatkalCharge() const {return maxTatkalCharge;};
    int GetMinimumTatkalDistance() const {return minTatkalDistance;};
    int GetReservationCharge() const {return reservationCharges;};
};


#endif //AC3TIER_H