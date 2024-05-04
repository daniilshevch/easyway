#include "tr_map.h"
#include "ui_tr_map.h"
#include <QPixmap>

tr_map::tr_map(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tr_map)
{
    ui->setupUi(this);
    QPixmap picture3(":/img/images/8619ad33e2fd8374f061f3cc056ef6e7f6e03e3a_1557999881.jpeg");
    ui->image3->setPixmap(picture3.scaled(ui->image3->width(), ui->image3->height(), Qt::KeepAspectRatio));
}

tr_map::~tr_map()
{
    delete ui;
}
