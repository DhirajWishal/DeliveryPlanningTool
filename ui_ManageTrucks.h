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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *labelTruckID;
    QFrame *line_2;
    QLabel *labelTruckCapacity;
    QFrame *line;
    QLabel *label;
    QListWidget *locationList;
    QLabel *label_2;
    QListWidget *itemList;
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
        truckID->setGeometry(QRect(330, 30, 401, 31));
        truckCapacity = new QTextEdit(centralwidget);
        truckCapacity->setObjectName(QString::fromUtf8("truckCapacity"));
        truckCapacity->setGeometry(QRect(330, 80, 401, 31));
        addToList = new QPushButton(centralwidget);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(470, 130, 131, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(330, 180, 401, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        labelTruckID = new QLabel(verticalLayoutWidget);
        labelTruckID->setObjectName(QString::fromUtf8("labelTruckID"));
        labelTruckID->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTruckID);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        labelTruckCapacity = new QLabel(verticalLayoutWidget);
        labelTruckCapacity->setObjectName(QString::fromUtf8("labelTruckCapacity"));
        labelTruckCapacity->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTruckCapacity);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        locationList = new QListWidget(verticalLayoutWidget);
        locationList->setObjectName(QString::fromUtf8("locationList"));

        verticalLayout->addWidget(locationList);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        itemList = new QListWidget(verticalLayoutWidget);
        itemList->setObjectName(QString::fromUtf8("itemList"));

        verticalLayout->addWidget(itemList);

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
        label_3->setText(QCoreApplication::translate("ManageTrucks", "Truck Information", nullptr));
        labelTruckID->setText(QString());
        labelTruckCapacity->setText(QString());
        label->setText(QCoreApplication::translate("ManageTrucks", "Locations", nullptr));
        label_2->setText(QCoreApplication::translate("ManageTrucks", "All items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageTrucks: public Ui_ManageTrucks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETRUCKS_H
