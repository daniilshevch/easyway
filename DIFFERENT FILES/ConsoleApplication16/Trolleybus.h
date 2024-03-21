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
class Trolleybus : public Transport
{
    friend void renew_nearest_station(Trolleybus* trolleybus);
    friend class Trolleybus_Route;
    friend void advance_in_time(Trolleybus* trolleybus, int seconds);
private:
    bool connected;
    bool autonomic_power;
    Trolleybus_Route* current_route = nullptr;
    Station* nearest_station;
public:
    virtual void check_info() override;
    Trolleybus(int in_index, bool on_route = false, int in_year = NAN);
    virtual string get_model();
    virtual int get_index();
    virtual int get_year();
    Trolleybus_Route* get_route();
    void sent_to_route(Trolleybus_Route* sent, Station* start_point);
    void sent_to_route_additional(Trolleybus_Route* sent, Station* start_position, int start_point);

    int advance_in_time(Trolleybus* trolleybus, int seconds);
    Station* get_nearest_station();

};

