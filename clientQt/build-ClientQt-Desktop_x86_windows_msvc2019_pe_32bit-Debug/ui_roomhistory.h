/********************************************************************************
** Form generated from reading UI file 'roomhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMHISTORY_H
#define UI_ROOMHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_roomHistory
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_back;
    QWidget *widget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_comfirm;
    QPushButton *pushButton_history;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *roomHistory)
    {
        if (roomHistory->objectName().isEmpty())
            roomHistory->setObjectName(QString::fromUtf8("roomHistory"));
        roomHistory->resize(1200, 700);
        centralwidget = new QWidget(roomHistory);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(0, 0, 80, 20));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 120, 178, 52));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        pushButton_comfirm = new QPushButton(widget);
        pushButton_comfirm->setObjectName(QString::fromUtf8("pushButton_comfirm"));

        gridLayout->addWidget(pushButton_comfirm, 1, 0, 1, 1);

        pushButton_history = new QPushButton(widget);
        pushButton_history->setObjectName(QString::fromUtf8("pushButton_history"));

        gridLayout->addWidget(pushButton_history, 1, 1, 1, 1);

        roomHistory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(roomHistory);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        roomHistory->setMenuBar(menubar);
        statusbar = new QStatusBar(roomHistory);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        roomHistory->setStatusBar(statusbar);

        retranslateUi(roomHistory);

        QMetaObject::connectSlotsByName(roomHistory);
    } // setupUi

    void retranslateUi(QMainWindow *roomHistory)
    {
        roomHistory->setWindowTitle(QCoreApplication::translate("roomHistory", "MainWindow", nullptr));
        pushButton_back->setText(QCoreApplication::translate("roomHistory", "back", nullptr));
        label->setText(QCoreApplication::translate("roomHistory", "roomnumber", nullptr));
        pushButton_comfirm->setText(QCoreApplication::translate("roomHistory", "comfirm", nullptr));
        pushButton_history->setText(QCoreApplication::translate("roomHistory", "history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomHistory: public Ui_roomHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMHISTORY_H
