#include "wyborpreta.h"
#include "ui_wyborpreta.h"

wyborpreta::wyborpreta(BetonLicz* src, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wyborpreta)
{
    target = src;
    ui->setupUi(this);

    ui->label->setNum(src->As1);

    ui->As1min->hide();
    ui->As2min->hide();
    if(target->min1== true)
    {
        ui->As1min->show();
        ui->d1->setValue(0.012);
        ui->d1->setEnabled(false);


    }
    if(target->min2== true)
    {
        ui->As2min->show();
        ui->d2->setValue(0.012);
        ui->d2->setEnabled(false);
    }

}

wyborpreta::~wyborpreta()
{
    delete ui;
}

void wyborpreta::on_pushButton_clicked()
{
    this->close();
}



void wyborpreta::on_spinAs1_valueChanged(double arg1)
{
   /* void BetonLicz::wyborpret1()
    {
        if (min1 == false) {
            n1req = (4.0 * As1) / (3.14*fi1*fi1);

            n1prov = ceil(n1req);
        }
        else { n1prov = 2.0; fi1 = 0.012; }
        As1 = (n1prov * 3.14*fi1*fi1) / 4.0;
        } */
    double a = (4.0 * target->As1) / (3.14*arg1*arg1);
   ui->As1req->setText(QString::number(a));
   double b = ceil(a);
   ui->As1prov->setText(QString::number(b));
}

void wyborpreta::on_spinAs2_valueChanged(double arg1)
{
    /*void BetonLicz::wyborpret2()
    {

        if (min2 == false) {
            n2req = (4.0 * As2) / (3.14*fi2*fi2);
            n2prov = ceil(n2req);
        }
        else { n2prov = 2.0; fi2 = 0.012; }
        As2 = (n2prov * 3.14*fi2*fi2) / 4.0;
    }
    */
    double a = (4.0 * target->As2) / (3.14*arg1*arg1);
   ui->As2req->setText(QString::number(a));
   double b = ceil(a);
   ui->As2prov->setText(QString::number(b));

}

void wyborpreta::on_d1_editingFinished()
{
    double a = (4.0 * target->As1) / (3.14*ui->d1->value()*ui->d1->value());
   ui->As1req->setText(QString::number(a));
   double b = ceil(a);
   ui->As1prov->setText(QString::number(b));
   ui->As2req->setText(QString::number(target->As1));
}
