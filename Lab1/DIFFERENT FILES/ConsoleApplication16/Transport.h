#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>

#include "Trolleybus.h"
#include "LAZE183.h"
#include "ElectronT19101.h"
#include "ElectronT19102.h"
#include "BogdanT601.h"
#include "Skoda14Tr.h"
#include "Tram.h"
#include "Station.h"
#include "Route.h"
#include "Trolleybus_Route.h"
#include "Full_Trolleybus_Route.h"
using namespace std;
class Transport
{
protected:
    int index;
    int year;
    string model;
    bool active;
    string depo;
    int current_speed;
    double X;
    double Y;
    int route_coordinate;
public:
    Transport(int in_index, bool on_route = false, int in_year = NAN);

    virtual void check_info() = 0;
    void set_speed(int speed);
   
    void set_location(int x, int y);
 
    void set_year(int x);
  
    long double get_X();
  
    long double get_Y();
  
    long long get_speed();
   
    int& get_coordinate();
  

};

