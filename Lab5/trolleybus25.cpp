#include "trolleybus25.h"
#include "ui_trolleybus25.h"

trolleybus25::trolleybus25(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus25)
{
    ui->setupUi(this);
}

trolleybus25::~trolleybus25()
{
    delete ui;
}
