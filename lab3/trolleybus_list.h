#ifndef TROLLEYBUS_LIST_H
#define TROLLEYBUS_LIST_H

#include <QDialog>
#include "trolleybus22.h"
#include "trolleybus23.h"
#include "trolleybus24.h"
#include "trolleybus25.h"
#include "trolleybus27.h"
#include "trolleybus30.h"
#include "trolleybus31.h"
#include "trolleybus32.h"
#include "trolleybus33.h"
#include "trolleybus38.h"
#include "tr_map.h"
namespace Ui {
class trolleybus_list;
}

class trolleybus_list : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus_list(QWidget *parent = nullptr);
    ~trolleybus_list();

private slots:
    void on_pushButton_clicked();

    void on_button23_clicked();

    void on_button24_clicked();

    void on_button25_clicked();

    void on_button27_clicked();

    void on_button30_clicked();

    void on_button31_clicked();

    void on_button32_clicked();

    void on_button33_clicked();

    void on_button38_clicked();

    void on_button22_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::trolleybus_list *ui;
    trolleybus22* window22;
    trolleybus23* window23;
    trolleybus24* window24;
    trolleybus25* window25;
    trolleybus27* window27;
    trolleybus30* window30;
    trolleybus31* window31;
    trolleybus32* window32;
    trolleybus33* window33;
    trolleybus38* window38;
    tr_map* window_map;
};

#endif // TROLLEYBUS_LIST_H
