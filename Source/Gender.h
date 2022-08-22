#ifndef __GENDER_H
#define __GENDER_H
#include <string>
using namespace std;
// Abstract Base Class - Concept of Gender
class Gender {
    const string& name_; // Name of the gender
protected:
    Gender(const string& name) : name_(name) { }
    virtual ~Gender() { }
public:
    const string& GetName() const { return name_; }
    virtual const string GetTitle() const = 0; // Salutation specific to gender
    static bool IsMale(const Gender&); // Checking and matching gender
};
// Male class - specialized gender
class Male : public Gender {
    Male() : Gender(Male::sName) {}
    static const string sName; // Name "Male" for this gender sub-type
public:
    static const Gender& Type() { // Singleton of Male that represents the type Male
        static const Male theObj; // May be non-const if the type has changeable behavior
        return theObj;
    }
    const string GetTitle() const // Dynamic dispatch
    { return "Mr."; } // Salutation is hard-coded - may be taken out as static
};
// Female class - specialized gender
class Female : public Gender {
    Female() : Gender(Female::sName) { }
    static const string sName; // Name "Female" for this gender sub-type
public:
    static const Gender& Type() { // Singleton of Female that represents the type Female
        static const Female theObj; // May be non-const if the type has changeable behavior
        return theObj;
    }
    const string GetTitle() const // Dynamic dispatch
    { return "Ms."; } // Salutation is hard-coded - may be taken out as static
};
inline bool Gender::IsMale(const Gender& g) { return &g == &Male::Type(); }
#endif // __GENDER_H