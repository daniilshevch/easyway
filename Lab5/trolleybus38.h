#ifndef TROLLEYBUS38_H
#define TROLLEYBUS38_H

#include <QDialog>

namespace Ui {
class trolleybus38;
}

class trolleybus38 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus38(QWidget *parent = nullptr);
    ~trolleybus38();

private:
    Ui::trolleybus38 *ui;
};

#endif // TROLLEYBUS38_H
