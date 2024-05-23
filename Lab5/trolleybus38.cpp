#include "trolleybus38.h"
#include "ui_trolleybus38.h"

trolleybus38::trolleybus38(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus38)
{
    ui->setupUi(this);
}

trolleybus38::~trolleybus38()
{
    delete ui;
}
