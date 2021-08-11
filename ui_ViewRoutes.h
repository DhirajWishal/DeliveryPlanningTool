/********************************************************************************
** Form generated from reading UI file 'ViewRoutes.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWROUTES_H
#define UI_VIEWROUTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewRoutes
{
public:
    QListWidget *routeList;
    QPushButton *manage;

    void setupUi(QWidget *ViewRoutes)
    {
        if (ViewRoutes->objectName().isEmpty())
            ViewRoutes->setObjectName(QString::fromUtf8("ViewRoutes"));
        ViewRoutes->resize(781, 560);
        routeList = new QListWidget(ViewRoutes);
        routeList->setObjectName(QString::fromUtf8("routeList"));
        routeList->setGeometry(QRect(10, 10, 261, 511));
        manage = new QPushButton(ViewRoutes);
        manage->setObjectName(QString::fromUtf8("manage"));
        manage->setGeometry(QRect(300, 240, 451, 24));

        retranslateUi(ViewRoutes);

        QMetaObject::connectSlotsByName(ViewRoutes);
    } // setupUi

    void retranslateUi(QWidget *ViewRoutes)
    {
        ViewRoutes->setWindowTitle(QCoreApplication::translate("ViewRoutes", "View Routes", nullptr));
        manage->setText(QCoreApplication::translate("ViewRoutes", "Manage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewRoutes: public Ui_ViewRoutes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWROUTES_H
