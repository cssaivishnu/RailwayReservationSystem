#include <iostream>
#include <cmath>

#include "AC2Tier.h"
using namespace std;

AC2Tier *AC2Tier::myclass = 0;      // the static singleton pointer to the  class

AC2Tier::AC2Tier(string name , float loadfactor, bool seat , bool ac, int num_tiers , bool luxury , int mintatkal, int maxtatkal, int mindistance, int reservationcharge): hasSeat_(seat) , isAC_(ac) , numberOfTiers_(num_tiers) {
    name_ = name;
    loadFactor_ = loadfactor;
    isLuxury_ = luxury;
    minTatkalCharge = mintatkal;
    maxTatkalCharge = maxtatkal;
    reservationCharges = reservationcharge;
    minTatkalDistance = mindistance;
}

const AC2Tier& AC2Tier::Type() {
    if(!myclass) {
        myclass = new AC2Tier();            // returns the only instance of the  class thereby making it singleton
    }
    return *myclass;
}

float AC2Tier::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string AC2Tier::GetName() const{
    return (*this).name_;
}

int AC2Tier::GetNumberOfTiers() const{
    return (*this).numberOfTiers_;
}

bool AC2Tier::IsSitting() const{
    return (*this).hasSeat_;
}

bool AC2Tier::IsAC() const{
    return (*this).isAC_;
}

bool AC2Tier::IsLuxury() const{
    return (*this).isLuxury_;
}

AC2Tier::~AC2Tier() {}


ostream& operator<<(ostream& os , const AC2Tier& ac2Tier) {      // prints the AC2Tier class object
    os << "\nName : " << ac2Tier.name_ << endl;
    os << "Load Factor : " << ac2Tier.loadFactor_ << endl;
    os << "Is Sitting : " << ac2Tier.hasSeat_ << endl;
    os << "Is AC : " << ac2Tier.isAC_ << endl;
    os << "Is Luxury : " << ac2Tier.isLuxury_ << endl;
    os << "Number of Tiers : " << ac2Tier.numberOfTiers_ << "\n" << endl;
    return os;
}

void AC2Tier::UnitTestAC2Tier() {            // checks for different use cases of the AC2Tier class
    if(AC2Tier::Type().name_ != "AC 2 Tier") {
        cout << "Name of the AC2Tier class is wrong !" << endl; // start of the data member tests
    }
    if(fabs(AC2Tier::Type().loadFactor_ - 2.0f) > 0.01f) {
        cout << "Load Factor of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().hasSeat_ != 0) {
        cout << "Has Seat of the AC2Tier class is wrong !" << endl;          // these 6 tests check the data members of the AC2Tier class
    }
    if(AC2Tier::Type().isAC_ != 1) {
        cout << "AC of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().isLuxury_ != 0) {
        cout << "Luxury of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().numberOfTiers_ != 2) {
        cout << "Number of Tiers of the AC2Tier class is wrong !" << endl; //  end of the data member tests
    }
    if(AC2Tier::Type().GetName() != "AC 2 Tier") {
        cout << "Name function of the AC2Tier class is wrong !" << endl;   // start of the member function tests
    }
    if(AC2Tier::Type().GetLoadFactor() != 2.0f) {
        cout << "Load Factor function of the AC2Tier class is wrong !" << endl;         // these 6 tests check the member functions of the AC2Tier class
    }
    if(AC2Tier::Type().IsSitting() != 0) {
        cout << "IsSitting function of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().IsAC() != 1) {
        cout << "IsAC function of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().IsLuxury() != 0) {
        cout << "IsLuxury function of the AC2Tier class is wrong !" << endl;
    }
    if(AC2Tier::Type().GetNumberOfTiers() != 2) {
        cout << "GetNumberOfTiers function of the AC2Tier class is wrong !" << endl;   // end of the member function tests
    }
}