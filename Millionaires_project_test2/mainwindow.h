#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Question.h"
#include <QMainWindow>
#include <QPushButton>
#include <string>
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fileopen();
    bool verifieanswer();
    void close();
    Question q1;
    int wartosc[11];
     string odpowiedz;
     QString text;
     QString pola;
     QString polb;
     QString polc;
     QString pold;


private:
    Ui::MainWindow *ui;
    //int const EXIT_CODE_REBOOT = -123456789;

private slots:

    void won();
    void winning();//do zrobienia
    void lost();
    void giveup();
    void nextquestion();
    void start();
    void random_question();

    void on_ButtonD_clicked();
    void on_ButtonA_clicked();
    void on_ButtonC_clicked();
    void on_ButtonB_clicked();
    //kola ratunkowe
    void pytanie();
    void polowa();
    void telefon();
    //guziki od kola ratunkowetp
    void on_ButtonPub_clicked();
    void on_pushButton_clicked();
    void on_ButtonCall_clicked();
    void on_ButtonFifty_clicked();
};


#endif // MAINWINDOW_H
