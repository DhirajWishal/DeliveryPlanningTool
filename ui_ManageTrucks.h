/********************************************************************************
** Form generated from reading UI file 'ManageTrucks.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGETRUCKS_H
#define UI_MANAGETRUCKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageTrucks
{
public:
    QListWidget *truckList;
    QTextEdit *truckCapacity;
    QPushButton *remove;
    QTextEdit *truckID;
    QPushButton *addToList;

    void setupUi(QWidget *ManageTrucks)
    {
        if (ManageTrucks->objectName().isEmpty())
            ManageTrucks->setObjectName(QString::fromUtf8("ManageTrucks"));
        ManageTrucks->resize(781, 560);
        truckList = new QListWidget(ManageTrucks);
        truckList->setObjectName(QString::fromUtf8("truckList"));
        truckList->setGeometry(QRect(10, 10, 261, 511));
        truckCapacity = new QTextEdit(ManageTrucks);
        truckCapacity->setObjectName(QString::fromUtf8("truckCapacity"));
        truckCapacity->setGeometry(QRect(330, 230, 401, 31));
        remove = new QPushButton(ManageTrucks);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(10, 530, 261, 24));
        truckID = new QTextEdit(ManageTrucks);
        truckID->setObjectName(QString::fromUtf8("truckID"));
        truckID->setGeometry(QRect(330, 180, 401, 31));
        addToList = new QPushButton(ManageTrucks);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(470, 280, 131, 24));

        retranslateUi(ManageTrucks);

        QMetaObject::connectSlotsByName(ManageTrucks);
    } // setupUi

    void retranslateUi(QWidget *ManageTrucks)
    {
        ManageTrucks->setWindowTitle(QCoreApplication::translate("ManageTrucks", "Manage Trucks", nullptr));
        truckCapacity->setPlaceholderText(QCoreApplication::translate("ManageTrucks", "Truck Capacity (cubic meters)", nullptr));
        remove->setText(QCoreApplication::translate("ManageTrucks", "Remove", nullptr));
        truckID->setPlaceholderText(QCoreApplication::translate("ManageTrucks", "Truck ID", nullptr));
        addToList->setText(QCoreApplication::translate("ManageTrucks", "Add To List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageTrucks: public Ui_ManageTrucks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETRUCKS_H
