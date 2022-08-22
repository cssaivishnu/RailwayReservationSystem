#ifndef CONCESSION_H
#define CONCESSION_H

#include <iostream>

#include "BookingCategory.h"
using namespace std;

class Concession : public BookingCategory {
protected:
    Concession(string name) : BookingCategory(name) {}
};

#endif