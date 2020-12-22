/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_quit;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *pushButton_send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName(QString::fromUtf8("chat"));
        chat->resize(1138, 709);
        chat->setStyleSheet(QString::fromUtf8("background-color: 245, 245, 245;\n"
"background-image: url(:/img/img/pink.png);"));
        centralwidget = new QWidget(chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(10, 10, 80, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        pushButton_quit->setFont(font);
        pushButton_quit->setStyleSheet(QString::fromUtf8("pushButton_quit->setStyleSheet(\"border:2px groove gray;border-radius:20px;padding:2px 4px;\");"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 1121, 391));
        textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 420, 1121, 201));
        textEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.5)"));
        pushButton_send = new QPushButton(centralwidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(1040, 630, 80, 20));
        pushButton_send->setFont(font);
        chat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1138, 21));
        chat->setMenuBar(menubar);
        statusbar = new QStatusBar(chat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/w.png);"));
        chat->setStatusBar(statusbar);

        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QMainWindow *chat)
    {
        chat->setWindowTitle(QCoreApplication::translate("chat", "MainWindow", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("chat", "Quit", nullptr));
        pushButton_send->setText(QCoreApplication::translate("chat", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
