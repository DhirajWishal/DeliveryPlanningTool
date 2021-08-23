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
    QTextEdit *latitude;
    QTextEdit *longitude;
    QLabel *label_2;
    QLabel *coordinates;

    void setupUi(QWidget *EditLocations)
    {
        if (EditLocations->objectName().isEmpty())
            EditLocations->setObjectName(QString::fromUtf8("EditLocations"));
        EditLocations->resize(777, 562);
        addToList = new QPushButton(EditLocations);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(470, 250, 91, 24));
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
        address->setGeometry(QRect(350, 120, 331, 71));
        label = new QLabel(EditLocations);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 290, 329, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        labelAddress = new QLabel(EditLocations);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));
        labelAddress->setGeometry(QRect(350, 330, 329, 151));
        labelAddress->setTextFormat(Qt::AutoText);
        labelAddress->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelAddress->setWordWrap(true);
        latitude = new QTextEdit(EditLocations);
        latitude->setObjectName(QString::fromUtf8("latitude"));
        latitude->setGeometry(QRect(350, 200, 161, 31));
        longitude = new QTextEdit(EditLocations);
        longitude->setObjectName(QString::fromUtf8("longitude"));
        longitude->setGeometry(QRect(520, 200, 161, 31));
        label_2 = new QLabel(EditLocations);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 490, 331, 31));
        label_2->setFont(font);
        coordinates = new QLabel(EditLocations);
        coordinates->setObjectName(QString::fromUtf8("coordinates"));
        coordinates->setGeometry(QRect(350, 525, 331, 21));

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
        latitude->setPlaceholderText(QCoreApplication::translate("EditLocations", "Latitude/ X", nullptr));
        longitude->setPlaceholderText(QCoreApplication::translate("EditLocations", "Longitude/ Y", nullptr));
        label_2->setText(QCoreApplication::translate("EditLocations", "Coordinates:", nullptr));
        coordinates->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditLocations: public Ui_EditLocations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLOCATIONS_H
