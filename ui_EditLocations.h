/********************************************************************************
** Form generated from reading UI file 'EditLocations.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLOCATIONS_H
#define UI_EDITLOCATIONS_H

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

class Ui_EditLocations
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *removeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditLocations)
    {
        if (EditLocations->objectName().isEmpty())
            EditLocations->setObjectName(QString::fromUtf8("EditLocations"));
        EditLocations->resize(800, 600);
        centralwidget = new QWidget(EditLocations);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 11, 331, 501));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(400, 80, 351, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(534, 150, 101, 24));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(10, 520, 331, 24));
        EditLocations->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditLocations);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        EditLocations->setMenuBar(menubar);
        statusbar = new QStatusBar(EditLocations);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EditLocations->setStatusBar(statusbar);

        retranslateUi(EditLocations);

        QMetaObject::connectSlotsByName(EditLocations);
    } // setupUi

    void retranslateUi(QMainWindow *EditLocations)
    {
        EditLocations->setWindowTitle(QCoreApplication::translate("EditLocations", "Edit Locations", nullptr));
        pushButton->setText(QCoreApplication::translate("EditLocations", "Add To List", nullptr));
        removeButton->setText(QCoreApplication::translate("EditLocations", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditLocations: public Ui_EditLocations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONS_H
