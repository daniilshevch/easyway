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
    ElectronT19102::ElectronT19102(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "Електрон Т19102";
    }
    string ElectronT19102::get_model()
    {
        return model;
    }
    int ElectronT19102::get_index()
    {
        return index;
    }
