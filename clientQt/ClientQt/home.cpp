#include "home.h"
#include "ui_home.h"
#include <QPixmap>

Home::Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
//    QPixmap pix(":/img/img/18.png");
//    int w = ui->label_pic->width();
//    int h = ui->label_pic->height();
//    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));//Keep Aspect Ratio:保持长宽比
    //ui->pushButton->setFocus();
    ui->pushButton->setShortcut( QKeySequence::InsertParagraphSeparator );//enter trigger:回车触发
}

Home::~Home()
{
    delete ui;
}



void Home::on_pushButton_clicked()
{
    QString address = ui->lineEdit_address->text();
//    String StdAddress = address.toStdString();
    if(address == "127.0.0.1"){
        hide();
        uname = new username(this);
        connect(uname,SIGNAL(sendsignal()),this,SLOT(show()));
        uname->show();
        //show();
    }else{
        ui->statusbar->showMessage("please check your Hostname or IP address",5000);
    }
}

