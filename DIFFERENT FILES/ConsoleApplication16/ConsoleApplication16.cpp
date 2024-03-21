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














long double find_distance(Trolleybus trolleybus, int target);





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


int main()
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
    route23->add_stops(list23);
    reverse(list23.begin(), list23.end());
    route23reverse->add_stops(list23);
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
    reverse(list24reverse.begin(), list24reverse.end());
    route24->add_stops(list24);
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
    full_route_renew_final_version(route22_full, 720);
    route22_full->print_condition_with_times();
    
    
    


  
    
    
  


    
    

    
 





   































}



