#ifndef TROLLEYBUS31_H
#define TROLLEYBUS31_H

#include <QDialog>

namespace Ui {
class trolleybus31;
}

class trolleybus31 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus31(QWidget *parent = nullptr);
    ~trolleybus31();

private:
    Ui::trolleybus31 *ui;
};

#endif // TROLLEYBUS31_H
