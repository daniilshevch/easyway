#include "trolleybus_list.h"
#include "ui_trolleybus_list.h"
#include <QPixmap>
#include <QTableView>
#include <QStandardItemModel>
#include <algorithm>
#include <QString>
#include <QList>
#include <QVector>
#include <QIcon>
#include <algorithm>
#include <QRandomGenerator>
#include <QMessageBox>
class Trolleybus;
class Trolleybus_Route
{
public:
    int number;
    QVector<Trolleybus*> current_trolleybus_list;

    Trolleybus_Route(int n)
    {
        number = n;
    }
};

class Station
{
public:
    QString name;
    Trolleybus* current_trolleybus;
    Station(QString n)
    {
        name = n;
        current_trolleybus = nullptr;
    }

};
QVector<Trolleybus*> trolleybus_array(600);
class Trolleybus
{
public:
    QString model;
    int index;
    Trolleybus_Route* current_route;
    Station* current_station;
public:
    Trolleybus(QString mod, int ind)
    {
        model = mod;
        current_route = nullptr;
        current_station = nullptr;
        index = ind;
    }

    void sent_to_route(Trolleybus_Route* current, Station* stat)
    {
        current_route = current;
        current_station = stat;
        current->current_trolleybus_list.append(this);
        stat->current_trolleybus = this;
    }
};
trolleybus_list::trolleybus_list(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus_list)
{
    ui->setupUi(this);
    QPixmap picture2(":/img/images/zx2rav---c1200x630x50px50p-up--b1292c38d0da322aafd72480bc14d14a.jpg");
    ui->image2->setPixmap(picture2.scaled(ui->image2->width(), ui->image2->height(), Qt::KeepAspectRatio));

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
    Station* Bus_Factory = new Station("Автобусний завод");
    Station* Tax_Administration = new Station("Податкова адмiнiстрацiя");
    Station* Children_Railway = new Station("Дитяча залiзниця");
    Station* War_Academy = new Station("Академiя сухопутних вiйськ");
    Station* StriyMarket = new Station("Стрийський ринок");
    Station* Petrushevycha = new Station("Петрушевича");
    Station* SilMash = new Station("Стадiон Сiльмаш");
    Station* Okruzhna = new Station("Окружна");
    Station* Furniture_House = new Station("Будинок меблiв");
    Station* Karadzhycha = new Station("Караджича");
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
    Station* Cardiologic_Centre = new Station("Кардiологiчний центр");
    Station* Demnianska = new Station("Демнянська");
    Station* Dukhovna_Seminary = new Station("Духовна семiнарiя");
    Station* Chuckarina = new Station("Чукарiна");
    Station* Khutorivka = new Station("Хуторiвка");
    Station* Bohdanivka = new Station("Богданiвка");
    Station* Motozavod = new Station("Мотозавод");
    Station* Vivsiana = new Station("Вiвсяна");
    Station* Vilhova = new Station("Вiльхова");
    Station* Kakhovska = new Station("Каховська");
    Station* Kurmanovycha = new Station("Курмановича");
    Station* Sknyliv = new Station("Скнилiв");
    Station* Aviatsiyna = new Station("Авiацiйна");
    Station* OldSykhiv = new Station("Старий Сихiв");
    Station* Station_Sykhiv = new Station("Станція Сихів");
    Station* Pasiky_Zubrytski = new Station("Пасіки-Зубрицькі");
    Station* Sykhiv_semetery = new Station("Сихівський цвинтар");
    Station* Pulmonologic_Centre = new Station("Пульмонологічний центр");


    //trolleybus22
    Trolleybus_Route* route22 = new Trolleybus_Route(22);
    Trolleybus_Route* route22_reverse = new Trolleybus_Route(22);
    Trolleybus_Route* route23 = new Trolleybus_Route(23);
    Trolleybus_Route* route23_reverse = new Trolleybus_Route(23);
    Trolleybus_Route* route24 = new Trolleybus_Route(24);
    Trolleybus_Route* route24_reverse = new Trolleybus_Route(24);
    Trolleybus_Route* route25 = new Trolleybus_Route(25);
    Trolleybus_Route* route25_reverse = new Trolleybus_Route(25);
    Trolleybus_Route* route30 = new Trolleybus_Route(30);
    Trolleybus_Route* route30_reverse = new Trolleybus_Route(30);
    Trolleybus_Route* route32 = new Trolleybus_Route(32);
    Trolleybus_Route* route32_reverse = new Trolleybus_Route(32);
    Trolleybus_Route* route33 = new Trolleybus_Route(33);
    Trolleybus_Route* route33_reverse = new Trolleybus_Route(33);
    Trolleybus_Route* route38 = new Trolleybus_Route(38);
    Trolleybus_Route* route38_reverse = new Trolleybus_Route(38);
    trolleybus_array[123] = new Trolleybus("ELECTRON T19102", 123);
    trolleybus_array[139] = new Trolleybus("ELECTRON T19102", 139);
    trolleybus_array[114] = new Trolleybus("ELECTRON T19101", 114);
    trolleybus_array[118] = new Trolleybus("ELECTRON T19101", 118);
    trolleybus_array[105] = new Trolleybus("LAZ E183", 105);
    trolleybus_array[172] = new Trolleybus("ELECTRON T19102", 172);
    trolleybus_array[133] = new Trolleybus("ELECTRON T19102", 133);
    trolleybus_array[154] = new Trolleybus("ELECTRON T19102", 154);
    trolleybus_array[558] = new Trolleybus("SKODA TR13", 558);
    trolleybus_array[122] = new Trolleybus("ELECTRON T19102", 122);
    trolleybus_array[138] = new Trolleybus("ELECTRON T19102", 138);
    trolleybus_array[135] = new Trolleybus("ELECTRON T19102", 135);

    trolleybus_array[123]->sent_to_route(route22, Kulparkiv);
    trolleybus_array[139]->sent_to_route(route22, St_Ura);
    trolleybus_array[114]->sent_to_route(route22, Smal_Stockogo);
    trolleybus_array[118]->sent_to_route(route22, Antonovycha);
    trolleybus_array[105]->sent_to_route(route22, Symonenka);
    trolleybus_array[172]->sent_to_route(route22, Skoryny);
    trolleybus_array[133]->sent_to_route(route22_reverse, Striyska_Naukova);
    trolleybus_array[154]->sent_to_route(route22_reverse, Kn_Olgy);
    trolleybus_array[558]->sent_to_route(route22_reverse, Naukova);
    trolleybus_array[122]->sent_to_route(route22_reverse, Sknylivok);
    trolleybus_array[138]->sent_to_route(route22_reverse, Melnyka);
    trolleybus_array[135]->sent_to_route(route22_reverse, University);
    //trolleybus23
    trolleybus_array[137] = new Trolleybus("ELECTRON T19102", 137);
    trolleybus_array[116]= new Trolleybus("ELECTRON T19102", 116);
    trolleybus_array[140] = new Trolleybus("ELECTRON T19102", 140);
    trolleybus_array[115] = new Trolleybus("ELECTRON T19102", 115);
    trolleybus_array[108] = new Trolleybus("LAZ E183", 108);
    trolleybus_array[144] = new Trolleybus("ELECTRON T19102", 144);



    trolleybus_array[137]->sent_to_route(route23, Bus_Station);
    trolleybus_array[116]->sent_to_route(route23, Sknylivok);
    trolleybus_array[140]->sent_to_route(route23, Railway_Adm);
    trolleybus_array[115]->sent_to_route(route23_reverse, Ocean);
    trolleybus_array[108]->sent_to_route(route23_reverse, Rubchaka);
    trolleybus_array[144]->sent_to_route(route23_reverse, Skoryny);
    //trolleybus24
    trolleybus_array[145] = new Trolleybus("ELECTRON T19102", 145);
    trolleybus_array[146]= new Trolleybus("ELECTRON T19102", 146);
    trolleybus_array[173] = new Trolleybus("ELECTRON T19102", 173);
    trolleybus_array[145]->sent_to_route(route33, ShevchenkoAdm);
    trolleybus_array[146]->sent_to_route(route30, Railway_Adm);
    trolleybus_array[173]->sent_to_route(route24, Frezer_Factory);
}

trolleybus_list::~trolleybus_list()
{
    delete ui;
}

void trolleybus_list::on_pushButton_clicked()
{
    window_map = new tr_map(this);
    window_map->show();
}


void trolleybus_list::on_button22_clicked()
{
    window22 = new trolleybus22(this);
    window22->show();
}
void trolleybus_list::on_button23_clicked()
{
    window23 = new trolleybus23(this);
    window23->show();
}


void trolleybus_list::on_button24_clicked()
{
    window24 = new trolleybus24(this);
    window24->show();
}


void trolleybus_list::on_button25_clicked()
{
    window25 = new trolleybus25(this);
    window25->show();
}


void trolleybus_list::on_button27_clicked()
{
    window27 = new trolleybus27(this);
    window27->show();
}


void trolleybus_list::on_button30_clicked()
{
    window30 = new trolleybus30(this);
    window30->show();
}


void trolleybus_list::on_button31_clicked()
{
    window31 = new trolleybus31(this);
    window31->show();
}


void trolleybus_list::on_button32_clicked()
{
    window32 = new trolleybus32(this);
    window32->show();
}


void trolleybus_list::on_button33_clicked()
{
    window33 = new trolleybus33(this);
    window33->show();
}


void trolleybus_list::on_button38_clicked()
{
    window38 = new trolleybus38(this);
    window38->show();
}




void trolleybus_list::on_pushButton_2_clicked()
{
    QString input_index = ui->tr_index->text();
    int int_index = input_index.toInt();
    if(int_index < 600)
    {
        if(trolleybus_array[int_index] != nullptr)
        {
            int route_index = trolleybus_array[int_index]->current_route->number;
            if(route_index == 22)
            {
            QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 22 : УНІВЕРСИТЕТ - АВТОВОКЗАЛ");
            }
            if(route_index == 23)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 23 : РЯШІВСЬКА - АВТОВОКЗАЛ");
            }
            if(route_index == 24)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 24 : ШОТА РУСТАВЕЛІ - САНТА БАРБАРА");
            }
            if(route_index == 25)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 25 : ШОТА РУСТАВЕЛІ - АВТОВОКЗАЛ");
            }
            if(route_index == 30)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 30 : УНІВЕРСИТЕТ - РЯШІВСЬКА");
            }
            if(route_index == 32)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 22 : УНІВЕРСИТЕТ - АВТОВОКЗАЛ");
            }
            if(route_index == 33)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 33 : ПЛОЩА ІВАНА ПІДКОВИ - ВУЛ. ГРІНЧЕНКА");
            }
            if(route_index == 38)
            {
                QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ НА МАРШРУТІ 22 : УНІВЕРСИТЕТ - АВТОВОКЗАЛ");
            }
        }
        if(trolleybus_array[int_index] == nullptr)
        {
            QMessageBox::information(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУС ПЕРЕБУВАЄ В ДЕПО І НЕ КУРСУЄ НА ЛІНІЇ");
        }

    }
    else
    {
        QMessageBox::warning(this, "ІНФОРМАЦІЯ ПРО ТРОЛЕЙБУС", "ТРОЛЕЙБУСА З ТАКИМ ІНДЕКСОМ НЕ ІСНУЄ");
    }



}

