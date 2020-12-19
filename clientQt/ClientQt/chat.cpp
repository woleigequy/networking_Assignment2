#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    ui->textEdit->setFocus();
    ui->pushButton_send->setShortcut(QKeySequence("Ctrl+Enter"));//combo keys:组合键
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButton_send_clicked()
{

}

void chat::on_pushButton_quit_clicked()
{
    emit sendsignal();
    close();
}



