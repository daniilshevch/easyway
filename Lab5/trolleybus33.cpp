#include "trolleybus33.h"
#include "ui_trolleybus33.h"

trolleybus33::trolleybus33(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus33)
{
    ui->setupUi(this);
}

trolleybus33::~trolleybus33()
{
    delete ui;
}
