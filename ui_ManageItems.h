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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageItems
{
public:
    QPushButton *addToList;
    QTextEdit *itemSize;
    QTextEdit *itemName;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelItemName;
    QLabel *labelItemSize;
    QPushButton *removeButton;
    QListWidget *itemList;

    void setupUi(QWidget *ManageItems)
    {
        if (ManageItems->objectName().isEmpty())
            ManageItems->setObjectName(QString::fromUtf8("ManageItems"));
        ManageItems->resize(781, 561);
        addToList = new QPushButton(ManageItems);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(460, 130, 121, 24));
        itemSize = new QTextEdit(ManageItems);
        itemSize->setObjectName(QString::fromUtf8("itemSize"));
        itemSize->setGeometry(QRect(290, 80, 471, 31));
        itemName = new QTextEdit(ManageItems);
        itemName->setObjectName(QString::fromUtf8("itemName"));
        itemName->setGeometry(QRect(290, 30, 471, 31));
        verticalLayoutWidget = new QWidget(ManageItems);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(289, 250, 471, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        labelItemName = new QLabel(verticalLayoutWidget);
        labelItemName->setObjectName(QString::fromUtf8("labelItemName"));
        labelItemName->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelItemName);

        labelItemSize = new QLabel(verticalLayoutWidget);
        labelItemSize->setObjectName(QString::fromUtf8("labelItemSize"));
        labelItemSize->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelItemSize);

        removeButton = new QPushButton(ManageItems);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(10, 530, 261, 24));
        itemList = new QListWidget(ManageItems);
        itemList->setObjectName(QString::fromUtf8("itemList"));
        itemList->setGeometry(QRect(10, 10, 261, 511));

        retranslateUi(ManageItems);

        QMetaObject::connectSlotsByName(ManageItems);
    } // setupUi

    void retranslateUi(QWidget *ManageItems)
    {
        ManageItems->setWindowTitle(QCoreApplication::translate("ManageItems", "Manage Items", nullptr));
        addToList->setText(QCoreApplication::translate("ManageItems", "Add To List", nullptr));
        itemSize->setPlaceholderText(QCoreApplication::translate("ManageItems", "Size of the package (cubic meters)", nullptr));
        itemName->setPlaceholderText(QCoreApplication::translate("ManageItems", "Item Name", nullptr));
        label->setText(QCoreApplication::translate("ManageItems", "Item Information", nullptr));
        labelItemName->setText(QString());
        labelItemSize->setText(QString());
        removeButton->setText(QCoreApplication::translate("ManageItems", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageItems: public Ui_ManageItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEITEMS_H
