#ifndef TROLLEYBUS25_H
#define TROLLEYBUS25_H

#include <QDialog>

namespace Ui {
class trolleybus25;
}

class trolleybus25 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus25(QWidget *parent = nullptr);
    ~trolleybus25();

private:
    Ui::trolleybus25 *ui;
};

#endif // TROLLEYBUS25_H
