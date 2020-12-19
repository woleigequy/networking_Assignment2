#include "history.h"
#include "ui_history.h"
#include <QComboBox>

history::history(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    //ui->lineEdit->hide();
    ui->dateEdit->hide();
    ui->dateEdit_endDate->hide();
    ui->label_to->hide();
    connect(parent,SIGNAL(CloseSignal()),this,SLOT(close()));
}

history::~history()
{
    delete ui;
}

void history::on_comboBox_currentIndexChanged(int index)
{

    //ui->statusbar->showMessage(QString::number(index));
    switch (index) {
        case 0:
            ui->lineEdit->show();
            ui->dateEdit->hide();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 1:
            ui->lineEdit->show();
            ui->dateEdit->hide();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 2:
            ui->lineEdit->show();
            ui->dateEdit->hide();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 3:
            ui->lineEdit->hide();
            ui->dateEdit->show();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 4:
            ui->lineEdit->hide();
            ui->dateEdit->show();
            ui->dateEdit_endDate->show();
            ui->label_to->show();
            break;
    }


}

void history::on_pushButton_search_clicked()
{

}
