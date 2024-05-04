#ifndef TROLLEYBUS22_H
#define TROLLEYBUS22_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui {
class trolleybus22;
}

class trolleybus22 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus22(QWidget *parent = nullptr);
    ~trolleybus22();

private:
    Ui::trolleybus22 *ui;
    QStandardItemModel* model;
    QStandardItemModel* model2;
};

#endif // TROLLEYBUS22_H
