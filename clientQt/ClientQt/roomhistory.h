#ifndef ROOMHISTORY_H
#define ROOMHISTORY_H

#include <QMainWindow>
#include "history.h"
#include "chat.h"

namespace Ui {
class roomHistory;
}

class roomHistory : public QMainWindow
{
    Q_OBJECT

public:
    explicit roomHistory(QWidget *parent = nullptr);
    ~roomHistory();

private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_history_clicked();

    void on_pushButton_comfirm_clicked();

signals:
    void sendsignalun();
    void CloseSignal();
private:
    Ui::roomHistory *ui;
};

#endif // ROOMHISTORY_H
