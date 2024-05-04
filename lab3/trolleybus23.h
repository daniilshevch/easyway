#ifndef TROLLEYBUS23_H
#define TROLLEYBUS23_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class trolleybus23;
}

class trolleybus23 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus23(QWidget *parent = nullptr);
    ~trolleybus23();

private:
    Ui::trolleybus23 *ui;
    QStandardItemModel* model;
    QStandardItemModel* model2;
};

#endif // TROLLEYBUS23_H
