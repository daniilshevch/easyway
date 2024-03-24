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
class Route
{
    friend class Station;
    friend void renew_nearest_station(Trolleybus* trolleybus);
protected:
    int number;
    Station* start;
    Station* end;
    vector<Station*>stations;
    string type;
    map<int, Station*> station_points;
    vector<int> station_distances;
    vector<long double> station_times;

    int length;


public:
    Route(int num);
    virtual void add_stops(vector<Station*> input) = 0;
    int get_number();
    virtual void print_route() = 0;
    Station* get_start_point();

};

