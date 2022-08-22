#include<iostream>
#include<vector>
#include<unordered_map>

#include "Railways.h"
#include "Station.h"
#include "Exception.h"
using namespace std;

Railways::Railways() {}
Railways::~Railways() {}

Railways *Railways::myRailways = 0;

const Railways& Railways::IndianRailways() {
    if(!myRailways) {
        int flag = 0;
    
        for(auto x : Railways::sStations){
            int cnt = 0;
            for(auto y : Railways::sStations){
                if(x.GetName() == y.GetName())
                    cnt++;
            }
            if(cnt > 1){
                flag = 1;
                break;
            }
        }

        int n = (int)Railways::sStations.size();
        if((int)Railways::sDistStations.size() != (n*(n-1)/2)){ 
            flag = 1;
        }

        for(auto x : Railways::sDistStations){
            int cnt = 0;
            for(auto y : Railways::sDistStations){
                if(x.first.first == y.first.first && x.first.second == y.first.second){
                    cnt++;
                }
            }
            if(cnt > 1){
                flag = 1;
                break;
            }
        }

        for(auto x : Railways::sDistStations){
            if(x.first.first == x.first.second){
                flag = 1;
                break;
            }
        }
        
        try{
            if(flag){
                BadRailways ex;
                throw ex;
            }
            else{
                myRailways = new Railways();           // returns the only singleton object of the class
                return *myRailways;
            }
        }
        catch(BadRailways &ex){
            throw;
        }
        // myRailways = new Railways();
    }
    return *myRailways;
}

int Railways::GetDistance(Station A , Station B) const {
    for(pair<pair<Station , Station> , int> p : Railways::sDistStations) {
        if((p.first.first == A && p.first.second == B) || (p.first.first == B && p.first.second == A)) {        // compares the stations and if they are found same 
            return p.second;                                   // returns the distance between them
        }
    }
    return 0;              // if no matching record found returns 0
}

// it stores the list of stations
const vector<Station> Railways::sStations = {Station("Mumbai") , Station("Delhi") , Station("Bangalore") , Station("Kolkata") , Station("Chennai")};

// it stores the pairwise distance between two stations
const vector<pair<pair<Station , Station> , int>> Railways::sDistStations = { 
    {{Station("Mumbai") , Station("Delhi")} , 1447} , 
    {{Station("Mumbai") , Station("Bangalore")} , 981} , 
    {{Station("Mumbai") , Station("Kolkata")} , 2014} , 
    {{Station("Mumbai") , Station("Chennai")} , 1338} , 
    {{Station("Delhi") , Station("Bangalore")} , 2150} ,
    {{Station("Delhi") , Station("Kolkata")} , 1472} ,
    {{Station("Delhi") , Station("Chennai")} , 2180} , 
    {{Station("Bangalore") , Station("Kolkata")} , 1871} ,
    {{Station("Bangalore") , Station("Chennai")} , 350} ,
    {{Station("Kolkata") , Station("Chennai")} , 1659} 
};

void Railways::UnitTestRailways() {
    cout<<"     Unit Test for Railways Class"<<endl;

    Station s1 = Station :: Construct("Mumbai");
    int found = 0;
    for(Station s : Railways::sStations) {
        if(s == s1) {
            found = 1;
            break;                                  // similarly can be done for other stations
        }
    }
    if(!found) {
        cout << "VALID STATION IN RAILWAYS : FAILED" << endl;
    }
    else{
        cout << "VALID STATION IN RAILWAYS : PASSED" << endl;
    }
    Station s3 = Station :: Construct("Varanasi");
    found = 0;
    for(Station s : Railways::sStations) {
        if(s == s1) {
            found = 1;
            break;                                  // similarly can be done for other stations
        }
    }
    if(!found) {
        cout << "INVALID STATION IN RAILWAYS (NEGATIVE TEST) : PASSED" << endl;
    }
    else{
        cout << "INVALID STATION IN RAILWAYS (NEGATIVE TEST) : FAILED" << endl;
    }
    
    int flag = 0;
    
    for(auto x : Railways::sStations){
        int cnt = 0;
        for(auto y : Railways::sStations){
            if(x.GetName() == y.GetName())
                cnt++;
        }
        if(cnt > 1){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"DUPLICATE STATIONS IN RAILWAYS (NEGATIVE TEST) : PASSED"<<endl;
    }
    else{
        cout<<"DUPLICATE STATIONS IN RAILWAYS (NEGATIVE TEST) : FAILED" <<endl;
    }

    flag = 0;
    int n = (int)Railways::sStations.size();
    if((int)Railways::sDistStations.size() != (n*(n-1)/2)){ 
        flag = 1;
    }
    if(flag){
        cout<<"DISTANCE BETWEEN SAME STATIONS IN RAILWAYS (NEGATIVE TEST) : PASSED"<<endl;
    }
    else{
        cout<<"DISTANCE BETWEEN SAME STATIONS IN RAILWAYS (NEGATIVE TEST) : FAILED" <<endl;
    }

    flag = 0;
    for(auto x : Railways::sDistStations){
        int cnt = 0;
        for(auto y : Railways::sDistStations){
            if(x.first.first == y.first.first && x.first.second == y.first.second){
                cnt++;
            }
        }
        if(cnt > 1){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"DUPLICATE DISTANCE IN RAILWAYS (NEGATIVE TEST) : PASSED"<<endl;
    }
    else{
        cout<<"DUPLICATE DISTANCE IN RAILWAYS (NEGATIVE TEST) : FAILED" <<endl;
    }
    
    Station s2("Delhi");
    if(Railways::IndianRailways().GetDistance(s1 , s2) != 1447) {       // similarly can be done for other stations to get the distance
        cout << "DISTANCE BETWEEN STATION IN RAILWAYS : FAILED" << endl;
    }
    else{
        cout << "DISTANCE BETWEEN STATION IN RAILWAYS : PASSED" << endl;
    }
    
    cout<<endl;
}
