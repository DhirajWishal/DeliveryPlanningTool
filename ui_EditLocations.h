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
#include <QtWidgets/QLabel>
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
    QTextEdit *address;
    QLabel *label;
    QLabel *labelAddress;

    void setupUi(QWidget *EditLocations)
    {
        if (EditLocations->objectName().isEmpty())
            EditLocations->setObjectName(QString::fromUtf8("EditLocations"));
        EditLocations->resize(777, 562);
        addToList = new QPushButton(EditLocations);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(470, 220, 91, 24));
        locationName = new QTextEdit(EditLocations);
        locationName->setObjectName(QString::fromUtf8("locationName"));
        locationName->setGeometry(QRect(350, 80, 331, 31));
        locationList = new QListWidget(EditLocations);
        locationList->setObjectName(QString::fromUtf8("locationList"));
        locationList->setGeometry(QRect(10, 11, 261, 511));
        removeButton = new QPushButton(EditLocations);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(10, 530, 261, 24));
        address = new QTextEdit(EditLocations);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(350, 130, 331, 71));
        label = new QLabel(EditLocations);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 270, 329, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        labelAddress = new QLabel(EditLocations);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));
        labelAddress->setGeometry(QRect(350, 330, 329, 221));
        labelAddress->setTextFormat(Qt::AutoText);
        labelAddress->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelAddress->setWordWrap(true);

        retranslateUi(EditLocations);

        QMetaObject::connectSlotsByName(EditLocations);
    } // setupUi

    void retranslateUi(QWidget *EditLocations)
    {
        EditLocations->setWindowTitle(QCoreApplication::translate("EditLocations", "Edit Locations", nullptr));
        addToList->setText(QCoreApplication::translate("EditLocations", "Add To List", nullptr));
        locationName->setPlaceholderText(QCoreApplication::translate("EditLocations", "Location/ Shop name", nullptr));
        removeButton->setText(QCoreApplication::translate("EditLocations", "Remove", nullptr));
        address->setPlaceholderText(QCoreApplication::translate("EditLocations", "Address", nullptr));
        label->setText(QCoreApplication::translate("EditLocations", "Address:", nullptr));
        labelAddress->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditLocations: public Ui_EditLocations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONS_H
