#include "username.h"
#include "ui_username.h"
#include "serverConnect.h"

using namespace std;
username::username(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::username)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->pushButton_confirm->setShortcut( QKeySequence::InsertParagraphSeparator );
}

username::~username()
{
    delete ui;
}

void username::on_pushButton_exit_clicked()
{
    emit sendsignal();
    this->close();
}

void username::on_pushButton_confirm_clicked()
{
    QString nickname = ui->lineEdit->text();
    string nicknameS = nickname.toStdString();
    if(sendToServer(&nicknameS[0],1)==0){
        hide();
        roomHistory *rh = new roomHistory(this);
        connect(rh,SIGNAL(sendsignalun()),this,SLOT(show()));
        rh->show();
    }else{
        ui->statusbar->showMessage("please input your nickname",5000);
    }
}
