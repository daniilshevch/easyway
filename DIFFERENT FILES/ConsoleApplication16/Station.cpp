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

    Station::Station()
    {

    }
    Station::Station(string in_name, double first = 0, double second = 0, string in_type = "BOTH_SIDE")
    {
        name = in_name;
        X = first;
        Y = second;
        type = in_type;

    }
    long double Station::get_X()
    {
        return X;
    }
    long double Station::get_Y()
    {
        return Y;
    }
    string Station::get_name()
    {
        return name;
    }
    vector<Trolleybus*> Station::get_current_trolleybuses()
    {
        return current_trolleybuses;
    }
    void Station::add_trolleybus(Trolleybus_Route input)
    {
        trolleybus_list.push_back(input);
    }



    void Station::station_trolleybuses()
    {
        set<int> list;
        for (int i = 0; i < trolleybus_list.size(); i++)
        {
            list.insert(trolleybus_list[i].get_number());
        }
        for (int x : list)
        {
            cout << x << " ";
        }

    }