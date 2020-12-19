#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>

namespace Ui {
class history;
}

class history : public QMainWindow
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_search_clicked();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
