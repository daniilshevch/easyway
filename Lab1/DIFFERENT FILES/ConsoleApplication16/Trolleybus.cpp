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

    void Trolleybus::check_info()
    {

    }
    Trolleybus::Trolleybus(int in_index, bool on_route = false, int in_year = NAN) : Transport(in_index, on_route, in_year)
    {

    }
    string Trolleybus::get_model()
    {
        return model;
    }
    int Trolleybus::get_index()
    {
        return index;
    }
    int Trolleybus::get_year()
    {
        return year;
    }
    Trolleybus_Route* Trolleybus::get_route()
    {
        return current_route;
    }
    void Trolleybus::sent_to_route(Trolleybus_Route* sent, Station* start_point);
    void Trolleybus::sent_to_route_additional(Trolleybus_Route* sent, Station* start_position, int start_point);

    int advance_in_time(Trolleybus* trolleybus, int seconds);
    Station* Trolleybus::get_nearest_station()
    {
        return nearest_station;
    }
    void Trolleybus::sent_to_route(Trolleybus_Route* sent, Station* start_point = nullptr)
    {
        if (current_route != nullptr)
        {
            auto it = find(current_route->active_trolleybuses_list.begin(), current_route->active_trolleybuses_list.end(), this);
            current_route->active_trolleybuses_list.erase(it);
            auto it2 = find(nearest_station->current_trolleybuses.begin(), nearest_station->current_trolleybuses.end(), this);
            nearest_station->current_trolleybuses.erase(it2);
        }
        sent->active_trolleybuses_list.push_back(this);
        current_route = sent;
        nearest_station = start_point;
        start_point->current_trolleybuses.push_back(this);
        for (auto it = sent->station_points.begin(); it != sent->station_points.end(); it++)
        {
            if (it->second == start_point)
            {
                route_coordinate = it->first;
            }
        }



    }
    void Trolleybus::sent_to_route_additional(Trolleybus_Route* sent, Station* start_station, int start_point)
    {
        if (current_route != nullptr)
        {
            auto it = find(current_route->active_trolleybuses_list.begin(), current_route->active_trolleybuses_list.end(), this);
            current_route->active_trolleybuses_list.erase(it);
            auto it2 = find(nearest_station->current_trolleybuses.begin(), nearest_station->current_trolleybuses.end(), this);
            nearest_station->current_trolleybuses.erase(it2);
        }
        sent->active_trolleybuses_list.push_back(this);
        current_route = sent;
        nearest_station = start_station;
        start_station->current_trolleybuses.push_back(this);
        route_coordinate = start_point;
    }

