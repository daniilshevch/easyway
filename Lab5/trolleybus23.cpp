#include "trolleybus23.h"
#include "ui_trolleybus23.h"
#include <QTableView>
#include <QStandardItemModel>
#include <algorithm>
#include <QString>
#include <QList>
#include <QVector>
#include <QIcon>
#include <algorithm>
#include <QRandomGenerator>
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
trolleybus23::trolleybus23(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus23)
{
    ui->setupUi(this);
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
    QVector<Station*> list23 = { Bus_Station, Maksymovycha,  Hasheka, Skoryny, Striyska_Naukova, Bodnarivka, Rubchaka, Trolleybus_Depaut,
                                 Com_College, Volodymyra_Velykogo, Ocean, Botkina, Sknylivok, Pivd_Market, Sknyliv_Park, Lubinska_Vygovskogo, Railway_Adm,
                                 Patona, Lorta, Riashivska };
    QVector<Station*> list23_reverse = { Bus_Station, Maksymovycha,  Hasheka, Skoryny, Striyska_Naukova, Bodnarivka, Rubchaka, Trolleybus_Depaut,
                                 Com_College, Volodymyra_Velykogo, Ocean, Botkina, Sknylivok, Pivd_Market, Sknyliv_Park, Lubinska_Vygovskogo, Railway_Adm,
                                 Patona, Lorta, Riashivska };
    Trolleybus_Route* route23 = new Trolleybus_Route(23);
    Trolleybus_Route* route23_reverse = new Trolleybus_Route(23);
    QVector<Trolleybus*> trolleybus_list(600);
    trolleybus_list[137] = new Trolleybus("ELECTRON T19102", 137);
    trolleybus_list[116]= new Trolleybus("ELECTRON T19102", 116);
    trolleybus_list[140] = new Trolleybus("ELECTRON T19102", 140);
    trolleybus_list[115] = new Trolleybus("ELECTRON T19102", 115);
    trolleybus_list[108] = new Trolleybus("LAZ E183", 108);
    trolleybus_list[144] = new Trolleybus("ELECTRON T19102", 144);

    QRandomGenerator *generator = QRandomGenerator::global();

    trolleybus_list[137]->sent_to_route(route23, Bus_Station);
    trolleybus_list[116]->sent_to_route(route23, Sknylivok);
    trolleybus_list[140]->sent_to_route(route23, Railway_Adm);
    trolleybus_list[115]->sent_to_route(route23_reverse, Ocean);
    trolleybus_list[108]->sent_to_route(route23_reverse, Rubchaka);
    trolleybus_list[144]->sent_to_route(route23_reverse, Skoryny);

    int interval = 16;
    ui->setupUi(this);
    ui->setupUi(this);
    QPixmap picture(":/img/images/00137640.jpg");
    ui->image->setPixmap(picture.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
    model = new QStandardItemModel(5, 3, this);
    model2 = new QStandardItemModel(5, 3, this);

    model->setHorizontalHeaderLabels({"ЗУПИНКА", "ЧАС ПРИБУТТЯ", "НАЯВНІСТЬ ТРОЛЕЙБУСІВ"});
    for (int row = 0; row < list23.size(); ++row)
    {
        QStandardItem *item = new QStandardItem(QString("%1").arg(QString(list23[row]->name)));
        item->setEditable(false);
        model->setItem(row, 0, item);
    }

    int upper = interval;
    for (int row = 0; row < list23.size(); ++row)
    {
        if(list23[row]->current_trolleybus!=nullptr && list23[row]->current_trolleybus->current_route == route23)
        {
            int option = generator->bounded(0,2);
            QString str;
            if(option == 0)
            {
                str = "NOW";
            }
            else
            {
                str = "<1ХВ";
            }
            upper = interval;

            QStandardItem *item = new QStandardItem(QString("%1").arg(QString(str)));
            item->setEditable(false);
            model->setItem(row, 1, item);
        }
        else
        {
            int output = generator->bounded(2, upper);
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(output).arg(QString("ХВ")));
            item->setEditable(false);
            model->setItem(row, 1, item);
            upper = output+1;
        }
    }
    for (int row = 0; row < list23.size(); ++row)
    {
        if(list23[row]->current_trolleybus!=nullptr && list23[row]->current_trolleybus->current_route == route23)
        {
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(list23[row]->current_trolleybus->index).arg(QString(list23[row]->current_trolleybus->model)));
            item->setEditable(false);
            model->setItem(row, 2, item);
        }
    }

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    model2->setHorizontalHeaderLabels({"ЗУПИНКА", "ЧАС ПРИБУТТЯ", "НАЯВНІСТЬ ТРОЛЕЙБУСІВ"});
    for (int row = 0; row < list23_reverse.size(); ++row)
    {
        QStandardItem *item = new QStandardItem(QString("%1").arg(QString(list23_reverse[list23_reverse.size()-1-row]->name)));
        item->setEditable(false);
        model2->setItem(row, 0, item);
    }
    int upper2 = interval;
    for (int row = 0; row < list23_reverse.size(); ++row)
    {
        if(list23_reverse[row]->current_trolleybus!=nullptr && list23_reverse[row]->current_trolleybus->current_route == route23_reverse)
        {
            int option = generator->bounded(0,2);
            QString str;
            if(option == 0)
            {
                str = "NOW";
            }
            else
            {
                str = "<1ХВ";
            }
            upper2 = interval;

            QStandardItem *item = new QStandardItem(QString("%1").arg(QString(str)));
            item->setEditable(false);
            model2->setItem(row, 1, item);
        }
        else
        {
            int output = generator->bounded(2, upper2);
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(output).arg(QString("ХВ")));
            item->setEditable(false);
            model2->setItem(row, 1, item);
            upper2 = output+1;
        }
    }
    for (int row = 0; row < list23_reverse.size(); ++row)
    {
        if(list23_reverse[row]->current_trolleybus!=nullptr && list23_reverse[row]->current_trolleybus->current_route == route23_reverse)
        {
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(list23_reverse[row]->current_trolleybus->index).arg(QString(list23_reverse[row]->current_trolleybus->model)));
            item->setEditable(false);
            model2->setItem(row, 2, item);
        }
    }
    ui->tableView_2->setModel(model2);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);






    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

}

trolleybus23::~trolleybus23()
{
    delete ui;
}



