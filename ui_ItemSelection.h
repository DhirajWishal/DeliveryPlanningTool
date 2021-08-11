/********************************************************************************
** Form generated from reading UI file 'ItemSelection.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMSELECTION_H
#define UI_ITEMSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemSelection
{
public:
    QWidget *centralwidget;
    QLabel *locationTitle;
    QListWidget *itemList;
    QListWidget *selectedItems;
    QLabel *totalSize;
    QTextEdit *quantity;
    QLabel *ItemSize;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *addToList;
    QPushButton *remove;
    QLabel *itemName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ItemSelection)
    {
        if (ItemSelection->objectName().isEmpty())
            ItemSelection->setObjectName(QString::fromUtf8("ItemSelection"));
        ItemSelection->resize(800, 600);
        centralwidget = new QWidget(ItemSelection);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        locationTitle = new QLabel(centralwidget);
        locationTitle->setObjectName(QString::fromUtf8("locationTitle"));
        locationTitle->setGeometry(QRect(10, 10, 301, 41));
        QFont font;
        font.setPointSize(20);
        locationTitle->setFont(font);
        itemList = new QListWidget(centralwidget);
        itemList->setObjectName(QString::fromUtf8("itemList"));
        itemList->setGeometry(QRect(10, 70, 261, 481));
        selectedItems = new QListWidget(centralwidget);
        selectedItems->setObjectName(QString::fromUtf8("selectedItems"));
        selectedItems->setGeometry(QRect(520, 70, 261, 481));
        totalSize = new QLabel(centralwidget);
        totalSize->setObjectName(QString::fromUtf8("totalSize"));
        totalSize->setGeometry(QRect(280, 530, 231, 20));
        QFont font1;
        font1.setPointSize(12);
        totalSize->setFont(font1);
        totalSize->setAlignment(Qt::AlignCenter);
        quantity = new QTextEdit(centralwidget);
        quantity->setObjectName(QString::fromUtf8("quantity"));
        quantity->setGeometry(QRect(303, 200, 181, 31));
        ItemSize = new QLabel(centralwidget);
        ItemSize->setObjectName(QString::fromUtf8("ItemSize"));
        ItemSize->setGeometry(QRect(280, 150, 231, 20));
        ItemSize->setFont(font1);
        ItemSize->setAlignment(Qt::AlignCenter);
        okButton = new QPushButton(centralwidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(700, 20, 81, 24));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(610, 20, 81, 24));
        addToList = new QPushButton(centralwidget);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(300, 270, 181, 24));
        remove = new QPushButton(centralwidget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(300, 310, 181, 24));
        itemName = new QLabel(centralwidget);
        itemName->setObjectName(QString::fromUtf8("itemName"));
        itemName->setGeometry(QRect(280, 110, 231, 20));
        itemName->setFont(font1);
        itemName->setAlignment(Qt::AlignCenter);
        ItemSelection->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ItemSelection);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ItemSelection->setMenuBar(menubar);
        statusbar = new QStatusBar(ItemSelection);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ItemSelection->setStatusBar(statusbar);

        retranslateUi(ItemSelection);

        QMetaObject::connectSlotsByName(ItemSelection);
    } // setupUi

    void retranslateUi(QMainWindow *ItemSelection)
    {
        ItemSelection->setWindowTitle(QCoreApplication::translate("ItemSelection", "Item Selection", nullptr));
        locationTitle->setText(QString());
        totalSize->setText(QString());
        quantity->setPlaceholderText(QCoreApplication::translate("ItemSelection", "Set the quantity", nullptr));
        ItemSize->setText(QString());
        okButton->setText(QCoreApplication::translate("ItemSelection", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("ItemSelection", "Cancel", nullptr));
        addToList->setText(QCoreApplication::translate("ItemSelection", "Add", nullptr));
        remove->setText(QCoreApplication::translate("ItemSelection", "Remove", nullptr));
        itemName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ItemSelection: public Ui_ItemSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMSELECTION_H
