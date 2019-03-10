#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wyborpreta.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //betony
    ui->CombBet->addItem("C20/25");



    //stale
    ui->CombStl->addItem("B500B");



    //ekspo iks de
    ui->CombEks->addItem("XC1");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(Obliczonka != nullptr)
    {
        delete Obliczonka;
        Obliczonka=nullptr;
    }
    Obliczonka=new BetonLicz;
    freeze(false);
    getbet();
    getstl();
    geteks();
    Obliczonka->lcol = ui->wysslup->value();
    Obliczonka->Beta = ui->beta->value();
    Obliczonka->b = ui->szerb->value();
    Obliczonka->h = ui->wysh->value();
    Obliczonka->Ned = ui->Ned->value();
    Obliczonka->M0ed = ui->M0ed->value();
    Obliczonka->stosm = ui->momzgi->value();
    Obliczonka->RH= ui->wilgot->value();
    Obliczonka->t0 = ui->czasprzyl->value();
    Obliczonka->rob = ui->rob->value();
    //Poczatek obliczen
    Obliczonka->PelzLicz();
    if (Obliczonka->smuklosc)
    {
        QMessageBox A(QMessageBox::Icon::Information,"","Element jest smukły, kontynuuj obliczenia(tak) lub zmień dane przekroju(nie)",
                      QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
        A.exec();
        if (A.result()==QMessageBox::StandardButton::No)
        {
            freeze(true);
            delete Obliczonka;
            Obliczonka = nullptr;
            return;

        }
    }
    else
    {
        QMessageBox A(QMessageBox::Icon::Information,"","Element jest krępy, kontynuuj obliczenia(tak) lub zmień dane przekroju(nie)",
                      QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
        A.exec();
        if (A.result()==QMessageBox::StandardButton::No)
        {
            freeze(true);
            delete Obliczonka;
            Obliczonka = nullptr;
            return;

        }
    }
    Obliczonka->liczsmukly();
    Obliczonka->wtracenie();
    ui->pushButton->setText(QString::number(Obliczonka->As1));
    Obliczonka->wymiar();

    wyborpreta* zbrojenie=new wyborpreta(Obliczonka);
    zbrojenie->show();


    freeze(true);
}

void MainWindow::freeze(bool src)
{

    ui->CombBet->setEnabled(src);
    ui->CombStl->setEnabled(src);
    ui->CombEks->setEnabled(src);
    //te drugie lajbelki
    ui->wysslup->setEnabled(src);
    ui->wysh->setEnabled(src);
    ui->beta->setEnabled(src);
    ui->szerb->setEnabled(src);
    ui->wilgot->setEnabled(src);
    ui->M0ed->setEnabled(src);
    ui->Ned->setEnabled(src);
    ui->czasprzyl->setEnabled(src);
    ui->momzgi->setEnabled(src);
}

void MainWindow::getbet()
{
    switch(ui->CombBet->currentIndex())
    {
        case 0:
            Obliczonka->Ecm = 30.0;
            Obliczonka->ec2 = 2.0*0.001;
            Obliczonka->ecu2 = 3.5*0.001;
            Obliczonka->fck = 20.0;
        break;
    }
    Obliczonka->bet1();
}
void MainWindow::getstl()
{
    switch(ui->CombStl->currentIndex())
    {
        case 0:
            Obliczonka->Es = 200.0;
            Obliczonka->fyd = 500.0;

        break;
    }
    Obliczonka->stl1();
}

void MainWindow::geteks()
{
    switch(ui->CombEks->currentIndex())
    {
        case 0:
            Obliczonka->cmind = 15.0;

        break;
    }
}
