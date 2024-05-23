#ifndef TROLLEYBUS33_H
#define TROLLEYBUS33_H

#include <QDialog>

namespace Ui {
class trolleybus33;
}

class trolleybus33 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus33(QWidget *parent = nullptr);
    ~trolleybus33();

private:
    Ui::trolleybus33 *ui;
};

#endif // TROLLEYBUS33_H
