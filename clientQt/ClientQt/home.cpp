#include "home.h"
#include "ui_home.h"
#include <QPixmap>
#include "connectMySQL.h"
#include "serverConnect.h"
#include <string.h>
#include <string>

using namespace std;

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

	if (!connectMySQL())
	{
		ui->statusbar->showMessage("database connect failure");
		/*printf("connect failure: \n");
		fprintf(stderr, " %s\n", mysql_error(&mysql));
		exit(1);*/
	}
	else
	{
		ui->statusbar->showMessage("database connect successfully",2000);
		//fprintf(stderr, "MySQL connect！succeed！\n");
	}
}

Home::~Home()
{
    delete ui;
}



void Home::on_pushButton_clicked()
{
    QString address = ui->lineEdit_address->text();
    string StdAddress = address.toStdString();
    int status = initConnect(&StdAddress[0]);
    if(status==0){
        hide();
        uname = new username(this);
        connect(uname,SIGNAL(sendsignal()),this,SLOT(show()));
        uname->show();
        //show();
    }
    else if (status==-2) {
        ui->statusbar->showMessage("WSAStartup failed", 5000);
    }else {
        ui->statusbar->showMessage("please check your Hostname or IP address",5000);
    }
}

