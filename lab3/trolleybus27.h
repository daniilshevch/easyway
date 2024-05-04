#ifndef TROLLEYBUS27_H
#define TROLLEYBUS27_H

#include <QDialog>

namespace Ui {
class trolleybus27;
}

class trolleybus27 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus27(QWidget *parent = nullptr);
    ~trolleybus27();

private:
    Ui::trolleybus27 *ui;
};

#endif // TROLLEYBUS27_H
