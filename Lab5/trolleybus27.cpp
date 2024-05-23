#include "trolleybus27.h"
#include "ui_trolleybus27.h"

trolleybus27::trolleybus27(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::trolleybus27)
{
    ui->setupUi(this);
}

trolleybus27::~trolleybus27()
{
    delete ui;
}
