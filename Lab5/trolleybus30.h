#ifndef TROLLEYBUS30_H
#define TROLLEYBUS30_H

#include <QDialog>

namespace Ui {
class trolleybus30;
}

class trolleybus30 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus30(QWidget *parent = nullptr);
    ~trolleybus30();

private:
    Ui::trolleybus30 *ui;
};

#endif // TROLLEYBUS30_H
