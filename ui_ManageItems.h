/********************************************************************************
** Form generated from reading UI file 'ManageItems.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEITEMS_H
#define UI_MANAGEITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageItems
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageItems)
    {
        if (ManageItems->objectName().isEmpty())
            ManageItems->setObjectName(QString::fromUtf8("ManageItems"));
        ManageItems->resize(800, 600);
        centralwidget = new QWidget(ManageItems);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ManageItems->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManageItems);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ManageItems->setMenuBar(menubar);
        statusbar = new QStatusBar(ManageItems);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManageItems->setStatusBar(statusbar);

        retranslateUi(ManageItems);

        QMetaObject::connectSlotsByName(ManageItems);
    } // setupUi

    void retranslateUi(QMainWindow *ManageItems)
    {
        ManageItems->setWindowTitle(QCoreApplication::translate("ManageItems", "Manage Items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageItems: public Ui_ManageItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEITEMS_H
