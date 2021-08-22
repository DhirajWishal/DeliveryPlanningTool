/********************************************************************************
** Form generated from reading UI file 'Chekout.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEKOUT_H
#define UI_CHEKOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Checkout
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QListWidget *routes;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *line_2;
    QListWidget *locations;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QFrame *line_3;
    QListWidget *items;
    QComboBox *truckSelect;
    QPushButton *generateDocuments;
    QLabel *dateLabel;
    QLabel *label_4;
    QLabel *itemsToDeliver;
    QLabel *label_5;
    QLabel *truckCapacity;
    QLabel *label_6;
    QLabel *totalLoad;
    QLabel *label_7;
    QLabel *estimatedTime;

    void setupUi(QWidget *Checkout)
    {
        if (Checkout->objectName().isEmpty())
            Checkout->setObjectName(QString::fromUtf8("Checkout"));
        Checkout->resize(777, 562);
        verticalLayoutWidget = new QWidget(Checkout);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 491));
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

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        routes = new QListWidget(verticalLayoutWidget);
        routes->setObjectName(QString::fromUtf8("routes"));

        verticalLayout->addWidget(routes);

        verticalLayoutWidget_2 = new QWidget(Checkout);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(180, 10, 160, 491));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        line_2 = new QFrame(verticalLayoutWidget_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        locations = new QListWidget(verticalLayoutWidget_2);
        locations->setObjectName(QString::fromUtf8("locations"));

        verticalLayout_2->addWidget(locations);

        verticalLayoutWidget_3 = new QWidget(Checkout);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(350, 10, 160, 491));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        line_3 = new QFrame(verticalLayoutWidget_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        items = new QListWidget(verticalLayoutWidget_3);
        items->setObjectName(QString::fromUtf8("items"));

        verticalLayout_3->addWidget(items);

        truckSelect = new QComboBox(Checkout);
        truckSelect->setObjectName(QString::fromUtf8("truckSelect"));
        truckSelect->setGeometry(QRect(540, 60, 221, 22));
        generateDocuments = new QPushButton(Checkout);
        generateDocuments->setObjectName(QString::fromUtf8("generateDocuments"));
        generateDocuments->setGeometry(QRect(544, 530, 221, 24));
        dateLabel = new QLabel(Checkout);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(540, 10, 221, 31));
        dateLabel->setFont(font);
        dateLabel->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Checkout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(540, 110, 121, 16));
        itemsToDeliver = new QLabel(Checkout);
        itemsToDeliver->setObjectName(QString::fromUtf8("itemsToDeliver"));
        itemsToDeliver->setGeometry(QRect(670, 110, 91, 16));
        label_5 = new QLabel(Checkout);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(540, 130, 121, 16));
        truckCapacity = new QLabel(Checkout);
        truckCapacity->setObjectName(QString::fromUtf8("truckCapacity"));
        truckCapacity->setGeometry(QRect(670, 130, 91, 16));
        label_6 = new QLabel(Checkout);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(540, 150, 121, 16));
        totalLoad = new QLabel(Checkout);
        totalLoad->setObjectName(QString::fromUtf8("totalLoad"));
        totalLoad->setGeometry(QRect(670, 150, 91, 16));
        label_7 = new QLabel(Checkout);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(540, 170, 121, 16));
        estimatedTime = new QLabel(Checkout);
        estimatedTime->setObjectName(QString::fromUtf8("estimatedTime"));
        estimatedTime->setGeometry(QRect(670, 170, 91, 16));

        retranslateUi(Checkout);

        QMetaObject::connectSlotsByName(Checkout);
    } // setupUi

    void retranslateUi(QWidget *Checkout)
    {
        Checkout->setWindowTitle(QCoreApplication::translate("Checkout", "Checkout", nullptr));
        label->setText(QCoreApplication::translate("Checkout", "Routes", nullptr));
        label_2->setText(QCoreApplication::translate("Checkout", "Locations", nullptr));
        label_3->setText(QCoreApplication::translate("Checkout", "Items", nullptr));
        truckSelect->setPlaceholderText(QCoreApplication::translate("Checkout", "Select Truck", nullptr));
        generateDocuments->setText(QCoreApplication::translate("Checkout", "Generate Checkout Documents", nullptr));
        dateLabel->setText(QCoreApplication::translate("Checkout", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("Checkout", "Total items to deliver:", nullptr));
        itemsToDeliver->setText(QString());
        label_5->setText(QCoreApplication::translate("Checkout", "Truck capacity:", nullptr));
        truckCapacity->setText(QString());
        label_6->setText(QCoreApplication::translate("Checkout", "Total load:", nullptr));
        totalLoad->setText(QString());
        label_7->setText(QCoreApplication::translate("Checkout", "Estimated time:", nullptr));
        estimatedTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Checkout: public Ui_Checkout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEKOUT_H
