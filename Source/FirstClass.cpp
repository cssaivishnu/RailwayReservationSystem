#include <iostream>
#include "FirstClass.h"

using namespace std;

FirstClass *FirstClass::myclass = 0;        // the static singleton pointer to the  class

FirstClass::FirstClass(string name , float loadfactor, bool seat , bool ac, int num_tiers , bool luxury,int mintatkal, int maxtatkal, int mindistance, int reservationcharge ) : hasSeat_(seat) , isAC_(ac) , numberOfTiers_(num_tiers){
    name_ = name;
    loadFactor_ = loadfactor;
    isLuxury_ = luxury;
    minTatkalCharge = mintatkal;
    maxTatkalCharge = maxtatkal;
    reservationCharges = reservationcharge;
    minTatkalDistance = mindistance;
}

const FirstClass& FirstClass::Type() {
    if(!myclass) {
        myclass = new FirstClass();     // returns the only instance of the  class thereby making it singleton
    }
    return *myclass;
}

float FirstClass::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string FirstClass::GetName() const{
    return (*this).name_;
}

int FirstClass::GetNumberOfTiers() const{
    return (*this).numberOfTiers_;
}

bool FirstClass::IsSitting() const{
    return (*this).hasSeat_;
}

bool FirstClass::IsAC() const{
    return (*this).isAC_;
}

bool FirstClass::IsLuxury() const{
    return (*this).isLuxury_;
}

FirstClass::~FirstClass() {}


ostream& operator<<(ostream& os , const FirstClass& firstClass) {      // prints the FirstClass class object
    os << "\nName : " << firstClass.name_ << endl;
    os << "Load Factor : " << firstClass.loadFactor_ << endl;
    os << "Is Sitting : " << firstClass.hasSeat_ << endl;
    os << "Is AC : " << firstClass.isAC_ << endl;
    os << "Is Luxury : " << firstClass.isLuxury_ << endl;
    os << "Number of Tiers : " << firstClass.numberOfTiers_ << "\n" << endl;
    return os;
}

void FirstClass::UnitTestFirstClass() {            // checks for different use cases of the FirstClass class
    if(FirstClass::Type().name_ != "First Class") {
        cout << "Name of the FirstClass class is wrong !" << endl; // start of the data member tests
    }
    if(FirstClass::Type().loadFactor_ != 2.0f) {
        cout << "Load Factor of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().hasSeat_ != 0) {
        cout << "Has Seat of the FirstClass class is wrong !" << endl;          // these 6 tests check the data members of the FirstClass class
    }
    if(FirstClass::Type().isAC_ != 0) {
        cout << "AC of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().isLuxury_ != 1) {
        cout << "Luxury of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().numberOfTiers_ != 2) {
        cout << "Number of Tiers of the FirstClass class is wrong !" << endl; //  end of the data member tests
    }
    if(FirstClass::Type().GetName() != "First Class") {
        cout << "Name function of the FirstClass class is wrong !" << endl;   // start of the member function tests
    }
    if(FirstClass::Type().GetLoadFactor() != 2.0f) {
        cout << "Load Factor function of the FirstClass class is wrong !" << endl;         // these 6 tests check the member functions of the FirstClass class
    }
    if(FirstClass::Type().IsSitting() != 0) {
        cout << "IsSitting function of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().IsAC() != 0) {
        cout << "IsAC function of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().IsLuxury() != 1) {
        cout << "IsLuxury function of the FirstClass class is wrong !" << endl;
    }
    if(FirstClass::Type().GetNumberOfTiers() != 2) {
        cout << "GetNumberOfTiers function of the FirstClass class is wrong !" << endl;   // end of the member function tests
    }
}