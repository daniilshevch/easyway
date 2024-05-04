#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "trolleybus_list.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap picture(":/img/images/img4391-99c5bd3b.jpg");
    ui->image->setPixmap(picture.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->log->text();
    QString password = ui->pass->text();
    if(login == "Daniil" && password == "15052005")
    {
        close();
        trolleybus_list window2;
        window2.setModal(true);
        window2.exec();

        //window2 = new trolleybus_list(this);
        //window2->show();

    }
    else
    {
        QMessageBox::warning(this, "АВТОРИЗАЦІЮ ПРОВАЛЕНО", "НЕПРАВИЛЬНИЙ ЛОГІН ЧИ ПАРОЛЬ");
    }

}

