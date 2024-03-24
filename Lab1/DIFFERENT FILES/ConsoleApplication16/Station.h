#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>

#include "Transport.h"
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
class Station
{
    friend void advance_in_time(Trolleybus* trolleybus, int seconds);
    friend void renew_nearest_station(Trolleybus* trolleybus);
    friend class Trolleybus_Route;
    friend class Full_Trolleybus_Route;
    friend class Trolleybus;
private:
    string name;
    double X;
    double Y;
    string type;
    vector<Trolleybus_Route> trolleybus_list;
    vector<Trolleybus*> current_trolleybuses;
    void add_trolleybus(Trolleybus_Route input);


public:
    Station();
    Station(string in_name, double first = 0, double second = 0, string in_type = "BOTH_SIDE");
    void station_trolleybuses();
    long double get_X();
    long double get_Y();
    string get_name();
    vector<Trolleybus*> get_current_trolleybuses();


};
