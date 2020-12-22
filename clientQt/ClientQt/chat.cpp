#include "chat.h"
#include "ui_chat.h"
#include "serverConnect.h"
#include "QScrollBar"

using namespace std;

char szBuff[buffSize];
char nickNameRec[buffSize];

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
    int i = sendToServer(&sendMsgS[0],4);
    string timeStamp = getCurrentTime();
    ui->textBrowser->insertHtml(QStringLiteral("<br><p align = 'right' style = 'margin:0;'>")+QString::fromStdString(getNickname()) + QStringLiteral("<br>") +QString::fromStdString(timeStamp) + QStringLiteral("</p><p align='right' style = 'margin:0;'>"));
    ui->textBrowser->insertPlainText(sendMsg);
    ui->textBrowser->insertHtml("</p><p align='right' style='margin:0;'></p>");
    ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
    ui->textEdit->clear();
}

void chat::on_pushButton_quit_clicked()
{
    
    T->terminate();
    char reset[10] = "0";
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
    ui->textBrowser->insertHtml(QStringLiteral("<br><p align = 'left' style = 'margin:0;'>") + QString(nickNameRec)+ QStringLiteral("<br>") + QString::fromStdString(timeStamp) + QStringLiteral("</p><p align='left' style = 'margin:0;'>"));
    ui->textBrowser->insertPlainText(QString(szBuff));
    ui->textBrowser->insertHtml("</p><p align='left' style='margin:0;'></p>");
    ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
}

