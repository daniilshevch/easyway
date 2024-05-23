#include "trolleybus32.h"
#include "ui_trolleybus32.h"

trolleybus32::trolleybus32(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus32)
{
    ui->setupUi(this);
}

trolleybus32::~trolleybus32()
{
    delete ui;
}
