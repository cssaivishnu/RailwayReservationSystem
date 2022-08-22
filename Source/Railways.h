#ifndef RAILWAYS_H
#define RAILWAYS_H

#include<iostream>
#include <vector>
#include <unordered_map>

#include "Station.h"
using namespace std;

class Railways {
    Railways();        // constructor made private so that only one instance of the class can be created
    static Railways *myRailways;      // stores the only object of the class
public:
    ~Railways();
    static const Railways& IndianRailways();    // returns the only singleton object of the class
    int GetDistance(Station A , Station B) const;
    Railways(const Railways& other) = delete;
    Railways& operator=(const Railways& other) = delete;
    static const vector<Station> sStations; //const list of sStations
    static const vector<pair<pair<Station , Station> , int>> sDistStations; // const distance between sStations
    static void UnitTestRailways();
};

#endif // RAILWAYS_H