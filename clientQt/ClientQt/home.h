#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "username.h"
#include "lib_static.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Home *ui;
    username *uname;
};
#endif // HOME_H
