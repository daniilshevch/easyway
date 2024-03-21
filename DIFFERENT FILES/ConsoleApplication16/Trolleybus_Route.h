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
class Trolleybus_Route : public Route
{
    friend void renew_nearest_station(Trolleybus* trolleybus);
    friend class Trolleybus;
private:
    Trolleybus_Route* reversed_route;
    friend class Full_Trolleybus_Route;
public:
    vector<Trolleybus*> active_trolleybuses_list;

    Trolleybus_Route(int num) : Route(num)
    {

    }
public:
    virtual void add_stops(vector<Station*> input) override
    {
        for (int i = 0; i < input.size(); i++)
        {
            stations.push_back(input[i]);
            input[i]->add_trolleybus(*this);
        }
        start = input[0];
        end = input[input.size() - 1];
    }
    virtual void print_route() override
    {
        for (int i = 0; i < stations.size(); i++)
        {
            cout << stations[i]->name << endl;
        }
    }
    void add_active_trolleybus(Trolleybus trol)
    {
        active_trolleybuses_list.push_back(&trol);
    }
    void print_active_trolleybuses()
    {
        cout << "Активнi тролейбуси на маршрутi " << number << " " << start->name << "-" << end->name << ":" << endl;
        for (Trolleybus* x : active_trolleybuses_list)
        {
            cout << x->index << " ";
        }
        cout << endl;
    }
    void print_condition()
    {
        cout << "Тролейбусiв на лiнii: " << active_trolleybuses_list.size() << endl;
        for (int i = 0; i < stations.size(); i++)
        {
            cout << stations[i]->name << endl;
        }
    }
    void organize_stops(vector<Station*> stations, vector<int> distances)
    {
        length = *max_element(distances.begin(), distances.end());
        for (int i = 0; i < stations.size(); i++)
        {
            station_points.insert(make_pair(distances[i], stations[i]));
        }
    }
    void print_route_modified()
    {
        for (auto it = station_points.begin(); it != station_points.end(); it++)
        {
            cout << it->second->name << " " << it->first << endl;
        }
    }
    void evaluate_distances_and_times()
    {
        station_distances.clear();
        station_times.clear();
        for (auto it = station_points.begin(); it != station_points.end(); it++)
        {
            int result = INF;
            int result_speed = 0.000001;
            for (Trolleybus* x : active_trolleybuses_list)
            {
                //cout << "Coordinate: " << x->get_coordinate() << endl;
                //cout << "Stop: " << it->first << endl;
                //cout << "Number: " << x->get_index() << endl;
                int distance = find_distance(*x, it->first);
                if (distance < result && distance >= 0)
                {
                    result = distance;
                    result_speed = x->get_speed();
                }
            }
            station_distances.push_back(result);
            long double metres_per_second = static_cast<long double>(result_speed) * 1000 / 60;
            station_times.push_back(static_cast<long double>(result) / metres_per_second);
        }
    }
    int get_number()
    {
        return number;
    }
    void print_distances()
    {

    }
    int get_length()
    {
        return length;
    }
    void set_reversed(Trolleybus_Route* reversed)
    {
        reversed_route = reversed;
    }
    Trolleybus_Route* get_reversed()
    {
        return reversed_route;
    }


};