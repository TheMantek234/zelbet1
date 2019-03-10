/********************************************************************************
** Form generated from reading UI file 'wyborpreta.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYBORPRETA_H
#define UI_WYBORPRETA_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_wyborpreta
{
public:
    QDoubleSpinBox *d1;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_2;
    QDoubleSpinBox *d2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *As1min;
    QLabel *As2min;
    QLabel *As1req;
    QLabel *As1prov;
    QLabel *As2req;
    QLabel *As2prov;

    void setupUi(QDialog *wyborpreta)
    {
        if (wyborpreta->objectName().isEmpty())
            wyborpreta->setObjectName(QString::fromUtf8("wyborpreta"));
        wyborpreta->resize(627, 253);
        d1 = new QDoubleSpinBox(wyborpreta);
        d1->setObjectName(QString::fromUtf8("d1"));
        d1->setGeometry(QRect(190, 20, 62, 22));
        d1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        d1->setDecimals(3);
        d1->setMaximum(1.000000000000000);
        d1->setSingleStep(0.001000000000000);
        label = new QLabel(wyborpreta);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 171, 41));
        label_5 = new QLabel(wyborpreta);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 130, 61, 16));
        label_6 = new QLabel(wyborpreta);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 70, 51, 16));
        label_7 = new QLabel(wyborpreta);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 130, 61, 16));
        label_8 = new QLabel(wyborpreta);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(390, 70, 47, 13));
        label_2 = new QLabel(wyborpreta);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(340, 10, 171, 41));
        d2 = new QDoubleSpinBox(wyborpreta);
        d2->setObjectName(QString::fromUtf8("d2"));
        d2->setGeometry(QRect(510, 20, 62, 22));
        d2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        d2->setDecimals(3);
        d2->setMaximum(1.000000000000000);
        d2->setSingleStep(0.001000000000000);
        pushButton = new QPushButton(wyborpreta);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 190, 121, 41));
        pushButton->setAutoDefault(false);
        label_3 = new QLabel(wyborpreta);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 20, 47, 13));
        label_4 = new QLabel(wyborpreta);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(580, 20, 47, 13));
        As1min = new QLabel(wyborpreta);
        As1min->setObjectName(QString::fromUtf8("As1min"));
        As1min->setEnabled(true);
        As1min->setGeometry(QRect(50, 160, 181, 51));
        As2min = new QLabel(wyborpreta);
        As2min->setObjectName(QString::fromUtf8("As2min"));
        As2min->setEnabled(true);
        As2min->setGeometry(QRect(410, 160, 181, 51));
        As1req = new QLabel(wyborpreta);
        As1req->setObjectName(QString::fromUtf8("As1req"));
        As1req->setGeometry(QRect(160, 60, 91, 41));
        As1prov = new QLabel(wyborpreta);
        As1prov->setObjectName(QString::fromUtf8("As1prov"));
        As1prov->setGeometry(QRect(160, 120, 91, 41));
        As2req = new QLabel(wyborpreta);
        As2req->setObjectName(QString::fromUtf8("As2req"));
        As2req->setGeometry(QRect(470, 60, 91, 41));
        As2prov = new QLabel(wyborpreta);
        As2prov->setObjectName(QString::fromUtf8("As2prov"));
        As2prov->setGeometry(QRect(470, 120, 91, 41));

        retranslateUi(wyborpreta);

        QMetaObject::connectSlotsByName(wyborpreta);
    } // setupUi

    void retranslateUi(QDialog *wyborpreta)
    {
        wyborpreta->setWindowTitle(QApplication::translate("wyborpreta", "Dialog", nullptr));
        label->setText(QApplication::translate("wyborpreta", "Zak\305\202adana srednica pr\304\231t\303\263w As1", nullptr));
        label_5->setText(QApplication::translate("wyborpreta", "n As1prov:", nullptr));
        label_6->setText(QApplication::translate("wyborpreta", "n As1req:", nullptr));
        label_7->setText(QApplication::translate("wyborpreta", "n As2prov:", nullptr));
        label_8->setText(QApplication::translate("wyborpreta", "n As2req:", nullptr));
        label_2->setText(QApplication::translate("wyborpreta", "Zak\305\202adana srednica pr\304\231t\303\263w As2", nullptr));
        pushButton->setText(QApplication::translate("wyborpreta", "Zaakceptuj", nullptr));
        label_3->setText(QApplication::translate("wyborpreta", "[m]", nullptr));
        label_4->setText(QApplication::translate("wyborpreta", "[m]", nullptr));
        As1min->setText(QApplication::translate("wyborpreta", "Zastosowano minimalne zbrojenie", nullptr));
        As2min->setText(QApplication::translate("wyborpreta", "Zastosowano minimalne zbrojenie", nullptr));
        As1req->setText(QString());
        As1prov->setText(QString());
        As2req->setText(QString());
        As2prov->setText(QApplication::translate("wyborpreta", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wyborpreta: public Ui_wyborpreta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYBORPRETA_H
