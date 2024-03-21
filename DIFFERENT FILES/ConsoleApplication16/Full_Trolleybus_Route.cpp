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
    Full_Trolleybus_Route::Full_Trolleybus_Route(Trolleybus_Route* first, Trolleybus_Route* second)
    {
        front = first;
        reverse = second;
    }
    void Full_Trolleybus_Route::print_stations_full()
    {
        cout << "Çóïèíêè íà ìàðøðóòi: " << endl;
        cout << "Ïðÿìèé ìàðøðóò " << endl;
        cout << "-------------------------------" << endl;
        cout << "# " << front->number << " " << front->start->name << "-" << front->end->name << endl;
        cout << "-------------------------------" << endl;
        front->print_route();
        cout << endl;
        cout << "Çâîðîòíèé ìàðøðóò: " << endl;
        cout << "-------------------------------" << endl;
        cout << "# " << front->number << " " << reverse->start->name << "-" << reverse->end->name << endl;
        cout << "-------------------------------" << endl;
        reverse->print_route();
    }
    void Full_Trolleybus_Route::print_condition()
    {
        cout << "Òðîëåéáóñiâ íà ëiíii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Ïðÿìèé ìàðøðóò " << endl;
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
        cout << "Çâîðîòíèé ìàðøðóò " << endl;
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
    void Full_Trolleybus_Route::print_condition_with_distances()
    {
        cout << "Òðîëåéáóñiâ íà ëiíii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Ïðÿìèé ìàðøðóò " << endl;
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
        cout << "Çâîðîòíèé ìàðøðóò " << endl;
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
    void Full_Trolleybus_Route::print_condition_with_times()
    {
        cout << "Òðîëåéáóñiâ íà ëiíii: " << front->active_trolleybuses_list.size() + reverse->active_trolleybuses_list.size() << endl;
        cout << "Ïðÿìèé ìàðøðóò " << endl;
        cout << "-------------------------------" << endl;
        cout << "\033[34m" << "ÇÓÏÈÍÊÀ";
        cout << "                   ÒÐÎËÅÉÁÓÑ";
        cout << "           ×ÀÑ ÏÐÈÁÓÒÒß";
        cout << "           ÐÓÕÎÌÈÉ ÑÊËÀÄ" << "\033[0m" << endl;
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
                cout << setprecision(2) << front->station_times[i] << " õâ";
            }
            else if (front->station_times[i] > 0.5 && front->station_times[i] <= 1)
            {
                cout << "\033[95m" "<1 õâ" << "\033[0m";
            }
            else
            {
                cout << "\033[36m" << "ÇÀÐÀÇ" << "\033[0m";
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
        cout << "Çâîðîòíèé ìàðøðóò " << endl;
        cout << "-------------------------------" << endl;
        cout << "\033[34m" << "ÇÓÏÈÍÊÀ";
        cout << "                   ÒÐÎËÅÉÁÓÑ";
        cout << "           ×ÀÑ ÏÐÈÁÓÒÒß";
        cout << "           ÐÓÕÎÌÈÉ ÑÊËÀÄ" << "\033[0m" << endl;
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
                cout << reverse->station_times[i];
            }
            else if (reverse->station_times[i] > 0.5 && reverse->station_times[i] <= 1)
            {
                cout << "\033[95m" << "<1 õâ" << "\033[0m";
            }
            else
            {
                cout << "\033[36m" << "ÇÀÐÀÇ" << "\033[0m";
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
