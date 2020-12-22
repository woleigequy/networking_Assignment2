/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_home;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QString::fromUtf8("Home"));
        Home->resize(520, 449);
        Home->setStyleSheet(QString::fromUtf8("background-color: 245, 245, 245;"));
        centralwidget = new QWidget(Home);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 90, 361, 231));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_home = new QLabel(layoutWidget);
        label_home->setObjectName(QString::fromUtf8("label_home"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(20);
        label_home->setFont(font);
        label_home->setLayoutDirection(Qt::LeftToRight);
        label_home->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        label_home->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_home);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_address = new QLabel(layoutWidget);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        label_address->setFont(font1);
        label_address->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));

        horizontalLayout->addWidget(label_address);

        lineEdit_address = new QLineEdit(layoutWidget);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));

        horizontalLayout->addWidget(lineEdit_address);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(65, 65, 65);color:white;"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        Home->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Home);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 520, 21));
        Home->setMenuBar(menubar);
        statusbar = new QStatusBar(Home);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        Home->setStatusBar(statusbar);

        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QMainWindow *Home)
    {
        Home->setWindowTitle(QCoreApplication::translate("Home", "Home", nullptr));
        label_home->setText(QCoreApplication::translate("Home", "Home Page", nullptr));
        label_address->setText(QCoreApplication::translate("Home", "Hostname/IP", nullptr));
        pushButton->setText(QCoreApplication::translate("Home", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
