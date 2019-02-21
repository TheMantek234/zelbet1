#ifndef WYBORPRETA_H
#define WYBORPRETA_H
#include "BetonLicz.h"

#include <QDialog>

namespace Ui {
class wyborpreta;
}

class wyborpreta : public QDialog
{
    Q_OBJECT

    BetonLicz & target;

public:
    explicit wyborpreta(BetonLicz & src, QWidget *parent = nullptr);
    ~wyborpreta();

private:
    Ui::wyborpreta *ui;
};

#endif // WYBORPRETA_H
