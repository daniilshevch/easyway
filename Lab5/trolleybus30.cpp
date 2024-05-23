#include "trolleybus30.h"
#include "ui_trolleybus30.h"

trolleybus30::trolleybus30(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus30)
{
    ui->setupUi(this);
}

trolleybus30::~trolleybus30()
{
    delete ui;
}
