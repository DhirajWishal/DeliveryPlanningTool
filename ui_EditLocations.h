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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditLocations
{
public:
    QPushButton *addToList;
    QTextEdit *locationName;
    QListWidget *locationList;
    QPushButton *removeButton;

    void setupUi(QWidget *EditLocations)
    {
        if (EditLocations->objectName().isEmpty())
            EditLocations->setObjectName(QString::fromUtf8("EditLocations"));
        EditLocations->resize(777, 562);
        addToList = new QPushButton(EditLocations);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(480, 260, 91, 24));
        locationName = new QTextEdit(EditLocations);
        locationName->setObjectName(QString::fromUtf8("locationName"));
        locationName->setGeometry(QRect(360, 210, 331, 31));
        locationList = new QListWidget(EditLocations);
        locationList->setObjectName(QString::fromUtf8("locationList"));
        locationList->setGeometry(QRect(10, 11, 261, 511));
        removeButton = new QPushButton(EditLocations);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(10, 530, 261, 24));

        retranslateUi(EditLocations);

        QMetaObject::connectSlotsByName(EditLocations);
    } // setupUi

    void retranslateUi(QWidget *EditLocations)
    {
        EditLocations->setWindowTitle(QCoreApplication::translate("EditLocations", "Edit Locations", nullptr));
        addToList->setText(QCoreApplication::translate("EditLocations", "Add To List", nullptr));
        locationName->setPlaceholderText(QCoreApplication::translate("EditLocations", "Location/ Shop name", nullptr));
        removeButton->setText(QCoreApplication::translate("EditLocations", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditLocations: public Ui_EditLocations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONS_H
