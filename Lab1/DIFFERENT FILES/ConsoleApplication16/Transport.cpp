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

    Transport::Transport(int in_index, bool on_route = false, int in_year = NAN) : index(in_index), year(in_year), active(on_route)
    {
        current_speed = 0;
        model = "UNKNOWN";
        depo = "UNKNOWN";

    }
    void Transport::set_speed(int speed)
    {
        current_speed = speed;
    }
    void Transport::set_location(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }
    void Transport::set_year(int x)
    {
        year = x;
    }
    long double Transport::get_X()
    {
        return X;
    }
    long double Transport::get_Y()
    {
        return Y;
    }
    long long Transport::get_speed()
    {
        return current_speed;
    }
    int& Transport::get_coordinate()
    {
        return route_coordinate;
    }



