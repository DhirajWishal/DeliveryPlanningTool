/********************************************************************************
** Form generated from reading UI file 'CreateRoute.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEROUTE_H
#define UI_CREATEROUTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateRoute
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateRoute)
    {
        if (CreateRoute->objectName().isEmpty())
            CreateRoute->setObjectName(QString::fromUtf8("CreateRoute"));
        CreateRoute->resize(800, 600);
        centralwidget = new QWidget(CreateRoute);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CreateRoute->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateRoute);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        CreateRoute->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateRoute);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateRoute->setStatusBar(statusbar);

        retranslateUi(CreateRoute);

        QMetaObject::connectSlotsByName(CreateRoute);
    } // setupUi

    void retranslateUi(QMainWindow *CreateRoute)
    {
        CreateRoute->setWindowTitle(QCoreApplication::translate("CreateRoute", "Create Route", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateRoute: public Ui_CreateRoute {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROUTE_H
