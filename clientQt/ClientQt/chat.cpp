#include "chat.h"
#include "ui_chat.h"
#include "serverConnect.h"
#include "QScrollBar"
#include "QtextCursor"
#include "Qcursor"

using namespace std;

char szBuff[buffSize];
char nickNameRec[16];

recThread::recThread(QObject* parent)
    : QThread(parent)
{

}


void recThread::run() {
    while (true) {
        if (recFromServer(szBuff, nickNameRec) != -1) {
            emit recInsertRequest();
        }
        //strcpy(szBuff, "");
        //strcpy(nickNameRec, "");
    }
}



chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    T = new recThread;
    T->start();
    connect(T,SIGNAL(recInsertRequest()),this,SLOT(insertMsgBox()));
    ui->textEdit->setFocus();
    ui->pushButton_send->setShortcut(QKeySequence("Ctrl+Enter"));//combo keys:组合键

}

chat::~chat()
{
    
    delete ui;
}

void chat::on_pushButton_send_clicked()
{
    QString sendMsg = ui->textEdit->toPlainText();
    string sendMsgS = sendMsg.toStdString();
    sendToServer(sendMsgS,4);
    string timeStamp = getCurrentTime();
    ui->textBrowser->moveCursor(QTextCursor::End);

    ui->textBrowser->insertHtml(QStringLiteral("<br><b><p align = 'right' style = 'margin:0; font-family:SimHei;'>")+QString::fromStdString(getNickname()) + QStringLiteral("</b></p><p align='right' style = 'margin:0; font-family:Century Gothic;'>") +QString::fromStdString(timeStamp) + QStringLiteral("</p><p align='right' style = 'margin:0; font-family:SimHei;'>"));
    ui->textBrowser->insertPlainText(sendMsg);
    ui->textBrowser->insertHtml("</p>");
    ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
    ui->textEdit->clear();
}

void chat::on_pushButton_quit_clicked()
{
    
    T->terminate();
    //char reset[10] = "0";
    string reset = "0";
    sendToServer(reset, 5);
    emit sendsignal();
    this->close();
}



void chat::insertMsgBox() {
    if (strcmp(szBuff,"")==0)
    {
        return;
    }
    string timeStamp = getCurrentTime();
    ui->textBrowser->moveCursor(QTextCursor::End);
    ui->textBrowser->insertHtml(QStringLiteral("<br><b><p align = 'left' style = 'margin:0; font-family:SimHei;'>") + QString(nickNameRec)+ QStringLiteral("</b></p><p align = 'left' style = 'margin:0; font-family:SimHei;'>") + QString::fromStdString(timeStamp) + QStringLiteral("</p><p align='left' style = 'margin:0; font-family:SimHei;'>"));
    ui->textBrowser->insertPlainText(QString(szBuff));
    ui->textBrowser->insertHtml("</p>");
    ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
}

