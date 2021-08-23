/********************************************************************************
** Form generated from reading UI file 'ManageRoutes.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEROUTES_H
#define UI_MANAGEROUTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_ManageRoutes
{
public:
    QWidget *centralwidget;
    QListWidget *routeList;
    QPushButton *remove;
    QComboBox *truckSelection;
    QListWidget *locationList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *routeNumber;
    QLabel *locationCount;
    QLabel *itemCount;
    QLabel *truckCapacity;
    QLabel *currentCapacity;
    QListWidget *selectedLocations;
    QPushButton *removeFromSelected;
    QTextEdit *addRouteNumber;
    QPushButton *addToList;
    QPushButton *generateRouteInformation;
    QPushButton *generateLoadingOrder;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageRoutes)
    {
        if (ManageRoutes->objectName().isEmpty())
            ManageRoutes->setObjectName(QString::fromUtf8("ManageRoutes"));
        ManageRoutes->resize(800, 600);
        centralwidget = new QWidget(ManageRoutes);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        routeList = new QListWidget(centralwidget);
        routeList->setObjectName(QString::fromUtf8("routeList"));
        routeList->setGeometry(QRect(10, 10, 261, 511));
        remove = new QPushButton(centralwidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(10, 530, 261, 24));
        truckSelection = new QComboBox(centralwidget);
        truckSelection->setObjectName(QString::fromUtf8("truckSelection"));
        truckSelection->setGeometry(QRect(540, 11, 211, 31));
        locationList = new QListWidget(centralwidget);
        locationList->setObjectName(QString::fromUtf8("locationList"));
        locationList->setGeometry(QRect(310, 60, 221, 192));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 300, 221, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(530, 300, 221, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        routeNumber = new QLabel(verticalLayoutWidget_2);
        routeNumber->setObjectName(QString::fromUtf8("routeNumber"));
        routeNumber->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(routeNumber);

        locationCount = new QLabel(verticalLayoutWidget_2);
        locationCount->setObjectName(QString::fromUtf8("locationCount"));
        locationCount->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(locationCount);

        itemCount = new QLabel(verticalLayoutWidget_2);
        itemCount->setObjectName(QString::fromUtf8("itemCount"));
        itemCount->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(itemCount);

        truckCapacity = new QLabel(verticalLayoutWidget_2);
        truckCapacity->setObjectName(QString::fromUtf8("truckCapacity"));
        truckCapacity->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(truckCapacity);

        currentCapacity = new QLabel(verticalLayoutWidget_2);
        currentCapacity->setObjectName(QString::fromUtf8("currentCapacity"));
        currentCapacity->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(currentCapacity);

        selectedLocations = new QListWidget(centralwidget);
        selectedLocations->setObjectName(QString::fromUtf8("selectedLocations"));
        selectedLocations->setGeometry(QRect(530, 60, 221, 192));
        removeFromSelected = new QPushButton(centralwidget);
        removeFromSelected->setObjectName(QString::fromUtf8("removeFromSelected"));
        removeFromSelected->setGeometry(QRect(680, 260, 71, 24));
        addRouteNumber = new QTextEdit(centralwidget);
        addRouteNumber->setObjectName(QString::fromUtf8("addRouteNumber"));
        addRouteNumber->setGeometry(QRect(310, 10, 211, 31));
        addToList = new QPushButton(centralwidget);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(310, 530, 101, 24));
        generateRouteInformation = new QPushButton(centralwidget);
        generateRouteInformation->setObjectName(QString::fromUtf8("generateRouteInformation"));
        generateRouteInformation->setGeometry(QRect(420, 530, 171, 24));
        generateLoadingOrder = new QPushButton(centralwidget);
        generateLoadingOrder->setObjectName(QString::fromUtf8("generateLoadingOrder"));
        generateLoadingOrder->setGeometry(QRect(600, 530, 151, 24));
        ManageRoutes->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManageRoutes);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ManageRoutes->setMenuBar(menubar);
        statusbar = new QStatusBar(ManageRoutes);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManageRoutes->setStatusBar(statusbar);

        retranslateUi(ManageRoutes);

        QMetaObject::connectSlotsByName(ManageRoutes);
    } // setupUi

    void retranslateUi(QMainWindow *ManageRoutes)
    {
        ManageRoutes->setWindowTitle(QCoreApplication::translate("ManageRoutes", "Manage Routes", nullptr));
        remove->setText(QCoreApplication::translate("ManageRoutes", "Remove", nullptr));
        truckSelection->setPlaceholderText(QCoreApplication::translate("ManageRoutes", "Select Truck", nullptr));
        label->setText(QCoreApplication::translate("ManageRoutes", "Route number:", nullptr));
        label_2->setText(QCoreApplication::translate("ManageRoutes", "Number of locations:", nullptr));
        label_3->setText(QCoreApplication::translate("ManageRoutes", "Total number of items:", nullptr));
        label_4->setText(QCoreApplication::translate("ManageRoutes", "Truck capacity:", nullptr));
        label_5->setText(QCoreApplication::translate("ManageRoutes", "Current capacity (after loading items):", nullptr));
        routeNumber->setText(QString());
        locationCount->setText(QString());
        itemCount->setText(QString());
        truckCapacity->setText(QString());
        currentCapacity->setText(QString());
        removeFromSelected->setText(QCoreApplication::translate("ManageRoutes", "Remove", nullptr));
        addRouteNumber->setPlaceholderText(QCoreApplication::translate("ManageRoutes", "Route Number", nullptr));
        addToList->setText(QCoreApplication::translate("ManageRoutes", "Add To List", nullptr));
        generateRouteInformation->setText(QCoreApplication::translate("ManageRoutes", "Generate Route Information", nullptr));
        generateLoadingOrder->setText(QCoreApplication::translate("ManageRoutes", "Generate Loading Order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageRoutes: public Ui_ManageRoutes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEROUTES_H
