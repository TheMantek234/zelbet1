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

    BetonLicz* target;

public:
     wyborpreta(BetonLicz* src, QWidget *parent = nullptr);
    ~wyborpreta();

private slots:
     void on_pushButton_clicked();


     void on_spinAs1_valueChanged(double arg1);

     void on_spinAs2_valueChanged(double arg1);

     void on_d1_editingFinished();

private:
    Ui::wyborpreta *ui;
};

#endif // WYBORPRETA_H
