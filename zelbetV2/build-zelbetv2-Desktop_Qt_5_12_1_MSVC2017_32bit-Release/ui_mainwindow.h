/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *CombBet;
    QComboBox *CombStl;
    QComboBox *CombEks;
    QLabel *LabelBet;
    QLabel *LabelStl;
    QLabel *LabelEks;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *wysslup;
    QDoubleSpinBox *beta;
    QDoubleSpinBox *szerb;
    QDoubleSpinBox *wysh;
    QDoubleSpinBox *Ned;
    QDoubleSpinBox *M0ed;
    QDoubleSpinBox *momzgi;
    QDoubleSpinBox *wilgot;
    QDoubleSpinBox *czasprzyl;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QListView *listView;
    QListView *listView_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1109, 672);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CombBet = new QComboBox(centralWidget);
        CombBet->setObjectName(QString::fromUtf8("CombBet"));
        CombBet->setGeometry(QRect(20, 40, 111, 21));
        CombStl = new QComboBox(centralWidget);
        CombStl->setObjectName(QString::fromUtf8("CombStl"));
        CombStl->setGeometry(QRect(20, 90, 111, 21));
        CombEks = new QComboBox(centralWidget);
        CombEks->setObjectName(QString::fromUtf8("CombEks"));
        CombEks->setGeometry(QRect(20, 140, 111, 21));
        LabelBet = new QLabel(centralWidget);
        LabelBet->setObjectName(QString::fromUtf8("LabelBet"));
        LabelBet->setGeometry(QRect(20, 20, 111, 16));
        LabelStl = new QLabel(centralWidget);
        LabelStl->setObjectName(QString::fromUtf8("LabelStl"));
        LabelStl->setGeometry(QRect(20, 70, 111, 16));
        LabelEks = new QLabel(centralWidget);
        LabelEks->setObjectName(QString::fromUtf8("LabelEks"));
        LabelEks->setGeometry(QRect(20, 120, 131, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 60, 171, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 190, 71, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 100, 131, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 140, 131, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 230, 91, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 290, 201, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(180, 330, 201, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(200, 370, 171, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 20, 81, 16));
        wysslup = new QDoubleSpinBox(centralWidget);
        wysslup->setObjectName(QString::fromUtf8("wysslup"));
        wysslup->setGeometry(QRect(370, 20, 62, 22));
        wysslup->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        beta = new QDoubleSpinBox(centralWidget);
        beta->setObjectName(QString::fromUtf8("beta"));
        beta->setGeometry(QRect(370, 60, 62, 22));
        beta->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        szerb = new QDoubleSpinBox(centralWidget);
        szerb->setObjectName(QString::fromUtf8("szerb"));
        szerb->setGeometry(QRect(370, 100, 62, 22));
        szerb->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        wysh = new QDoubleSpinBox(centralWidget);
        wysh->setObjectName(QString::fromUtf8("wysh"));
        wysh->setGeometry(QRect(370, 130, 62, 22));
        wysh->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        Ned = new QDoubleSpinBox(centralWidget);
        Ned->setObjectName(QString::fromUtf8("Ned"));
        Ned->setGeometry(QRect(370, 180, 62, 22));
        Ned->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        M0ed = new QDoubleSpinBox(centralWidget);
        M0ed->setObjectName(QString::fromUtf8("M0ed"));
        M0ed->setGeometry(QRect(370, 220, 62, 22));
        M0ed->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        momzgi = new QDoubleSpinBox(centralWidget);
        momzgi->setObjectName(QString::fromUtf8("momzgi"));
        momzgi->setGeometry(QRect(380, 290, 62, 22));
        momzgi->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        wilgot = new QDoubleSpinBox(centralWidget);
        wilgot->setObjectName(QString::fromUtf8("wilgot"));
        wilgot->setGeometry(QRect(380, 330, 62, 22));
        wilgot->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        czasprzyl = new QDoubleSpinBox(centralWidget);
        czasprzyl->setObjectName(QString::fromUtf8("czasprzyl"));
        czasprzyl->setGeometry(QRect(380, 370, 62, 22));
        czasprzyl->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(450, 20, 47, 13));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(450, 60, 47, 13));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(450, 100, 47, 13));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(450, 130, 47, 13));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(450, 180, 47, 13));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(450, 220, 47, 13));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(460, 290, 47, 13));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(460, 340, 47, 13));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(460, 370, 47, 13));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(550, 20, 261, 571));
        listView_2 = new QListView(centralWidget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(830, 20, 261, 571));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 400, 491, 231));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1109, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LabelBet->setText(QApplication::translate("MainWindow", "Wybierz klase betonu:", nullptr));
        LabelStl->setText(QApplication::translate("MainWindow", "Wybierz gatunek stali:", nullptr));
        LabelEks->setText(QApplication::translate("MainWindow", "Wybierz klase ekspozycji:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Wsp\303\263\305\202czynnik wyboczeniowy Beta:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Podaj Ned:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Podaj szeroko\305\233\304\207 s\305\202upa b:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Podaj wysoko\305\233\304\207 s\305\202upa h:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "M0ed1=M0ed2:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Podaj stosunek moment\303\263w zginaj\304\205cych:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Podaj wilgotno\305\233\304\207 wzgl\304\231dna \305\233rodowiska:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Podaj czas przy\305\202o\305\274enia obci\304\205\305\274enia:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Wysoko\305\233\304\207 s\305\202upa:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "[m]", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "[-]", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "[m]", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "[m]", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "[kN]", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "[kNm]", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "[-]", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "[%]", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "[dni]", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "L I C Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
