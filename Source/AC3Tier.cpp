#include <iostream>

#include "AC3Tier.h"
using namespace std;

AC3Tier *AC3Tier::myclass = 0;      // the static singleton pointer to the  class

AC3Tier::AC3Tier(string name , float loadfactor, bool seat , bool ac, int num_tiers , bool luxury ,int mintatkal, int maxtatkal, int mindistance, int reservationcharge): hasSeat_(seat) , isAC_(ac) , numberOfTiers_(num_tiers) {
    name_ = name;
    loadFactor_ = loadfactor;
    isLuxury_ = luxury;
    minTatkalCharge = mintatkal;
    maxTatkalCharge = maxtatkal;
    reservationCharges = reservationcharge;
    minTatkalDistance = mindistance;
}

const AC3Tier& AC3Tier::Type() {
    if(!myclass) {
        myclass = new AC3Tier();        // returns the only instance of the  class thereby making it singleton
    }
    return *myclass;
}

float AC3Tier::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string AC3Tier::GetName() const{
    return (*this).name_;
}

int AC3Tier::GetNumberOfTiers() const{
    return (*this).numberOfTiers_;
}

bool AC3Tier::IsSitting() const{
    return (*this).hasSeat_;
}

bool AC3Tier::IsAC() const{
    return (*this).isAC_;
}

bool AC3Tier::IsLuxury() const{
    return (*this).isLuxury_;
}

AC3Tier::~AC3Tier() {}


ostream& operator<<(ostream& os , const AC3Tier& ac3Tier) {      // prints the AC3Tier class object
    os << "\nName : " << ac3Tier.name_ << endl;
    os << "Load Factor : " << ac3Tier.loadFactor_ << endl;
    os << "Is Sitting : " << ac3Tier.hasSeat_ << endl;
    os << "Is AC : " << ac3Tier.isAC_ << endl;
    os << "Is Luxury : " << ac3Tier.isLuxury_ << endl;
    os << "Number of Tiers : " << ac3Tier.numberOfTiers_ << "\n" << endl;
    return os;
}

void AC3Tier::UnitTestAC3Tier() {            // checks for different use cases of the AC3Tier class
    if(AC3Tier::Type().name_ != "AC 3 Tier") {
        cout << "Name of the AC3Tier class is wrong !" << endl; // start of the data member tests
    }
    if(AC3Tier::Type().loadFactor_ != 1.75f) {
        cout << "Load Factor of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().hasSeat_ != 0) {
        cout << "Has Seat of the AC3Tier class is wrong !" << endl;          // these 6 tests check the data members of the AC3Tier class
    }
    if(AC3Tier::Type().isAC_ != 1) {
        cout << "AC of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().isLuxury_ != 0) {
        cout << "Luxury of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().numberOfTiers_ != 3) {
        cout << "Number of Tiers of the AC3Tier class is wrong !" << endl; //  end of the data member tests
    }
    if(AC3Tier::Type().GetName() != "AC 3 Tier") {
        cout << "Name function of the AC3Tier class is wrong !" << endl;   // start of the member function tests
    }
    if(AC3Tier::Type().GetLoadFactor() != 1.75f) {
        cout << "Load Factor function of the AC3Tier class is wrong !" << endl;         // these 6 tests check the member functions of the AC3Tier class
    }
    if(AC3Tier::Type().IsSitting() != 0) {
        cout << "IsSitting function of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().IsAC() != 1) {
        cout << "IsAC function of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().IsLuxury() != 0) {
        cout << "IsLuxury function of the AC3Tier class is wrong !" << endl;
    }
    if(AC3Tier::Type().GetNumberOfTiers() != 3) {
        cout << "GetNumberOfTiers function of the AC3Tier class is wrong !" << endl;   // end of the member function tests
    }
}