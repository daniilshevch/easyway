#ifndef TROLLEYBUS24_H
#define TROLLEYBUS24_H

#include <QDialog>

namespace Ui {
class trolleybus24;
}

class trolleybus24 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus24(QWidget *parent = nullptr);
    ~trolleybus24();

private:
    Ui::trolleybus24 *ui;
};

#endif // TROLLEYBUS24_H
