#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <gtest/gtest.h>
using namespace std;
const long long INF = 1e9;
class Transport
{
protected:
    int index;
    int year;
    string model;
    bool active;
    string depo;
    int current_speed;
    double X;
    double Y;
    int route_coordinate;
public:
    Transport(int in_index, bool on_route = false, int in_year = NAN) : index(in_index), year(in_year), active(on_route)
    {
        current_speed = 0;
        model = "UNKNOWN";
        depo = "UNKNOWN";

    }
    virtual void check_info() = 0;
    void set_speed(int speed)
    {
        current_speed = speed;
    }
    void set_location(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }
    void set_year(int x)
    {
        year = x;
    }
    long double get_X()
    {
        return X;
    }
    long double get_Y()
    {
        return Y;
    }
    long long get_speed()
    {
        return current_speed;
    }
    int& get_coordinate()
    {
        return route_coordinate;
    }

};
class Station;
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
    virtual void check_info() override
    {

    }
    Trolleybus(int in_index, bool on_route = false, int in_year = NAN) : Transport(in_index, on_route, in_year)
    {

    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
    virtual int get_year()
    {
        return year;
    }
    Trolleybus_Route* get_route()
    {
        return current_route;
    }
    void sent_to_route(Trolleybus_Route* sent, Station* start_point);
    void sent_to_route_additional(Trolleybus_Route* sent, Station* start_position, int start_point);

    int advance_in_time(Trolleybus* trolleybus, int seconds);
    Station* get_nearest_station()
    {
        return nearest_station;
    }

};
class LAZE183 : public Trolleybus
{
public:
    LAZE183(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "ЛАЗ Е183";
    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
};
class ElectronT19101 : public Trolleybus
{
public:
    ElectronT19101(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "Електрон Т19101";
    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
};
class ElectronT19102 : public Trolleybus
{
public:
    ElectronT19102(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "Електрон Т19102";
    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
};
class Skoda14Tr : public Trolleybus
{
public:
    Skoda14Tr(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "Шкода 14ТР";
    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
};
class BogdanT601 : public Trolleybus
{
public:
    BogdanT601(int in_index, bool on_route = false, int in_year = NAN) : Trolleybus(in_index, on_route, in_year)
    {
        model = "Богдан Т601";
    }
    virtual string get_model()
    {
        return model;
    }
    virtual int get_index()
    {
        return index;
    }
};

class Tram : public Transport
{

};


//-----------------------------------------------------------------------
class Trolleybus_Route;

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
    Station()
    {

    }
    Station(string in_name, double first = 0, double second = 0, string in_type = "BOTH_SIDE")
    {
        name = in_name;
        X = first;
        Y = second;
        type = in_type;

    }
    void station_trolleybuses();
    long double get_X()
    {
        return X;
    }
    long double get_Y()
    {
        return Y;
    }
    string get_name()
    {
        return name;
    }
    vector<Trolleybus*> get_current_trolleybuses()
    {
        return current_trolleybuses;
    }


};
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
    Route(int num)
    {
        number = num;

    }
    virtual void add_stops(vector<Station*> input) = 0;
    int get_number()
    {
        return number;
    }
    virtual void print_route() = 0;
    Station* get_start_point()
    {
        return start;
    }

};
long double find_distance(Trolleybus trolleybus, int target);
class Trolleybus_Route : public Route
{
    friend void renew_nearest_station(Trolleybus* trolleybus);
    friend class Trolleybus;
    friend class Trolleybus_Route_Test;
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
                if(distance < result && distance >= 0)
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

void Station::add_trolleybus(Trolleybus_Route input)
{
    trolleybus_list.push_back(input);
}
class Full_Trolleybus_Route
{
    friend void full_route_renew_both_side(Full_Trolleybus_Route* route, int seconds);
    friend void full_route_renew_final_version(Full_Trolleybus_Route* route, int seconds);
private:
    Trolleybus_Route* front;
    Trolleybus_Route* reverse;
public:
    Full_Trolleybus_Route(Trolleybus_Route* first, Trolleybus_Route* second)
    {
        front = first;
        reverse = second;
    }
    void print_stations_full()
    {
        cout << "Зупинки на маршрутi: " << endl;
        cout << "Прямий маршрут " << endl;
        cout << "-------------------------------" << endl;
        cout << "# " << front->number << " " << front->start->name << "-" << front->end->name << endl;
        cout << "-------------------------------" << endl;
        front->print_route();
        cout << endl;
        cout << "Зворотний маршрут: " << endl;
        cout << "-------------------------------" << endl;
        cout << "# " << front->number << " " << reverse->start->name << "-" << reverse->end->name << endl;
        cout << "-------------------------------" << endl;
        reverse->print_route();
    }
    void print_condition()
    {
        cout << "Тролейбусiв на лiнii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Прямий маршрут " << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < front->stations.size(); i++)
        {
            cout << front->stations[i]->name << " ";
            for (int j = 0; j < front->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(front->active_trolleybuses_list.begin(), front->active_trolleybuses_list.end(), front->stations[i]->current_trolleybuses[j]) != front->active_trolleybuses_list.end())
                {
                    cout << front->stations[i]->current_trolleybuses[j]->get_index() << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << "Зворотний маршрут " << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < reverse->stations.size(); i++)
        {
            cout << reverse->stations[i]->name << " ";
            for (int j = 0; j < reverse->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(reverse->active_trolleybuses_list.begin(), reverse->active_trolleybuses_list.end(), reverse->stations[i]->current_trolleybuses[j]) != reverse->active_trolleybuses_list.end())
                    cout << reverse->stations[i]->current_trolleybuses[j]->get_index() << " ";
            }
            cout << endl;

        }

    }
    void print_condition_with_distances()
    {
        cout << "Тролейбусiв на лiнii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Прямий маршрут " << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < front->stations.size(); i++)
        {
            cout << front->stations[i]->name << " ";
            for (int j = 0; j < front->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(front->active_trolleybuses_list.begin(), front->active_trolleybuses_list.end(), front->stations[i]->current_trolleybuses[j]) != front->active_trolleybuses_list.end())
                {
                    cout << "\033[32m" << front->stations[i]->current_trolleybuses[j]->get_index() << " " "\033[0m";
                }
            }
            cout << front->station_distances[i];
            cout << endl;
        }
        cout << endl;
        cout << "Зворотний маршрут " << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < reverse->stations.size(); i++)
        {
            cout << reverse->stations[i]->name << " ";
            for (int j = 0; j < reverse->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(reverse->active_trolleybuses_list.begin(), reverse->active_trolleybuses_list.end(), reverse->stations[i]->current_trolleybuses[j]) != reverse->active_trolleybuses_list.end())
                    cout << reverse->stations[i]->current_trolleybuses[j]->get_index() << " ";
            }
            cout << endl;

        }

    }
    void print_condition_with_times()
    {
        cout << "Тролейбусiв на лiнii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Прямий маршрут " << endl;
        cout << "-------------------------------" << endl;
        cout << "\033[34m" << "ЗУПИНКА";
        cout << "                   ТРОЛЕЙБУС";
        cout << "           ЧАС ПРИБУТТЯ";
        cout << "           РУХОМИЙ СКЛАД" << "\033[0m" << endl;
        for (int i = 0; i < front->stations.size(); i++)
        {
            string x = front->stations[i]->name;
            cout << front->stations[i]->name << " ";
            int y = 27 - x.size();
            for (int i = 0; i < y; i++)
            {
                cout << " ";
            }
            int counter = 5;
            for (int j = 0; j < front->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(front->active_trolleybuses_list.begin(), front->active_trolleybuses_list.end(), front->stations[i]->current_trolleybuses[j]) != front->active_trolleybuses_list.end())
                {
                    cout << "\033[32m" << front->stations[i]->current_trolleybuses[j]->get_index() << " " << "\033[0m";
                    counter--;
                }
            }
            for (int i = 0; i < counter; i++)
            {
                cout << "    ";
            }
            if (front->station_times[i] > 100000000)
            {
                cout << "\033[31m" << "???" << "\033[0m";
            }
            else if (front->station_times[i] > 1)
            {
                cout << setprecision(2) << front->station_times[i] << " хв";
            }
            else if (front->station_times[i] > 0.5 && front->station_times[i] <= 1)
            {
                cout << "\033[95m" "<1 хв" << "\033[0m";
            }
            else
            {
                cout << "\033[36m" << "ЗАРАЗ" << "\033[0m";
            }
            for (int j = 0; j < front->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(front->active_trolleybuses_list.begin(), front->active_trolleybuses_list.end(), front->stations[i]->current_trolleybuses[j]) != front->active_trolleybuses_list.end())
                {
                    cout << "\033[32m" << "                " << front->stations[i]->current_trolleybuses[j]->get_model() << " " << "\033[0m";
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << "Зворотний маршрут " << endl;
        cout << "-------------------------------" << endl;
        cout << "\033[34m" << "ЗУПИНКА";
        cout << "                   ТРОЛЕЙБУС";
        cout << "           ЧАС ПРИБУТТЯ";
        cout << "           РУХОМИЙ СКЛАД" << "\033[0m" << endl;
        for (int i = 0; i < reverse->stations.size(); i++)
        {
            string a = reverse->stations[i]->name;
            cout << reverse->stations[i]->name << " ";
            int b = 27 - a.size();
            for (int i = 0; i < b; i++)
            {
                cout << " ";
            }
            int counter2 = 5;
            for (int j = 0; j < reverse->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(reverse->active_trolleybuses_list.begin(), reverse->active_trolleybuses_list.end(), reverse->stations[i]->current_trolleybuses[j]) != reverse->active_trolleybuses_list.end())
                {
                    cout << "\033[32m" << reverse->stations[i]->current_trolleybuses[j]->get_index() << "\033[0m" << " ";
                    counter2--;
                }
               
            }
            for (int i = 0; i < counter2; i++)
            {
                cout << "    ";
            }
            if (reverse->station_times[i] > 10000000)
            {
                cout << "\033[31m" << "???" << "\033[0m";
            }
            else if (reverse->station_times[i] > 1)
            {
                cout << reverse->station_times[i] << " хв";
            }
            else if (reverse->station_times[i] > 0.5 && reverse->station_times[i] <= 1)
            {
                cout << "\033[95m" << "<1 хв" << "\033[0m";
            }
            else
            {
                cout << "\033[36m" << "ЗАРАЗ" << "\033[0m";
            }

            

            for (int j = 0; j < reverse->stations[i]->current_trolleybuses.size(); j++)
            {
                if (find(reverse->active_trolleybuses_list.begin(), reverse->active_trolleybuses_list.end(), reverse->stations[i]->current_trolleybuses[j]) != reverse->active_trolleybuses_list.end())
                {
                    cout << "\033[32m" << "                " << reverse->stations[i]->current_trolleybuses[j]->get_model() << "\033[0m" << " ";

                }

            }
            cout << endl;

        }

    }
};


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


void represent_trolleybuses(vector<Trolleybus*> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != nullptr)
        {
            cout << array[i]->get_index() << " " << array[i]->get_model() << " " << array[i]->get_year() << endl;
        }
    }
}
bool operator==(Trolleybus first, Trolleybus second)
{
    return (first.get_index() == second.get_index());
}

long double find_distance(Trolleybus trolleybus, int target)
{
    return (target - trolleybus.get_coordinate());
}
long double find_time(Trolleybus trolleybus, int target)
{
    long double speed_meters_per_minute = trolleybus.get_speed() * 1000 / 60;
    long double result = ((target - trolleybus.get_coordinate()) / speed_meters_per_minute);
    return result;
}
void advance_in_time(Trolleybus* trolleybus, int seconds)
{
    trolleybus->get_coordinate() = trolleybus->get_coordinate() + static_cast<long double>(trolleybus->get_speed()) * 1000 / 3600 * seconds;
    if (trolleybus->get_coordinate() > trolleybus->get_route()->get_length())
    {
        //cout << trolleybus->get_index() << " was sent to the reversed way" << endl;
        int difference = trolleybus->get_coordinate() - trolleybus->get_route()->get_length();
        //cout << "Difference is " << difference << endl;
        //cout << trolleybus->get_route()->get_reversed()->get_start_point()->get_name() << endl;
        trolleybus->sent_to_route(trolleybus->get_route()->get_reversed(), trolleybus->get_route()->get_reversed()->get_start_point());
        renew_nearest_station(trolleybus);
        trolleybus->get_coordinate() = difference;
        trolleybus->get_route()->evaluate_distances_and_times();
        renew_nearest_station(trolleybus);
        //cout << trolleybus->get_nearest_station()->get_name() << endl;
        /*for (Trolleybus* x : trolleybus->get_nearest_station()->current_trolleybuses)
        {
            cout << x->get_index() << " ";
        }
        cout << endl;
        */

      
      
        
    }
    
}
void renew_nearest_station(Trolleybus* trolleybus)
{
    auto it = find(trolleybus->nearest_station->current_trolleybuses.begin(), trolleybus->nearest_station->current_trolleybuses.end(), trolleybus);
    trolleybus->nearest_station->current_trolleybuses.erase(it);
    trolleybus->nearest_station = nullptr;
 
    int result = INF;
    Trolleybus_Route* current = trolleybus->get_route();
    Station* desired = nullptr;
    for (auto it = current->station_points.begin(); it != current->station_points.end(); it++)
    {
        int distance = fabs(trolleybus->get_coordinate() - it->first);
        if (distance < result)
        {
            result = distance;
            desired = it->second;
        }

    }
    trolleybus->nearest_station = desired;
    desired->current_trolleybuses.push_back(trolleybus);
}
void full_route_renew(Trolleybus_Route* route, int seconds)
{
    for (Trolleybus* it : route->active_trolleybuses_list)
    {
        advance_in_time(it, seconds);
        route->evaluate_distances_and_times();
        renew_nearest_station(it);
    }
}
void full_route_renew_both_side(Full_Trolleybus_Route* route, int seconds)
{
    full_route_renew(route->front, seconds);
    full_route_renew(route->reverse, seconds);
}
void full_route_renew_final_version(Full_Trolleybus_Route* route, int seconds)
{
    vector<Trolleybus*> already_moved;
    for (Trolleybus* it : route->front->active_trolleybuses_list)
    {
        if (find(already_moved.begin(), already_moved.end(), it) == already_moved.end())
        {
            advance_in_time(it, seconds);
            route->front->evaluate_distances_and_times();
            renew_nearest_station(it);
            already_moved.push_back(it);
        }
    }
    for (Trolleybus* it : route->reverse->active_trolleybuses_list)
    {
        if (find(already_moved.begin(), already_moved.end(), it) == already_moved.end())
        {
            advance_in_time(it, seconds);
            route->reverse->evaluate_distances_and_times();
            renew_nearest_station(it);
            already_moved.push_back(it);
        }
    }

}
class Trolleybus_Route_Test : public ::testing::Test {
protected:
    Trolleybus_Route* route22 = new Trolleybus_Route(22);
    Trolleybus_Route* route23 = new Trolleybus_Route(23);
    Trolleybus_Route* route24 = new Trolleybus_Route(24);
    Trolleybus_Route* route25 = new Trolleybus_Route(25);
    Trolleybus_Route* route27 = new Trolleybus_Route(27);
    Trolleybus_Route* route30 = new Trolleybus_Route(30);
    Trolleybus_Route* route31 = new Trolleybus_Route(31);
    Trolleybus_Route* route32 = new Trolleybus_Route(32);
    Trolleybus_Route* route33 = new Trolleybus_Route(33);
    Trolleybus_Route* route38 = new Trolleybus_Route(38);
    Trolleybus_Route* route22reverse = new Trolleybus_Route(22);
    Trolleybus_Route* route23reverse = new Trolleybus_Route(23);
    Trolleybus_Route* route24reverse = new Trolleybus_Route(24);
    Trolleybus_Route* route25reverse = new Trolleybus_Route(25);
    Trolleybus_Route* route27reverse = new Trolleybus_Route(27);
    Trolleybus_Route* route30reverse = new Trolleybus_Route(30);
    Trolleybus_Route* route31reverse = new Trolleybus_Route(31);
    Trolleybus_Route* route32reverse = new Trolleybus_Route(32);
    Trolleybus_Route* route33reverse = new Trolleybus_Route(33);
    Trolleybus_Route* route38reverse = new Trolleybus_Route(38);
    

};
class Trolleybus_Test : public Trolleybus_Route_Test
{
    protected:
        Station* University = new Station("Унiверситет");
        Station* St_Ura = new Station("Собор Святого Юра");
        Station* Stepana_Bandery = new Station("Степана Бандери");
        Station* Lypneva = new Station("Площа Липнева");
        Station* Smal_Stockogo = new Station("Смаль-Стоцького");
        Station* Kopystynskogo = new Station("Копистиньского");
        Station* Antonovycha = new Station("Антоновича");
        Station* Kulparkiv = new Station("Кульпаркiв");
        Station* Sknylivok = new Station("Скнилiвок");
        Station* Shyretska = new Station("Щирецька");
        Station* Naukova = new Station("Наукова");
        Station* Symonenka = new Station("Василя Симоненка");
        Station* Science_Club = new Station("Клуб Науковий");
        Station* Emp_Centre = new Station("Центр зайнятостi");
        Station* Kn_Olgy = new Station("Княгинi Ольги");
        Station* Troleybusna = new Station("Тролейбусна");
        Station* Pidstrygacha = new Station("Академiка Пiдстригача");
        Station* Striyska_Naukova = new Station("Стрийська-Наукова");
        Station* Skoryny = new Station("Скорини");
        Station* Hasheka = new Station("Ярослава Гашека");
        Station* Maksymovycha = new Station("Максимовича");
        Station* Bus_Station = new Station("Автовокзал");
        //--------------------------------------------
        Station* Zalizniaka = new Station("Залізняка");
        Station* Melnyka = new Station("Мельника");
        Station* Ustiyanovycha = new Station("Устияновича");

};
TEST_F(Trolleybus_Route_Test, A1) {
    int result = route22->get_number();
    EXPECT_EQ(result, 22);  
}
TEST_F(Trolleybus_Route_Test, A2) {
    int result = route23->get_number();
    EXPECT_EQ(result, 23);
}
TEST_F(Trolleybus_Route_Test, A3) {
    int result = route24->get_number();
    EXPECT_EQ(result, 24);
}
TEST_F(Trolleybus_Route_Test, A4) {
    int result = route25->get_number();
    EXPECT_EQ(result, 25);
}
TEST_F(Trolleybus_Route_Test, A5) {
    int result = route27->get_number();
    EXPECT_EQ(result, 28);
}
TEST_F(Trolleybus_Route_Test, A6) {
    int result = route30->get_number();
    EXPECT_EQ(result, 30);
}
TEST_F(Trolleybus_Route_Test, A7) {
    int result = route32->get_number();
    EXPECT_EQ(result, 32);
}
TEST_F(Trolleybus_Route_Test, B1) {
    route22->set_reversed(route22reverse);
    EXPECT_EQ(route22->get_reversed(), route22reverse);
}
TEST_F(Trolleybus_Route_Test, B2) {
    route25->set_reversed(route25reverse);
    EXPECT_EQ(route25->get_reversed(), route25reverse);
}
TEST_F(Trolleybus_Route_Test, B3) {
    route30->set_reversed(route30reverse);
    EXPECT_EQ(route30->get_reversed(), route22reverse);
}
TEST_F(Trolleybus_Test, C1)
{
    vector<Trolleybus*> trolleybus_array(604);
    for (int i = 0; i < 604; i++)
    {
        trolleybus_array[i] = nullptr;
    }
    for (int i = 101; i <= 110; i++)
    {
        trolleybus_array[i] = new LAZE183(i);
    }
    trolleybus_array[101]->set_year(2006);
    trolleybus_array[103]->set_year(2006);
    trolleybus_array[104]->set_year(2006);
    trolleybus_array[105]->set_year(2006);
    trolleybus_array[107]->set_year(2007);
    trolleybus_array[108]->set_year(2007);
    trolleybus_array[109]->set_year(2007);
    trolleybus_array[110]->set_year(2007);


    trolleybus_array[114] = new ElectronT19101(114);
    trolleybus_array[114]->set_year(2014);
    trolleybus_array[118] = new ElectronT19101(118);
    trolleybus_array[118]->set_year(2016);
    trolleybus_array[111] = new BogdanT601(111);
    trolleybus_array[112] = new BogdanT601(112);
    trolleybus_array[111]->set_year(2008);
    trolleybus_array[112]->set_year(2008);
    for (int i = 115; i <= 117; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2015);
    }
    for (int i = 119; i <= 123; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2016);
    }
    for (int i = 124; i <= 173; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2019);
    }
    trolleybus_array[122]->sent_to_route(route22, St_Ura);
    trolleybus_array[136]->sent_to_route(route22, Sknylivok);
    trolleybus_array[149]->sent_to_route(route22, Naukova);

    trolleybus_array[122]->set_speed(20);
    trolleybus_array[136]->set_speed(20);
    trolleybus_array[149]->set_speed(20);


    route22->evaluate_distances_and_times();
    trolleybus_array[124]->sent_to_route(route22reverse, Bus_Station);
    trolleybus_array[105]->sent_to_route(route22reverse, Ustiyanovycha);
    trolleybus_array[114]->sent_to_route(route22reverse, Kn_Olgy);
    trolleybus_array[105]->set_speed(20);
    trolleybus_array[124]->set_speed(20);
    trolleybus_array[114]->set_speed(20);
    trolleybus_array[163]->sent_to_route(route22, Emp_Centre);
    trolleybus_array[163]->set_speed(20);
    string result = trolleybus_array[124]->get_model();
    EXPECT_EQ(result, "Електрон Т19102");

}
TEST_F(Trolleybus_Test, C2)
{
    vector<Trolleybus*> trolleybus_array(604);
    for (int i = 0; i < 604; i++)
    {
        trolleybus_array[i] = nullptr;
    }
    for (int i = 101; i <= 110; i++)
    {
        trolleybus_array[i] = new LAZE183(i);
    }
    trolleybus_array[101]->set_year(2006);
    trolleybus_array[103]->set_year(2006);
    trolleybus_array[104]->set_year(2006);
    trolleybus_array[105]->set_year(2006);
    trolleybus_array[107]->set_year(2007);
    trolleybus_array[108]->set_year(2007);
    trolleybus_array[109]->set_year(2007);
    trolleybus_array[110]->set_year(2007);


    trolleybus_array[114] = new ElectronT19101(114);
    trolleybus_array[114]->set_year(2014);
    trolleybus_array[118] = new ElectronT19101(118);
    trolleybus_array[118]->set_year(2016);
    trolleybus_array[111] = new BogdanT601(111);
    trolleybus_array[112] = new BogdanT601(112);
    trolleybus_array[111]->set_year(2008);
    trolleybus_array[112]->set_year(2008);
    for (int i = 115; i <= 117; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2015);
    }
    for (int i = 119; i <= 123; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2016);
    }
    for (int i = 124; i <= 173; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2019);
    }
    trolleybus_array[122]->sent_to_route(route22, St_Ura);
    trolleybus_array[136]->sent_to_route(route22, Sknylivok);
    trolleybus_array[149]->sent_to_route(route22, Naukova);

    trolleybus_array[122]->set_speed(20);
    trolleybus_array[136]->set_speed(20);
    trolleybus_array[149]->set_speed(20);


    route22->evaluate_distances_and_times();
    trolleybus_array[124]->sent_to_route(route22reverse, Bus_Station);
    trolleybus_array[105]->sent_to_route(route22reverse, Ustiyanovycha);
    trolleybus_array[114]->sent_to_route(route22reverse, Kn_Olgy);
    trolleybus_array[105]->set_speed(20);
    trolleybus_array[124]->set_speed(20);
    trolleybus_array[114]->set_speed(20);
    trolleybus_array[163]->sent_to_route(route22, Emp_Centre);
    trolleybus_array[163]->set_speed(20);
    string result = trolleybus_array[122]->get_model();
    EXPECT_EQ(result, "Електрон Т19101");

}
TEST_F(Trolleybus_Test, D1)
{
    vector<Trolleybus*> trolleybus_array(604);
    for (int i = 0; i < 604; i++)
    {
        trolleybus_array[i] = nullptr;
    }
    for (int i = 101; i <= 110; i++)
    {
        trolleybus_array[i] = new LAZE183(i);
    }
    trolleybus_array[101]->set_year(2006);
    trolleybus_array[103]->set_year(2006);
    trolleybus_array[104]->set_year(2006);
    trolleybus_array[105]->set_year(2006);
    trolleybus_array[107]->set_year(2007);
    trolleybus_array[108]->set_year(2007);
    trolleybus_array[109]->set_year(2007);
    trolleybus_array[110]->set_year(2007);


    trolleybus_array[114] = new ElectronT19101(114);
    trolleybus_array[114]->set_year(2014);
    trolleybus_array[118] = new ElectronT19101(118);
    trolleybus_array[118]->set_year(2016);
    trolleybus_array[111] = new BogdanT601(111);
    trolleybus_array[112] = new BogdanT601(112);
    trolleybus_array[111]->set_year(2008);
    trolleybus_array[112]->set_year(2008);
    for (int i = 115; i <= 117; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2015);
    }
    for (int i = 119; i <= 123; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2016);
    }
    for (int i = 124; i <= 173; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2019);
    }
    trolleybus_array[122]->sent_to_route(route22, St_Ura);
    trolleybus_array[136]->sent_to_route(route22, Sknylivok);
    trolleybus_array[149]->sent_to_route(route22, Naukova);

    trolleybus_array[122]->set_speed(20);
    trolleybus_array[136]->set_speed(20);
    trolleybus_array[149]->set_speed(20);


    route22->evaluate_distances_and_times();
    trolleybus_array[124]->sent_to_route(route22reverse, Bus_Station);
    trolleybus_array[105]->sent_to_route(route22reverse, Ustiyanovycha);
    trolleybus_array[114]->sent_to_route(route22reverse, Kn_Olgy);
    trolleybus_array[105]->set_speed(20);
    trolleybus_array[124]->set_speed(20);
    trolleybus_array[114]->set_speed(20);
    trolleybus_array[163]->sent_to_route(route22, Emp_Centre);
    trolleybus_array[163]->set_speed(20);
    Trolleybus_Route* result = trolleybus_array[122]->get_route();
    EXPECT_EQ(result, route22);

}
TEST_F(Trolleybus_Test, E1)
{
    vector<Trolleybus*> trolleybus_array(604);
    for (int i = 0; i < 604; i++)
    {
        trolleybus_array[i] = nullptr;
    }
    for (int i = 101; i <= 110; i++)
    {
        trolleybus_array[i] = new LAZE183(i);
    }
    trolleybus_array[101]->set_year(2006);
    trolleybus_array[103]->set_year(2006);
    trolleybus_array[104]->set_year(2006);
    trolleybus_array[105]->set_year(2006);
    trolleybus_array[107]->set_year(2007);
    trolleybus_array[108]->set_year(2007);
    trolleybus_array[109]->set_year(2007);
    trolleybus_array[110]->set_year(2007);


    trolleybus_array[114] = new ElectronT19101(114);
    trolleybus_array[114]->set_year(2014);
    trolleybus_array[118] = new ElectronT19101(118);
    trolleybus_array[118]->set_year(2016);
    trolleybus_array[111] = new BogdanT601(111);
    trolleybus_array[112] = new BogdanT601(112);
    trolleybus_array[111]->set_year(2008);
    trolleybus_array[112]->set_year(2008);
    for (int i = 115; i <= 117; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2015);
    }
    for (int i = 119; i <= 123; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2016);
    }
    for (int i = 124; i <= 173; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2019);
    }
    trolleybus_array[122]->sent_to_route(route22, St_Ura);
    trolleybus_array[136]->sent_to_route(route22, Sknylivok);
    trolleybus_array[149]->sent_to_route(route22, Naukova);

    trolleybus_array[122]->set_speed(20);
    trolleybus_array[136]->set_speed(20);
    trolleybus_array[149]->set_speed(20);


    route22->evaluate_distances_and_times();
    trolleybus_array[124]->sent_to_route(route22reverse, Bus_Station);
    trolleybus_array[105]->sent_to_route(route22reverse, Ustiyanovycha);
    trolleybus_array[114]->sent_to_route(route22reverse, Kn_Olgy);
    trolleybus_array[105]->set_speed(20);
    trolleybus_array[124]->set_speed(20);
    trolleybus_array[114]->set_speed(20);
    trolleybus_array[163]->sent_to_route(route22, Emp_Centre);
    trolleybus_array[163]->set_speed(20);
    Station* result = trolleybus_array[122]->get_nearest_station();
    EXPECT_EQ(result, Sknylivok);

}
int main(int argc, char** argv)
{


    setlocale(LC_CTYPE, "ukr");
    //Front routes
    Trolleybus_Route* route22 = new Trolleybus_Route(22);
    Trolleybus_Route* route23 = new Trolleybus_Route(23);
    Trolleybus_Route* route24 = new Trolleybus_Route(24);
    Trolleybus_Route* route25 = new Trolleybus_Route(25);
    Trolleybus_Route* route27 = new Trolleybus_Route(27);
    Trolleybus_Route* route30 = new Trolleybus_Route(30);
    Trolleybus_Route* route31 = new Trolleybus_Route(31);
    Trolleybus_Route* route32 = new Trolleybus_Route(32);
    Trolleybus_Route* route33 = new Trolleybus_Route(33);
    Trolleybus_Route* route38 = new Trolleybus_Route(38);
    //Reversed routes
    Trolleybus_Route* route22reverse = new Trolleybus_Route(22);
    Trolleybus_Route* route23reverse = new Trolleybus_Route(23);
    Trolleybus_Route* route24reverse = new Trolleybus_Route(24);
    Trolleybus_Route* route25reverse = new Trolleybus_Route(25);
    Trolleybus_Route* route27reverse = new Trolleybus_Route(27);
    Trolleybus_Route* route30reverse = new Trolleybus_Route(30);
    Trolleybus_Route* route31reverse = new Trolleybus_Route(31);
    Trolleybus_Route* route32reverse = new Trolleybus_Route(32);
    Trolleybus_Route* route33reverse = new Trolleybus_Route(33);
    Trolleybus_Route* route38reverse = new Trolleybus_Route(38);
    route22->set_reversed(route22reverse);
    route22reverse->set_reversed(route22);
    route23->set_reversed(route23reverse);
    route23reverse->set_reversed(route23);
    route24->set_reversed(route24reverse);
    route24reverse->set_reversed(route24);
    route25->set_reversed(route25reverse);
    route25reverse->set_reversed(route25);
    route27->set_reversed(route27reverse);
    route27reverse->set_reversed(route27);
    route30->set_reversed(route30reverse);
    route30reverse->set_reversed(route30);
    route31->set_reversed(route31reverse);
    route31reverse->set_reversed(route31);
    route32->set_reversed(route32reverse);
    route32reverse->set_reversed(route32);
    route33->set_reversed(route33reverse);
    route33reverse->set_reversed(route33);
    route38->set_reversed(route38reverse);
    route38reverse->set_reversed(route38);




    //Full routes
    Full_Trolleybus_Route* route22_full = new Full_Trolleybus_Route(route22, route22reverse);
    Full_Trolleybus_Route* route23_full = new Full_Trolleybus_Route(route23, route23reverse);
    Full_Trolleybus_Route* route24_full = new Full_Trolleybus_Route(route24, route24reverse);
    Full_Trolleybus_Route* route25_full = new Full_Trolleybus_Route(route25, route25reverse);
    Full_Trolleybus_Route* route27_full = new Full_Trolleybus_Route(route27, route27reverse);
    Full_Trolleybus_Route* route30_full = new Full_Trolleybus_Route(route30, route30reverse);
    Full_Trolleybus_Route* route31_full = new Full_Trolleybus_Route(route31, route31reverse);
    Full_Trolleybus_Route* route32_full = new Full_Trolleybus_Route(route32, route32reverse);
    Full_Trolleybus_Route* route33_full = new Full_Trolleybus_Route(route33, route33reverse);
    Full_Trolleybus_Route* route38_full = new Full_Trolleybus_Route(route38, route38reverse);
    //Stations

    //Тролейбус 22
    Station* University = new Station("Унiверситет");
    Station* St_Ura = new Station("Собор Святого Юра");
    Station* Stepana_Bandery = new Station("Степана Бандери");
    Station* Lypneva = new Station("Площа Липнева");
    Station* Smal_Stockogo = new Station("Смаль-Стоцького");
    Station* Kopystynskogo = new Station("Копистиньского");
    Station* Antonovycha = new Station("Антоновича");
    Station* Kulparkiv = new Station("Кульпаркiв");
    Station* Sknylivok = new Station("Скнилiвок");
    Station* Shyretska = new Station("Щирецька");
    Station* Naukova = new Station("Наукова");
    Station* Symonenka = new Station("Василя Симоненка");
    Station* Science_Club = new Station("Клуб Науковий");
    Station* Emp_Centre = new Station("Центр зайнятостi");
    Station* Kn_Olgy = new Station("Княгинi Ольги");
    Station* Troleybusna = new Station("Тролейбусна");
    Station* Pidstrygacha = new Station("Академiка Пiдстригача");
    Station* Striyska_Naukova = new Station("Стрийська-Наукова");
    Station* Skoryny = new Station("Скорини");
    Station* Hasheka = new Station("Ярослава Гашека");
    Station* Maksymovycha = new Station("Максимовича");
    Station* Bus_Station = new Station("Автовокзал");
    //--------------------------------------------
    Station* Zalizniaka = new Station("Залізняка");
    Station* Melnyka = new Station("Мельника");
    Station* Ustiyanovycha = new Station("Устияновича");

    vector<Station*> list22 = { University, St_Ura, Stepana_Bandery, Lypneva, Smal_Stockogo,
        Kopystynskogo, Antonovycha, Kulparkiv, Sknylivok, Shyretska, Naukova, Symonenka, Science_Club,
        Emp_Centre, Kn_Olgy, Troleybusna, Pidstrygacha, Striyska_Naukova, Skoryny, Hasheka, Maksymovycha, Bus_Station };
    vector<int> distances22 = { 0, 1020, 1470, 1870, 2390, 2770, 3080, 4000, 4580, 5150, 5570, 6030, 6360, 6680, 6870, 7397, 7750, 8300, 8670, 9100, 9400, 9900 };
    route22->add_stops(list22);
    route22->organize_stops(list22, distances22);

    vector<Station*> list22reverse = { University,Ustiyanovycha, St_Ura, Stepana_Bandery, Melnyka, Zalizniaka,
        Antonovycha, Kulparkiv, Sknylivok, Shyretska, Naukova, Symonenka, Science_Club,
        Emp_Centre, Kn_Olgy, Troleybusna, Pidstrygacha, Striyska_Naukova, Skoryny, Hasheka, Maksymovycha, Bus_Station };
    vector<int> distances22reverse = { 0, 510, 760, 1000, 1380, 1900, 2170, 2690, 3150, 3460, 3680, 4110, 4670, 5340, 6000, 6870, 7500, 7870, 8340, 8850, 9200, 9950 };
    reverse(list22reverse.begin(), list22reverse.end());
    route22reverse->add_stops(list22reverse);
    route22reverse->organize_stops(list22reverse, distances22reverse);
    //Тролейбус 23
    Station* Bodnarivka = new Station("Боднарiвка");
    Station* Rubchaka = new Station("Рубчака");
    Station* Trolleybus_Depaut = new Station("Тролейбусне депо");
    Station* Com_College = new Station("Коледж Комунiкацій");
    Station* Volodymyra_Velykogo = new Station("Володимира Великого");
    Station* Ocean = new Station("ТРЦ Океан");
    Station* Botkina = new Station("Боткiна");
    Station* Pivd_Market = new Station("Пiвденний ринок");
    Station* Sknyliv_Park = new Station("Скнилiвський парк");
    Station* Lubinska_Vygovskogo = new Station("Любiнська-Виговського");
    Station* Railway_Adm = new Station("Залiзнична райадмiнiстрaцiя");
    Station* Patona = new Station("Патона");
    Station* Lorta = new Station("Лорта");
    Station* Riashivska = new Station("Ряшiвська");
    vector<Station*> list23 = { Bus_Station, Maksymovycha,  Hasheka, Skoryny, Striyska_Naukova, Bodnarivka, Rubchaka, Trolleybus_Depaut,
    Com_College, Volodymyra_Velykogo, Ocean, Botkina, Sknylivok, Pivd_Market, Sknyliv_Park, Lubinska_Vygovskogo, Railway_Adm,
    Patona, Lorta, Riashivska };
    vector<int> distances23 = { 0, 510, 760, 1000, 1167, 1835, 2200, 2600, 3080, 3360, 3810, 4070, 4570, 5180, 5660, 6080, 6490, 7000, 7310, 7680, 8120 };
    route23->organize_stops(list23, distances23);
    route23->add_stops(list23);
    reverse(list23.begin(), list23.end());
    route23reverse->add_stops(list23);
    route23reverse->organize_stops(list23, distances23);
    //Тролейбус24
    Station* Shota_Rustaveli = new Station("Шота Руставелi");
    Station* Vahylevycha = new Station("Вагилевича");
    Station* LvivCanal = new Station("ЛьвiвВодоканал");
    Station* Vodoginna = new Station("Водогiнна");
    Station* Kerchenska = new Station("Керченська");
    Station* Lypova_Alley = new Station("Липова Алея");
    Station* Dnisterska = new Station("Днiстерська");
    Station* Buzkova = new Station("Бузкова");
    Station* Frezer_Factory = new Station("Фрезерний завод");
    Station* Bus_Station5 = new Station("Автостанцiя №5");
    Station* DBK = new Station("ДБК");
    Station* Zubrivska = new Station("Зубрiвська");
    Station* Sykhivska = new Station("Сихiвська");
    Station* Kavaleridze = new Station("Кавалерiдзе");
    Station* Dovzhenka_Centre = new Station("Центр Довженка");
    Station* Sykhiv_Adm = new Station("Сихiвська райадмiнiстрацiя");
    Station* Kolomiyska = new Station("Коломийська");
    Station* Santa_Barbara = new Station("Санта Барбара");
    //-------------------------------------
    Station* Policlinic4 = new Station("Полiклiнiка №4");
    vector<Station*> list24 = { Shota_Rustaveli, Vahylevycha, LvivCanal, Vodoginna, Kerchenska, Lypova_Alley, Dnisterska, Buzkova,
    Frezer_Factory, Bus_Station5, DBK, Zubrivska, Sykhivska, Kavaleridze, Dovzhenka_Centre, Sykhiv_Adm, Kolomiyska, Santa_Barbara };
    vector<Station*> list24reverse = { Shota_Rustaveli, Policlinic4, Vahylevycha, LvivCanal, Vodoginna, Kerchenska, Lypova_Alley, Dnisterska, Buzkova,
    Frezer_Factory, Bus_Station5, DBK, Zubrivska, Sykhivska, Kavaleridze, Dovzhenka_Centre, Sykhiv_Adm, Kolomiyska, Santa_Barbara };
    vector<int> distances24 = { 0,420, 670, 840, 1440, 1950, 2300, 3000, 3440, 3540, 4200, 4460, 4700, 5000, 5600, 6320, 6850, 7300, 7600, 8030 };
    reverse(list24reverse.begin(), list24reverse.end());
    route24->add_stops(list24);
    route24->organize_stops(list24, distances24);
    vector<int> distances24reverse = {};

    route24reverse->add_stops(list24reverse);
    //Тролейбус 25
    Station* Bus_Factory = new Station("Автобусний завод");
    Station* Tax_Administration = new Station("Податкова адмiнiстрацiя");
    Station* Children_Railway = new Station("Дитяча залiзниця");
    Station* War_Academy = new Station("Академiя сухопутних вiйськ");
    Station* StriyMarket = new Station("Стрийський ринок");
    Station* Petrushevycha = new Station("Петрушевича");
    vector<Station*> list25 = { Bus_Station, Maksymovycha, Hasheka, Skoryny, Striyska_Naukova, Bus_Factory, Tax_Administration,
    Children_Railway, War_Academy, StriyMarket, Petrushevycha, Shota_Rustaveli };
    vector<Station*> list25reverse = { Bus_Station, Maksymovycha, Hasheka, Skoryny, Striyska_Naukova, Bus_Factory, Tax_Administration,
    Children_Railway, War_Academy, StriyMarket, Shota_Rustaveli };
    route25->add_stops(list25);
    reverse(list25reverse.begin(), list25reverse.end());
    route25reverse->add_stops(list25reverse);
    //Тролейбус30
    Station* SilMash = new Station("Стадiон Сiльмаш");
    Station* Okruzhna = new Station("Окружна");
    Station* Furniture_House = new Station("Будинок меблiв");
    Station* Karadzhycha = new Station("Караджича");
    vector<Station*> list30 = { University, St_Ura, Stepana_Bandery, Lypneva, Smal_Stockogo,
    Kopystynskogo, SilMash, Okruzhna, Furniture_House, Karadzhycha, Railway_Adm,
    Patona, Lorta, Riashivska };
    route30->add_stops(list30);
    vector<Station*> list30reverse = { University, Ustiyanovycha, St_Ura, Stepana_Bandery, Melnyka, Zalizniaka,
    Antonovycha,Okruzhna,Furniture_House,Karadzhycha,Railway_Adm,
    Patona,Lorta,Riashivska };
    reverse(list30reverse.begin(), list30reverse.end());
    route30reverse->add_stops(list30reverse);
    //Тролейбус32
    Station* Kropyvnytskogo = new Station("Площа Кропивницького");
    Station* Pre_Station = new Station("Привокзальний ринок");
    Station* Skrynia = new Station("ТРЦ Скриня");
    Station* Kulparkivska = new Station("Кульпаркiвська");
    Station* Narodna = new Station("Народна");
    Station* Siayvo = new Station("Сяйво");
    Station* Shyroka = new Station("Широка");
    Station* Nyzynna = new Station("Низинна");
    Station* Hnizdovskogo = new Station("Гнiздовського");
    Station* Policlinic3 = new Station("Полiклiнiка №3");
    Station* Subotivska = new Station("Суботiвська");
    Station* Tobilevycha = new Station("Тобiлевича");
    vector<Station*> list32 = { University, St_Ura, Kropyvnytskogo, Pre_Station, Skrynia, Kulparkivska, Narodna, Siayvo, Shyroka,
    Nyzynna, Hnizdovskogo, Policlinic3, Subotivska };
    route32->add_stops(list32);
    vector<Station*> list32reverse = { University, St_Ura, Kropyvnytskogo, Tobilevycha, Pre_Station, Skrynia, Kulparkivska, Narodna, Siayvo, Shyroka,
    Nyzynna, Hnizdovskogo, Policlinic3, Subotivska };
    reverse(list32reverse.begin(), list32reverse.end());
    route32reverse->add_stops(list32reverse);
    //Тролейбус33
    Station* Pidkovy = new Station("Площа Iвана Пiдкови");
    Station* Chornovola = new Station("В'ячеслава Чорновола");
    Station* Hotkevycha = new Station("Палац Хоткевича");
    Station* Khimichna = new Station("Хiмiчна");
    Station* ShevchenkoAdm = new Station("Шевченкiвська райадмiнiстрацiя");
    Station* Park700year = new Station("Парк 700-рiччя Львова");
    Station* Varshavska = new Station("Варшавська");
    Station* Holosko = new Station("Голоско");
    Station* Mazepy = new Station("Гетьмана Мазепи");
    Station* Orlyka = new Station("Пилипа Орлика");
    Station* Hospital = new Station("Лiкарня швидкої допомоги");
    Station* Pluhova = new Station("Плугова");
    Station* Hrinchenka = new Station("Грiнченка");
    Station* Zamarstyniv = new Station("Замарстинiв");
    Station* OperaTheatre = new Station("Театр опери та балету");
    vector<Station*> list33 = { Pidkovy, Chornovola, Hotkevycha, Khimichna, ShevchenkoAdm, Park700year, Varshavska, Holosko, Mazepy,
    Orlyka, Hospital, Pluhova, Hrinchenka };
    vector<Station*> list33reverse = { Pidkovy, OperaTheatre, Chornovola, Hotkevycha, Khimichna, ShevchenkoAdm, Park700year, Varshavska, Holosko,Zamarstyniv, Mazepy,
    Orlyka, Hospital, Pluhova, Hrinchenka };
    route33->add_stops(list33);
    reverse(list33reverse.begin(), list33reverse.end());
    route33reverse->add_stops(list33reverse);
    //Тролейбус 38
    Station* Cardiologic_Centre = new Station("Кардiологiчний центр");
    Station* Demnianska = new Station("Демнянська");
    Station* Dukhovna_Seminary = new Station("Духовна семiнарiя");
    Station* Chuckarina = new Station("Чукарiна");
    Station* Khutorivka = new Station("Хуторiвка");
    vector<Station*> list38 = { Kropyvnytskogo, Pre_Station, Skrynia, Kulparkivska, Cardiologic_Centre, Antonovycha, Kulparkiv,
    Sknylivok, Botkina, Ocean, Volodymyra_Velykogo, Trolleybus_Depaut, Rubchaka, Bodnarivka, Striyska_Naukova, Demnianska,
    Dukhovna_Seminary, Chuckarina, Khutorivka };
    route38->add_stops(list38);
    vector<Station*> list38reverse = { Kropyvnytskogo, Tobilevycha, Pre_Station, Skrynia, Kulparkivska, Cardiologic_Centre, Antonovycha, Kulparkiv,
    Sknylivok, Botkina, Ocean, Volodymyra_Velykogo, Trolleybus_Depaut, Rubchaka, Bodnarivka, Striyska_Naukova, Demnianska,
    Dukhovna_Seminary, Chuckarina, Khutorivka };
    reverse(list38reverse.begin(), list38reverse.end());
    route38reverse->add_stops(list38reverse);
    //Тролейбус 27
    Station* Bohdanivka = new Station("Богданiвка");
    Station* Motozavod = new Station("Мотозавод");
    Station* Vivsiana = new Station("Вiвсяна");
    Station* Vilhova = new Station("Вiльхова");
    Station* Kakhovska = new Station("Каховська");
    Station* Kurmanovycha = new Station("Курмановича");
    Station* Sknyliv = new Station("Скнилiв");
    Station* Aviatsiyna = new Station("Авiацiйна");
    vector<Station*> list27 = { University, St_Ura, Kropyvnytskogo, Pre_Station, Skrynia, Kulparkivska, Narodna, Bohdanivka, Motozavod, Vivsiana,
    Vilhova, Kakhovska, Kurmanovycha, Sknyliv };
    route27->add_stops(list27);
    vector<Station*> list27reverse = { University, Ustiyanovycha, St_Ura, Kropyvnytskogo,Tobilevycha, Pre_Station, Skrynia, Kulparkivska, Narodna, Bohdanivka, Motozavod, Vivsiana,
    Vilhova, Kakhovska, Kurmanovycha, Aviatsiyna, Sknyliv };
    reverse(list27reverse.begin(), list27reverse.end());
    route27reverse->add_stops(list27reverse);
    //Тролейбус 31
    Station* OldSykhiv = new Station("Старий Сихiв");
    Station* Station_Sykhiv = new Station("Станція Сихів");
    Station* Pasiky_Zubrytski = new Station("Пасіки-Зубрицькі");
    Station* Sykhiv_semetery = new Station("Сихівський цвинтар");
    Station* Pulmonologic_Centre = new Station("Пульмонологічний центр");
    vector<Station*> list31 = { Shota_Rustaveli, Vahylevycha, LvivCanal, Vodoginna, Kerchenska, Lypova_Alley, Dnisterska, Buzkova,
    Frezer_Factory, Bus_Station5, DBK, Zubrivska, Sykhivska, OldSykhiv, Station_Sykhiv, Pasiky_Zubrytski, Sykhiv_semetery, Pulmonologic_Centre };
    route31->add_stops(list31);
    vector<Station*> list31reverse = { Shota_Rustaveli, Vahylevycha, LvivCanal, Vodoginna, Kerchenska, Lypova_Alley, Dnisterska, Buzkova,
    Frezer_Factory, Bus_Station5, DBK, Zubrivska, Sykhivska, OldSykhiv, Station_Sykhiv, Pasiky_Zubrytski, Pulmonologic_Centre };
    reverse(list31reverse.begin(), list31reverse.end());

    route31reverse->add_stops(list31reverse);
    //TROLLEYBUSES
    vector<Trolleybus*> trolleybus_array(604);
    for (int i = 0; i < 604; i++)
    {
        trolleybus_array[i] = nullptr;
    }
    for (int i = 101; i <= 110; i++)
    {
        trolleybus_array[i] = new LAZE183(i);
    }
    trolleybus_array[101]->set_year(2006);
    trolleybus_array[103]->set_year(2006);
    trolleybus_array[104]->set_year(2006);
    trolleybus_array[105]->set_year(2006);
    trolleybus_array[107]->set_year(2007);
    trolleybus_array[108]->set_year(2007);
    trolleybus_array[109]->set_year(2007);
    trolleybus_array[110]->set_year(2007);


    trolleybus_array[114] = new ElectronT19101(114);
    trolleybus_array[114]->set_year(2014);
    trolleybus_array[118] = new ElectronT19101(118);
    trolleybus_array[118]->set_year(2016);
    trolleybus_array[111] = new BogdanT601(111);
    trolleybus_array[112] = new BogdanT601(112);
    trolleybus_array[111]->set_year(2008);
    trolleybus_array[112]->set_year(2008);
    for (int i = 115; i <= 117; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2015);
    }
    for (int i = 119; i <= 123; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2016);
    }
    for (int i = 124; i <= 173; i++)
    {
        trolleybus_array[i] = new ElectronT19102(i);
        trolleybus_array[i]->set_year(2019);
    }
    trolleybus_array[122]->sent_to_route(route22, St_Ura);
    trolleybus_array[136]->sent_to_route(route22, Sknylivok);
    trolleybus_array[149]->sent_to_route(route22, Naukova);

    trolleybus_array[122]->set_speed(20);
    trolleybus_array[136]->set_speed(20);
    trolleybus_array[149]->set_speed(20);


    route22->evaluate_distances_and_times();
    trolleybus_array[124]->sent_to_route(route22reverse, Bus_Station);
    trolleybus_array[105]->sent_to_route(route22reverse, Ustiyanovycha);
    trolleybus_array[114]->sent_to_route(route22reverse, Kn_Olgy);
    trolleybus_array[105]->set_speed(20);
    trolleybus_array[124]->set_speed(20);
    trolleybus_array[114]->set_speed(20);
    trolleybus_array[163]->sent_to_route(route22, Emp_Centre);
    trolleybus_array[163]->set_speed(20);
    route22->evaluate_distances_and_times();
    route22reverse->evaluate_distances_and_times();
    //route22_full->print_condition_with_distances();
    //cout << trolleybus_array[122]->get_coordinate() << endl;
    //cout << trolleybus_array[136]->get_coordinate() << endl;
    //cout << find_distance(*trolleybus_array[122], 1415);
    route22_full->print_condition_with_times();
    //advance_in_time(trolleybus_array[122], 400);
    //route22->evaluate_distances_and_times();
    //renew_nearest_station(trolleybus_array[122]);
    full_route_renew_final_version(route22_full, 600);
    trolleybus_array[129]->sent_to_route(route22, Stepana_Bandery);
    trolleybus_array[129]->set_speed(15);
    trolleybus_array[111]->set_speed(16);
    trolleybus_array[111]->sent_to_route(route22reverse, Zalizniaka);
    route22->evaluate_distances_and_times();
    route22reverse->evaluate_distances_and_times();
    route22_full->print_condition_with_times();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
    


  
    
    
  


    
    

    
 





   































}



