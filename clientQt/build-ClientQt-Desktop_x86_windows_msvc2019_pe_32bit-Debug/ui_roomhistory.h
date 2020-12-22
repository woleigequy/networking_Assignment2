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
    QWidget *layoutWidget;
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
        roomHistory->resize(483, 380);
        roomHistory->setStyleSheet(QString::fromUtf8("background-color: 245, 245, 245;"));
        centralwidget = new QWidget(roomHistory);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        pushButton_back = new QPushButton(centralwidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setGeometry(QRect(0, 0, 80, 20));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 150, 178, 52));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        pushButton_comfirm = new QPushButton(layoutWidget);
        pushButton_comfirm->setObjectName(QString::fromUtf8("pushButton_comfirm"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        pushButton_comfirm->setFont(font1);

        gridLayout->addWidget(pushButton_comfirm, 1, 0, 1, 1);

        pushButton_history = new QPushButton(layoutWidget);
        pushButton_history->setObjectName(QString::fromUtf8("pushButton_history"));
        pushButton_history->setFont(font1);

        gridLayout->addWidget(pushButton_history, 1, 1, 1, 1);

        roomHistory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(roomHistory);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 483, 21));
        roomHistory->setMenuBar(menubar);
        statusbar = new QStatusBar(roomHistory);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        roomHistory->setStatusBar(statusbar);

        retranslateUi(roomHistory);

        QMetaObject::connectSlotsByName(roomHistory);
    } // setupUi

    void retranslateUi(QMainWindow *roomHistory)
    {
        roomHistory->setWindowTitle(QCoreApplication::translate("roomHistory", "MainWindow", nullptr));
        pushButton_back->setText(QCoreApplication::translate("roomHistory", "back", nullptr));
        label->setText(QCoreApplication::translate("roomHistory", "Roomnumber", nullptr));
        pushButton_comfirm->setText(QCoreApplication::translate("roomHistory", "comfirm", nullptr));
        pushButton_history->setText(QCoreApplication::translate("roomHistory", "history", nullptr));
    } // retranslateUi

};

namespace Ui {
    class roomHistory: public Ui_roomHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMHISTORY_H
