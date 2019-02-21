#include "wyborpreta.h"
#include "ui_wyborpreta.h"

wyborpreta::wyborpreta(BetonLicz & src, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wyborpreta),target(src)
{
    ui->setupUi(this);
}

wyborpreta::~wyborpreta()
{
    delete ui;
}
