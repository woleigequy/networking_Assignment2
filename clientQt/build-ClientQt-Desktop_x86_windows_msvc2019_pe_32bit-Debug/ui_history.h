/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_search;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_endDate;
    QLabel *label_to;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QString::fromUtf8("history"));
        history->resize(1200, 664);
        history->setStyleSheet(QString::fromUtf8("background-color: 245, 245, 245;"));
        centralwidget = new QWidget(history);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 40, 281, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara"));
        font.setPointSize(11);
        comboBox->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 80, 281, 20));
        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(70, 140, 80, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Candara"));
        font1.setPointSize(10);
        pushButton_search->setFont(font1);
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(70, 110, 110, 22));
        dateEdit_endDate = new QDateEdit(centralwidget);
        dateEdit_endDate->setObjectName(QString::fromUtf8("dateEdit_endDate"));
        dateEdit_endDate->setGeometry(QRect(210, 110, 110, 22));
        label_to = new QLabel(centralwidget);
        label_to->setObjectName(QString::fromUtf8("label_to"));
        label_to->setGeometry(QRect(180, 110, 31, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font2.setPointSize(16);
        label_to->setFont(font2);
        label_to->setAlignment(Qt::AlignCenter);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 40, 811, 591));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(10);
        textBrowser->setFont(font3);
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5)"));
        history->setCentralWidget(centralwidget);
        menubar = new QMenuBar(history);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        history->setMenuBar(menubar);
        statusbar = new QStatusBar(history);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        history->setStatusBar(statusbar);

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QMainWindow *history)
    {
        history->setWindowTitle(QCoreApplication::translate("history", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("history", "Search by nickname", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("history", "Search by room number", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("history", "Search by nickname keyword", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("history", "Search by content keyword", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("history", "Search by date", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("history", "Search by date period", nullptr));

        pushButton_search->setText(QCoreApplication::translate("history", "Search", nullptr));
        label_to->setText(QCoreApplication::translate("history", "~", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
