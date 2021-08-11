/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QListWidget *itemList;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QFrame *line_3;
    QListWidget *locationList;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QFrame *line_4;
    QListWidget *truckList;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QFrame *line_5;
    QListWidget *routeList;
    QPushButton *manageRoute;
    QPushButton *manageItemsButton;
    QPushButton *manageTrucksButton;
    QPushButton *manageLocationsButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1121, 485);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(560, 10, 271, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        itemList = new QListWidget(verticalLayoutWidget);
        new QListWidgetItem(itemList);
        new QListWidgetItem(itemList);
        new QListWidgetItem(itemList);
        new QListWidgetItem(itemList);
        new QListWidgetItem(itemList);
        new QListWidgetItem(itemList);
        itemList->setObjectName(QString::fromUtf8("itemList"));

        verticalLayout->addWidget(itemList);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 9, 271, 391));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_3);

        line_3 = new QFrame(verticalLayoutWidget_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        locationList = new QListWidget(verticalLayoutWidget_2);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        new QListWidgetItem(locationList);
        locationList->setObjectName(QString::fromUtf8("locationList"));

        verticalLayout_2->addWidget(locationList);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(289, 9, 261, 391));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_4);

        line_4 = new QFrame(verticalLayoutWidget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        truckList = new QListWidget(verticalLayoutWidget_3);
        truckList->setObjectName(QString::fromUtf8("truckList"));

        verticalLayout_3->addWidget(truckList);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(840, 10, 271, 391));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_4->addWidget(label_5);

        line_5 = new QFrame(verticalLayoutWidget_4);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        routeList = new QListWidget(verticalLayoutWidget_4);
        routeList->setObjectName(QString::fromUtf8("routeList"));

        verticalLayout_4->addWidget(routeList);

        manageRoute = new QPushButton(centralwidget);
        manageRoute->setObjectName(QString::fromUtf8("manageRoute"));
        manageRoute->setGeometry(QRect(840, 410, 271, 31));
        manageItemsButton = new QPushButton(centralwidget);
        manageItemsButton->setObjectName(QString::fromUtf8("manageItemsButton"));
        manageItemsButton->setGeometry(QRect(560, 410, 269, 31));
        manageTrucksButton = new QPushButton(centralwidget);
        manageTrucksButton->setObjectName(QString::fromUtf8("manageTrucksButton"));
        manageTrucksButton->setGeometry(QRect(290, 410, 261, 31));
        manageLocationsButton = new QPushButton(centralwidget);
        manageLocationsButton->setObjectName(QString::fromUtf8("manageLocationsButton"));
        manageLocationsButton->setGeometry(QRect(10, 410, 271, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1121, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Manager's Panel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Items", nullptr));

        const bool __sortingEnabled = itemList->isSortingEnabled();
        itemList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = itemList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Vitamin B Cream", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = itemList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Aloe Vera Gel Tube", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = itemList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Gold Mask", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = itemList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Vitamin E Cream", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = itemList->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Vitamin C Cream", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = itemList->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "Moisturizer", nullptr));
        itemList->setSortingEnabled(__sortingEnabled);

        label_3->setText(QCoreApplication::translate("MainWindow", "Locations/ Shops", nullptr));

        const bool __sortingEnabled1 = locationList->isSortingEnabled();
        locationList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem6 = locationList->item(0);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "Geek World", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = locationList->item(1);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "Gee Beauty", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = locationList->item(2);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "MAC Cosmetics", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = locationList->item(3);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("MainWindow", "SEPHORA", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = locationList->item(4);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("MainWindow", "Sally Beauty", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = locationList->item(5);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("MainWindow", "Beauty Boutique By Shoppers Drug Mart", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = locationList->item(6);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("MainWindow", "Ronny Consmetics Store", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = locationList->item(7);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("MainWindow", "Seasons Cosmetics", nullptr));
        locationList->setSortingEnabled(__sortingEnabled1);

        label_4->setText(QCoreApplication::translate("MainWindow", "Registered Trucks", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Routes", nullptr));
        manageRoute->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        manageItemsButton->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        manageTrucksButton->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
        manageLocationsButton->setText(QCoreApplication::translate("MainWindow", "Manage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
