#include "trolleybus22.h"
#include "ui_trolleybus22.h"
#include "classes.h"
QVector<Station*> list22 = { University, St_Ura, Stepana_Bandery, Lypneva, Smal_Stockogo,
                             Kopystynskogo, Antonovycha, Kulparkiv, Sknylivok, Shyretska, Naukova, Symonenka, Science_Club,
                             Emp_Centre, Kn_Olgy, Troleybusna, Pidstrygacha, Striyska_Naukova, Skoryny, Hasheka, Maksymovycha, Bus_Station };
QVector<Station*> list22_reverse = { University,Ustiyanovycha, St_Ura, Stepana_Bandery, Melnyka, Zalizniaka,
                                     Antonovycha, Kulparkiv, Sknylivok, Shyretska, Naukova, Symonenka, Science_Club,
                                     Emp_Centre, Kn_Olgy, Troleybusna, Pidstrygacha, Striyska_Naukova, Skoryny, Hasheka, Maksymovycha, Bus_Station };




trolleybus22::trolleybus22(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus22)
{
    QRandomGenerator *generator = QRandomGenerator::global();
    QVector<Trolleybus*> trolleybus_list(600);

    Trolleybus_Route* route22 = new Trolleybus_Route(22);
    Trolleybus_Route* route22_reverse = new Trolleybus_Route(22);
    trolleybus_list[123] = new Trolleybus("ELECTRON T19102", 123);
    trolleybus_list[139] = new Trolleybus("ELECTRON T19102", 139);
    trolleybus_list[114] = new Trolleybus("ELECTRON T19101", 114);
    trolleybus_list[118] = new Trolleybus("ELECTRON T19101", 118);
    trolleybus_list[105] = new Trolleybus("LAZ E183", 105);
    trolleybus_list[172] = new Trolleybus("ELECTRON T19102", 172);
    trolleybus_list[133] = new Trolleybus("ELECTRON T19102", 133);
    trolleybus_list[154] = new Trolleybus("ELECTRON T19102", 154);
    trolleybus_list[558] = new Trolleybus("SKODA TR13", 558);
    trolleybus_list[122] = new Trolleybus("ELECTRON T19102", 122);
    trolleybus_list[138] = new Trolleybus("ELECTRON T19102", 138);
    trolleybus_list[135] = new Trolleybus("ELECTRON T19102", 135);
    trolleybus_list[123]->sent_to_route(route22, Kulparkiv);
    trolleybus_list[139]->sent_to_route(route22, St_Ura);
    trolleybus_list[114]->sent_to_route(route22, Smal_Stockogo);
    trolleybus_list[118]->sent_to_route(route22, Antonovycha);
    trolleybus_list[105]->sent_to_route(route22, Symonenka);
    trolleybus_list[172]->sent_to_route(route22, Skoryny);
    trolleybus_list[133]->sent_to_route(route22_reverse, Striyska_Naukova);
    trolleybus_list[154]->sent_to_route(route22_reverse, Kn_Olgy);
    trolleybus_list[558]->sent_to_route(route22_reverse, Naukova);
    trolleybus_list[122]->sent_to_route(route22_reverse, Sknylivok);
    trolleybus_list[138]->sent_to_route(route22_reverse, Melnyka);
    trolleybus_list[135]->sent_to_route(route22_reverse, University);
    int interval = 10;
    ui->setupUi(this);
    ui->setupUi(this);
    QPixmap picture(":/img/images/00137640.jpg");
    ui->image->setPixmap(picture.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
    model = new QStandardItemModel(5, 3, this);
    model2 = new QStandardItemModel(5, 3, this);

    model->setHorizontalHeaderLabels({"ЗУПИНКА", "ЧАС ПРИБУТТЯ", "НАЯВНІСТЬ ТРОЛЕЙБУСІВ"});
    for (int row = 0; row < list22.size(); ++row)
    {
        QStandardItem *item = new QStandardItem(QString("%1").arg(QString(list22[row]->name)));
        item->setEditable(false);
        model->setItem(row, 0, item);
    }

    int upper = interval;
    for (int row = 0; row < list22.size(); ++row)
    {
        if(list22[row]->current_trolleybus!=nullptr && list22[row]->current_trolleybus->current_route == route22)
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
    for (int row = 0; row < list22.size(); ++row)
    {
        if(list22[row]->current_trolleybus!=nullptr && list22[row]->current_trolleybus->current_route == route22)
        {
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(list22[row]->current_trolleybus->index).arg(QString(list22[row]->current_trolleybus->model)));
            item->setEditable(false);
            model->setItem(row, 2, item);
        }
    }

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    model2->setHorizontalHeaderLabels({"ЗУПИНКА", "ЧАС ПРИБУТТЯ", "НАЯВНІСТЬ ТРОЛЕЙБУСІВ"});
    for (int row = 0; row < list22_reverse.size(); ++row)
    {
        QStandardItem *item = new QStandardItem(QString("%1").arg(QString(list22_reverse[list22_reverse.size()-1-row]->name)));
        item->setEditable(false);
        model2->setItem(row, 0, item);
    }
    int upper2 = interval;
    for (int row = 0; row < list22_reverse.size(); ++row)
    {
        if(list22_reverse[row]->current_trolleybus!=nullptr && list22_reverse[row]->current_trolleybus->current_route == route22_reverse)
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
    for (int row = 0; row < list22_reverse.size(); ++row)
    {
        if(list22_reverse[row]->current_trolleybus!=nullptr && list22_reverse[row]->current_trolleybus->current_route == route22_reverse)
        {
            QStandardItem *item = new QStandardItem(QString("%1 %2").arg(list22_reverse[row]->current_trolleybus->index).arg(QString(list22_reverse[row]->current_trolleybus->model)));
            item->setEditable(false);
            model2->setItem(row, 2, item);
        }
    }
    ui->tableView_2->setModel(model2);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);






    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

trolleybus22::~trolleybus22()
{
    delete ui;
}
