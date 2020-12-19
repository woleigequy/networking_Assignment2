#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>

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
signals:
    void sendsignal();
private:
    Ui::chat *ui;
};



#endif // CHAT_H
