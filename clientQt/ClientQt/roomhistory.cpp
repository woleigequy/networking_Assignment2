#include "roomhistory.h"
#include "ui_roomhistory.h"

history *his;

roomHistory::roomHistory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::roomHistory)
{
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->lineEdit->setFocus();
    ui->pushButton_comfirm->setShortcut(QKeySequence::InsertParagraphSeparator);
}

roomHistory::~roomHistory()
{
    delete ui;
}

void roomHistory::on_pushButton_back_clicked()
{

    if(his!=NULL){
        //his->setAttribute(Qt::WA_DeleteOnClose, true);
        //his->close();
        emit CloseSignal();
    }
    emit sendsignalun();
    close();
}


void roomHistory::on_pushButton_history_clicked()
{
    his = new history(this);
    his->show();
}

void roomHistory::on_pushButton_comfirm_clicked()
{
    QString roomNumber = ui->lineEdit->text();
    bool convertCheck;
    int roomNumberi = roomNumber.toInt(&convertCheck);
    if(convertCheck){
        if(roomNumberi>0){
            chat *c = new chat(this);
            hide();
            connect(c,SIGNAL(sendsignal()),this,SLOT(show()));
            c->show();
        }else{
            ui->statusbar->showMessage("please input an positive integer as the roomnumber",5000);
        }
    }else{
        ui->statusbar->showMessage("please input an positive integer as the roomnumber",5000);
    }
}
