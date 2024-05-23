#ifndef TR_MAP_H
#define TR_MAP_H

#include <QDialog>

namespace Ui {
class tr_map;
}

class tr_map : public QDialog
{
    Q_OBJECT

public:
    explicit tr_map(QWidget *parent = nullptr);
    ~tr_map();

private:
    Ui::tr_map *ui;
};

#endif // TR_MAP_H
