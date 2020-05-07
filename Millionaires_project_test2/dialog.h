#ifndef DIALOG_H
#define DIALOG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
public slots:
    void pytanie(string a);
};

#endif // DIALOG_H
