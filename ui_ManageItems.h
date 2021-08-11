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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageItems
{
public:
    QWidget *centralwidget;
    QListWidget *itemList;
    QPushButton *removeButton;
    QTextEdit *itemName;
    QTextEdit *itemSize;
    QPushButton *addToList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *labelItemName;
    QLabel *labelItemSize;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageItems)
    {
        if (ManageItems->objectName().isEmpty())
            ManageItems->setObjectName(QString::fromUtf8("ManageItems"));
        ManageItems->resize(800, 600);
        centralwidget = new QWidget(ManageItems);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        itemList = new QListWidget(centralwidget);
        itemList->setObjectName(QString::fromUtf8("itemList"));
        itemList->setGeometry(QRect(10, 10, 256, 511));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(10, 530, 261, 24));
        itemName = new QTextEdit(centralwidget);
        itemName->setObjectName(QString::fromUtf8("itemName"));
        itemName->setGeometry(QRect(290, 30, 471, 31));
        itemSize = new QTextEdit(centralwidget);
        itemSize->setObjectName(QString::fromUtf8("itemSize"));
        itemSize->setGeometry(QRect(290, 80, 471, 31));
        addToList = new QPushButton(centralwidget);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(460, 130, 121, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(289, 280, 471, 80));
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
        removeButton->setText(QCoreApplication::translate("ManageItems", "Remove", nullptr));
        itemName->setPlaceholderText(QCoreApplication::translate("ManageItems", "Item Name", nullptr));
        itemSize->setPlaceholderText(QCoreApplication::translate("ManageItems", "Size of the package (cubic meters)", nullptr));
        addToList->setText(QCoreApplication::translate("ManageItems", "Add To List", nullptr));
        label->setText(QCoreApplication::translate("ManageItems", "Item Information", nullptr));
        labelItemName->setText(QString());
        labelItemSize->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ManageItems: public Ui_ManageItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEITEMS_H
