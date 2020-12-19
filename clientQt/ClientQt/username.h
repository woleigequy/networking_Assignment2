#ifndef USERNAME_H
#define USERNAME_H

#include <QMainWindow>
#include "roomhistory.h"

namespace Ui {
class username;
}

class username : public QMainWindow
{
    Q_OBJECT

public:
    explicit username(QWidget *parent = nullptr);
    ~username();

private slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_confirm_clicked();

signals:
    void sendsignal();
private:
    Ui::username *ui;
};

#endif // USERNAME_H
