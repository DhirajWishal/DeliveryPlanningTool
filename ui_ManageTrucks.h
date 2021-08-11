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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageTrucks
{
public:
    QWidget *centralwidget;
    QListWidget *truckList;
    QPushButton *remove;
    QTextEdit *truckID;
    QTextEdit *truckCapacity;
    QPushButton *addToList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageTrucks)
    {
        if (ManageTrucks->objectName().isEmpty())
            ManageTrucks->setObjectName(QString::fromUtf8("ManageTrucks"));
        ManageTrucks->resize(800, 600);
        centralwidget = new QWidget(ManageTrucks);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        truckList = new QListWidget(centralwidget);
        truckList->setObjectName(QString::fromUtf8("truckList"));
        truckList->setGeometry(QRect(10, 10, 261, 511));
        remove = new QPushButton(centralwidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(10, 530, 261, 24));
        truckID = new QTextEdit(centralwidget);
        truckID->setObjectName(QString::fromUtf8("truckID"));
        truckID->setGeometry(QRect(330, 180, 401, 31));
        truckCapacity = new QTextEdit(centralwidget);
        truckCapacity->setObjectName(QString::fromUtf8("truckCapacity"));
        truckCapacity->setGeometry(QRect(330, 230, 401, 31));
        addToList = new QPushButton(centralwidget);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(470, 280, 131, 24));
        ManageTrucks->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManageTrucks);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ManageTrucks->setMenuBar(menubar);
        statusbar = new QStatusBar(ManageTrucks);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManageTrucks->setStatusBar(statusbar);

        retranslateUi(ManageTrucks);

        QMetaObject::connectSlotsByName(ManageTrucks);
    } // setupUi

    void retranslateUi(QMainWindow *ManageTrucks)
    {
        ManageTrucks->setWindowTitle(QCoreApplication::translate("ManageTrucks", "Manage Trucks", nullptr));
        remove->setText(QCoreApplication::translate("ManageTrucks", "Remove", nullptr));
        truckID->setPlaceholderText(QCoreApplication::translate("ManageTrucks", "Truck ID", nullptr));
        truckCapacity->setPlaceholderText(QCoreApplication::translate("ManageTrucks", "Truck Capacity (cubic meters)", nullptr));
        addToList->setText(QCoreApplication::translate("ManageTrucks", "Add To List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageTrucks: public Ui_ManageTrucks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETRUCKS_H
