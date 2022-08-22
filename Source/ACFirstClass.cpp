#include <iostream>

#include "ACFirstClass.h"
using namespace std;

ACFirstClass *ACFirstClass::myclass = 0;    // the static singleton pointer to the  class

ACFirstClass::ACFirstClass(string name , float loadfactor, bool seat , bool ac, int num_tiers , bool luxury,int mintatkal, int maxtatkal, int mindistance, int reservationcharge ): hasSeat_(seat) , isAC_(ac) , numberOfTiers_(num_tiers) {
    name_ = name;
    loadFactor_ = loadfactor;
    isLuxury_ = luxury;
    minTatkalCharge = mintatkal;
    maxTatkalCharge = maxtatkal;
    reservationCharges = reservationcharge;
    minTatkalDistance = mindistance;
}

const ACFirstClass& ACFirstClass::Type() {
    if(!myclass) {
        myclass = new ACFirstClass();       // returns the only instance of the  class thereby making it singleton
    }
    return *myclass;
}

float ACFirstClass::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string ACFirstClass::GetName() const{
    return (*this).name_;
}

int ACFirstClass::GetNumberOfTiers() const{
    return (*this).numberOfTiers_;
}

bool ACFirstClass::IsSitting() const{
    return (*this).hasSeat_;
}

bool ACFirstClass::IsAC() const{
    return (*this).isAC_;
}

bool ACFirstClass::IsLuxury() const{
    return (*this).isLuxury_;
}

ACFirstClass::~ACFirstClass() {}

ostream& operator<<(ostream& os , const ACFirstClass& acfirstClass) {      // prints the ACFirstClass class object
    os << "\nName : " << acfirstClass.name_ << endl;
    os << "Load Factor : " << acfirstClass.loadFactor_ << endl;
    os << "Is Sitting : " << acfirstClass.hasSeat_ << endl;
    os << "Is AC : " << acfirstClass.isAC_ << endl;
    os << "Is Luxury : " << acfirstClass.isLuxury_ << endl;
    os << "Number of Tiers : " << acfirstClass.numberOfTiers_ << "\n" << endl;
    return os;
}

void ACFirstClass::UnitTestACFirstClass() {            // checks for different use cases of the ACFirstClass class
    if(ACFirstClass::Type().name_ != "AC First Class") {
        cout << "Name of the ACFirstClass class is wrong !" << endl; // start of the data member tests
    }
    if(ACFirstClass::Type().loadFactor_ != 3.0f) {
        cout << "Load Factor of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().hasSeat_ != 0) {
        cout << "Has Seat of the ACFirstClass class is wrong !" << endl;          // these 6 tests check the data members of the ACFirstClass class
    }
    if(ACFirstClass::Type().isAC_ != 1) {
        cout << "AC of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().isLuxury_ != 1) {
        cout << "Luxury of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().numberOfTiers_ != 2) {
        cout << "Number of Tiers of the ACFirstClass class is wrong !" << endl; //  end of the data member tests
    }
    if(ACFirstClass::Type().GetName() != "AC First Class") {
        cout << "Name function of the ACFirstClass class is wrong !" << endl;   // start of the member function tests
    }
    if(ACFirstClass::Type().GetLoadFactor() != 3.0f) {
        cout << "Load Factor function of the ACFirstClass class is wrong !" << endl;         // these 6 tests check the member functions of the ACFirstClass class
    }
    if(ACFirstClass::Type().IsSitting() != 0) {
        cout << "IsSitting function of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().IsAC() != 1) {
        cout << "IsAC function of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().IsLuxury() != 1) {
        cout << "IsLuxury function of the ACFirstClass class is wrong !" << endl;
    }
    if(ACFirstClass::Type().GetNumberOfTiers() != 2) {
        cout << "GetNumberOfTiers function of the ACFirstClass class is wrong !" << endl;   // end of the member function tests
    }
}