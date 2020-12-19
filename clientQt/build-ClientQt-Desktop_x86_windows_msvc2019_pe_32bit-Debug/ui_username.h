/********************************************************************************
** Form generated from reading UI file 'username.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAME_H
#define UI_USERNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_username
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_exit;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_confirm;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *username)
    {
        if (username->objectName().isEmpty())
            username->setObjectName(QString::fromUtf8("username"));
        username->resize(1200, 700);
        centralwidget = new QWidget(username);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(0, 0, 80, 20));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 120, 164, 24));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        pushButton_confirm = new QPushButton(centralwidget);
        pushButton_confirm->setObjectName(QString::fromUtf8("pushButton_confirm"));
        pushButton_confirm->setGeometry(QRect(210, 160, 80, 20));
        username->setCentralWidget(centralwidget);
        menubar = new QMenuBar(username);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        username->setMenuBar(menubar);
        statusbar = new QStatusBar(username);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        username->setStatusBar(statusbar);

        retranslateUi(username);

        QMetaObject::connectSlotsByName(username);
    } // setupUi

    void retranslateUi(QMainWindow *username)
    {
        username->setWindowTitle(QCoreApplication::translate("username", "MainWindow", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("username", "back", nullptr));
        label->setText(QCoreApplication::translate("username", "Nickname", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("username", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class username: public Ui_username {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAME_H
