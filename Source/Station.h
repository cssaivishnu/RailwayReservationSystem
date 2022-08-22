#ifndef STATION_H
#define STATION_H

#include<iostream>
using namespace std;

class Station {
    string name_;
public:
    Station(string name);
    string GetName() const;
    int GetDistance(const Station& other);
    Station(const Station& other);
    Station& operator=(const Station& other);
    ~Station();
    bool operator==(const Station& other);    // checks for equality of two stations
    friend ostream& operator<<(ostream& os, const Station& station);
    static void UnitTestStation();    // unit testing for the station class
    static Station Construct(string name = "");
};

#endif // STATION_H