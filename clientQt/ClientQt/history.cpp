#include "history.h"
#include "ui_history.h"
#include "connectMySQL.h"
#include <QComboBox>
#include <QScrollBar>


using namespace std;

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
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_endDate->setDate(QDate::currentDate());
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
            ui->lineEdit->show();
            ui->dateEdit->hide();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 4:
            ui->lineEdit->hide();
            ui->dateEdit->show();
            ui->dateEdit_endDate->hide();
            ui->label_to->hide();
            break;
        case 5:
            ui->lineEdit->hide();
            ui->dateEdit->show();
            ui->dateEdit_endDate->show();
            ui->label_to->show();
            break;
    }


}

void history::on_pushButton_search_clicked()
{
    ui->textBrowser->clear();
    int index = ui->comboBox->currentIndex();
    string input = "";
    string input2 = "";//using in date period
    string result = "";
    char temp[100000];

    QDate date;
    QString year,month,day;
    
    switch (index)
    {
    case 0:
        input = ui->lineEdit->text().toStdString();
        searchByName(&input[0], temp);
        result = temp;
        ui->textBrowser->insertHtml(QString::fromStdString(result));
        ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        break;
    case 1:
        input = ui->lineEdit->text().toStdString();
        strcpy(temp,&input[0]);
        if (atoi(temp) == 0 || atoi(temp) == -1) {
            ui->statusbar->showMessage("please input an positive integer as the roomnumber",5000);
        }
        else {
            searchByRoomNumber(atoi(temp), temp);
            result = temp;
            ui->textBrowser->insertHtml(QString::fromStdString(result));
            ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        }
        break;
    case 2:
        input = ui->lineEdit->text().toStdString();
        searchBySenderKeyword(&input[0],temp);
        result = temp;
        ui->textBrowser->insertHtml(QString::fromStdString(result));
        ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        break;
    case 3:
        input = ui->lineEdit->text().toStdString();
        searchByContentKeyword(&input[0], temp);
        result = temp;
        ui->textBrowser->insertHtml(QString::fromStdString(result));
        ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        break;
    case 4:
        date = ui->dateEdit->date();
        year = QString::number(date.year());
        month = QString::number(date.month());      
        day = QString::number(date.day());
        input = (year + "-"+month+"-"+day).toStdString();
        searchByDate(&input[0], temp);
        result = temp;
        ui->textBrowser->insertHtml(QString::fromStdString(result));
        ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        break;
    case 5:
        date = ui->dateEdit->date();
        year = QString::number(date.year());
        month = QString::number(date.month());
        day = QString::number(date.day());
        input = (year + "-" + month + "-" + day).toStdString();
        date = ui->dateEdit_endDate->date();
        year = QString::number(date.year());
        month = QString::number(date.month());
        day = QString::number(date.day());
        input2 = (year + "-" + month + "-" + day).toStdString();
        searchByDatePeriod(&input[0], &input2[0], temp);
        result = temp;
        ui->textBrowser->insertHtml(QString::fromStdString(result));
        ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        break;
    default:
        break;
    }
}
