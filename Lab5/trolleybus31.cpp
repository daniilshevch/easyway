#include "trolleybus31.h"
#include "ui_trolleybus31.h"

trolleybus31::trolleybus31(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus31)
{
    ui->setupUi(this);
}

trolleybus31::~trolleybus31()
{
    delete ui;
}
