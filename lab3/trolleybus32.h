#ifndef TROLLEYBUS32_H
#define TROLLEYBUS32_H

#include <QDialog>

namespace Ui {
class trolleybus32;
}

class trolleybus32 : public QDialog
{
    Q_OBJECT

public:
    explicit trolleybus32(QWidget *parent = nullptr);
    ~trolleybus32();

private:
    Ui::trolleybus32 *ui;
};

#endif // TROLLEYBUS32_H
