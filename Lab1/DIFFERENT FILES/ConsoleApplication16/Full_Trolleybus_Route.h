#pragma once
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
using namespace std;

const long long INF = 1e9;
class Full_Trolleybus_Route
{
    friend void full_route_renew_both_side(Full_Trolleybus_Route* route, int seconds);
    friend void full_route_renew_final_version(Full_Trolleybus_Route* route, int seconds);
private:
    Trolleybus_Route* front;
    Trolleybus_Route* reverse;
public:
    Full_Trolleybus_Route(Trolleybus_Route* first, Trolleybus_Route* second);
 
    void print_stations_full();

    void print_condition();

    void print_condition_with_distances();
    
    void print_condition_with_times();
    
};

