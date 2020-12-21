#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QThread>





class recThread : public QThread
{
    Q_OBJECT
public:
    explicit recThread(QObject* parent = nullptr);
    void run();
private:
signals:
    void recInsertRequest();

};


namespace Ui {
class chat;
}

class chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_quit_clicked();
    void insertMsgBox();

signals:
    void sendsignal();
    void getMsg();
private:
    Ui::chat *ui;
    recThread* T;
private:
    
};



#endif // CHAT_H
