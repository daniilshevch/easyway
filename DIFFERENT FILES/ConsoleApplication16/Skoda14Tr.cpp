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
    Skoda14Tr::Skoda14Tr(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "ÿÍÓ‰‡ 14“–";
    }
    string Skoda14Tr::get_model()
    {
        return model;
    }
    int Skoda14Tr::get_index()
    {
        return index;
    }

