#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BetonLicz.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    BetonLicz* Obliczonka= nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void freeze(bool);
    void getbet();
    void getstl();
    void geteks();
};

#endif // MAINWINDOW_H
