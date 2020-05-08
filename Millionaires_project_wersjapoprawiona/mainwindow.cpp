#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <QString>
#include <QTextStream>
#include "Question.h"
#include <QMessageBox>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

start();

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::fileopen()
{
random_question();
    string filee;
    fstream file;
    file.open("C:\\Users\\Wee\\Desktop\\pytaniatest1.txt",std::ios::in);
    for(int i=0; i<wartosc[i];i++)//i zamieniamy na numer pytania*3 i wczytuje tylko linie odpowiedniego pytania
    {
       getline(file,filee);
       q1.question=filee;
       getline(file,filee);
       q1.answera=filee;
       getline(file,filee);
       q1.answerb=filee;
       getline(file,filee);
       q1.answerc=filee;
       getline(file,filee);
       q1.answerd=filee;
       getline(file,filee);
       q1.correct=filee;
        ui->QuestionTextBox->setText(QString::fromStdString(q1.question));
        ui->ButtonD->setText(QString::fromStdString(q1.answerd));
        ui->ButtonA->setText(QString::fromStdString(q1.answera));
        ui->ButtonC->setText(QString::fromStdString(q1.answerc));
        ui->ButtonB->setText(QString::fromStdString(q1.answerb));
        QString anss = QString::fromStdString(q1.correct);
        text = QString("Proponowana odpwoiedz to: %1").arg(anss);
        pola = QString("Proponowana odpwoiedz to: A i %1").arg(anss);//odpowedzi w procentach
        polb = QString("Proponowana odpwoiedz to: B i %1").arg(anss);
        polc = QString("Proponowana odpwoiedz to: C i %1").arg(anss);
        pold = QString("Proponowana odpwoiedz to: D i %1").arg(anss);
    }

}
bool MainWindow::verifieanswer()
{

if(q1.correct==q1.users_answer)
{
    return 1;
}
else
{
    return 0;
}
}



void MainWindow::on_ButtonD_clicked()
{

  q1.users_answer = "D";
  nextquestion();

}

void MainWindow::on_ButtonA_clicked()
{

     q1.users_answer = "A";
     nextquestion();
}

void MainWindow::on_ButtonC_clicked()
{

     q1.users_answer = "C";
     nextquestion();
}

void MainWindow::on_ButtonB_clicked()
{

     q1.users_answer = "B";
     nextquestion();
}
void MainWindow::nextquestion()
{
    if(verifieanswer())
    {
        q1.score++;
        winning();
fileopen();
    }
    else
    {
        lost();
    }
}
void MainWindow::start()
{
//    ui->TextAccount->setStyleSheet("font: 9pt;");       // nie potrzebne już, można usunąć
//    ui->TextAccount->setText("0zl");                    //
    fileopen();
}
void MainWindow::random_question()
{
    for (int i=0;i<6;i++)
    {
        qsrand(time(NULL));
        int liczba=qrand() % 10;
        wartosc[i]=liczba; //wpisuje liczbe do tabeli
    }

}
void MainWindow::lost()
{

    if(q1.score<=1)
    {
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this," ","Niestety nic nie wygrywasz. Czy chcesz zagrac ponownie?",QMessageBox::Yes | QMessageBox::No );
       if(reply==QMessageBox::No)
       {
            QWidget::close();

       }
       else
       {

           qApp->quit();
           QProcess::startDetached(qApp->arguments()[0], qApp->arguments()); //uruchamia ponownie giere
           QMessageBox::Close;

       }

    }
    if(q1.score>=2&&q1.score<7)
    {
        QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this," ","Wygrywasz bezpieczna kwote 1 000zl. Czy chcesz zagrac ponownie?",QMessageBox::Yes | QMessageBox::No );
       if(reply==QMessageBox::No)
       {
            QWidget::close();

       }
       else
       {
           qApp->quit();
           QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
           QMessageBox::Close;

       }

    }
    if(q1.score>=7&&q1.score<12)
    {
        QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this," ","Wygrywasz bezpieczna kwote 40 000zl. Czy chcesz zagrac ponownie?",QMessageBox::Yes | QMessageBox::No );
       if(reply==QMessageBox::No)
       {
            QWidget::close();

       }
       else
       {
           qApp->quit();
           QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
           QMessageBox::Close;

       }

    }

}
void MainWindow::winning()
{
    QMessageBox Msgbox;
    switch(q1.score)
    {
    case 1:
        Msgbox.setText("Gratulacje wygrywasz 500zl!");
        Msgbox.exec();
        ui->TextStep1->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
        ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

        ui->TextAccount->setText("500zl");

        break;
    case 2:
            Msgbox.setText("Gratulacje wygrywasz 1000zl oraz twoja wygrana zamienia sie w bezpieczna kwote!");
            Msgbox.exec();
            ui->TextStep2->setStyleSheet("background-color: #F0E68C;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("1000zl");
            break;
    case 3:
            Msgbox.setText("Gratulacje wygrywasz 5000zl!");
            Msgbox.exec();
            ui->TextStep3->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("5000zl");
            break;
    case 4:
            Msgbox.setText("Gratulacje wygrywasz 10000zl!");
            Msgbox.exec();
            ui->TextStep4->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("10000zl");
            break;
    case 5:
            Msgbox.setText("Gratulacje wygrywasz 20000zl!");
            Msgbox.exec();
            ui->TextStep5->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("20000zl");
            break;
    case 6:
            Msgbox.setText("Gratulacje wygrywasz 40000zl oraz twoja wygrana zamienia sie w bezpieczna kwote!");
            Msgbox.exec();
            ui->TextStep6->setStyleSheet("background-color: #F0E68C;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("40000zl");
            break;
    case 7:
            Msgbox.setText("Gratulacje wygrywasz 75000zl!");
            Msgbox.exec();
            ui->TextStep7->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("75000zl");
            break;
    case 8:
            Msgbox.setText("Gratulacje wygrywasz 125000zl!");
            Msgbox.exec();
            ui->TextStep8->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("125000zl");
            break;
    case 9:
            Msgbox.setText("Gratulacje wygrywasz 250000zl!");
            Msgbox.exec();
            ui->TextStep9->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("250000zl");
            break;
    case 10:
            Msgbox.setText("Gratulacje wygrywasz 500000zl!");
            Msgbox.exec();
            ui->TextStep10->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: solid 2px black;border: 2px solid black;");
            ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

            ui->TextAccount->setText("500000zl");
            break;
           case 11:
        ui->TextStep11->setStyleSheet("background-color: #90EE90;border-radius: 10px;border: 2px solid black;");
        ui->TextAccount->setStyleSheet("background-color: #D3D3D3;border: 2px solid black;border-radius: 10px;font: 9pt;");

         ui->TextAccount->setText("1000000zl");
        won();
        break;

    }
}
void MainWindow::won()
{
    QMessageBox Msgbox;
    Msgbox.setText("Gratulacje wygrywasz gre oraz milion!");
    Msgbox.exec();
    QWidget::close();
}
void MainWindow::pytanie()
{

    if(q1.pytanie)
    {

Dialog dialog;
dialog.setModal(true);
dialog.pytanie(q1.correct);
dialog.exec();
q1.pytanie=0;
    }
    else
    {
        QMessageBox Msgbox;
        Msgbox.setText("Wykorzystales to kolo");
        Msgbox.exec();
    }

}

void MainWindow::on_ButtonPub_clicked()
{
    pytanie();
}
void MainWindow::giveup()
{
    QMessageBox::StandardButton reply;
   reply = QMessageBox::question(this," ","Czy na pewno chcesz zrezygnowac?",QMessageBox::Yes | QMessageBox::No );
   if(reply==QMessageBox::Yes)
   {
        QWidget::close();
        winning();
   }
   else
   {
       QMessageBox::Close;
   }

}

void MainWindow::on_pushButton_clicked()
{
    giveup();
}
void MainWindow::telefon()
{
    QMessageBox Msgbox;
    if(q1.telefon)
    {

        qsrand(time(NULL));
        int odpowiedztel=(qrand() % 5)+1;



                    switch(odpowiedztel)//szansa na podpowiedzenie dobrej odpowiedzi to 1/2
                    {
                    case 1:
                             Msgbox.setText("Proponowana odpowiedz to: a ");
                             Msgbox.exec();
                            break;
                    case 2:
                             Msgbox.setText("Proponowana odpowiedz to: b ");
                             Msgbox.exec();
                             break;
                    case 3:
                             Msgbox.setText("Proponowana odpowiedz to: c");
                             Msgbox.exec();
                             break;
                    case 4:
                             Msgbox.setText("Proponowana odpowiedz to: d");
                             Msgbox.exec();
                             break;
                    case 5:
                        Msgbox.setText(text);
                        Msgbox.exec();
                            break;
                    case 6:
                        Msgbox.setText(text);
                        Msgbox.exec();
                            break;
                    }
                    q1.telefon=0;
    }
    else
    {
        Msgbox.setText("Wykorzystales to kolo");
        Msgbox.exec();
    }
}

void MainWindow::on_ButtonCall_clicked()
{
    telefon();
}

void MainWindow::on_ButtonFifty_clicked()
{
    polowa();
}
void MainWindow::polowa()
{
    if(q1.pol)
    {
        q1.pol=0;
    QMessageBox Msgbox;
    if(q1.correct=="A")
            {
                srand((unsigned)time(0));
                int random = (rand()%4);
                switch (random)
                {
            case 1:

                    ui->ButtonC->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonC->setStyleSheet("border: none;");
                    ui->ButtonD->setStyleSheet("border: none;");

                break;

            case 2:

                    ui->ButtonB->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonB->setStyleSheet("border: none");
                    ui->ButtonD->setStyleSheet("border: none;");
                    break;
            case 3:

                    ui->ButtonC->setText("");
                    ui->ButtonB->setText("");
                    ui->ButtonC->setStyleSheet("border: none");
                    ui->ButtonB->setStyleSheet("border: none;");
                           break;
                }
            }
            if(q1.correct=="B")
            {
                srand((unsigned)time(0));
                int random = (rand()%4);
                switch (random)
                {
            case 1:
                    ui->ButtonC->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonC->setStyleSheet("border: none;");
                    ui->ButtonD->setStyleSheet("border: none;");

                break;

            case 2:
                    ui->ButtonA->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonD->setStyleSheet("border: none;");

                           break;
            case 3:
                    ui->ButtonA->setText("");
                    ui->ButtonC->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonC->setStyleSheet("border: none;");

                           break;

                }
            }
            if(q1.correct=="C")
            {
                srand((unsigned)time(0));
                int random = (rand()%4);
                switch (random)
                {
            case 1:
                    ui->ButtonA->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonD->setStyleSheet("border: none;");

                break;

            case 2:
                    ui->ButtonB->setText("");
                    ui->ButtonD->setText("");
                    ui->ButtonB->setStyleSheet("border: none;");
                    ui->ButtonD->setStyleSheet("border: none;");

                           break;
            case 3:
                    ui->ButtonA->setText("");
                    ui->ButtonB->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonB->setStyleSheet("border: none;");

                           break;

                }
            }
            if(q1.correct=="D")
            {
                srand((unsigned)time(0));
                int random = (rand()%4);
                switch (random)
                {
            case 1:
                    ui->ButtonA->setText("");
                    ui->ButtonC->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonC->setStyleSheet("border: none;");

                break;

            case 2:
                    ui->ButtonA->setText("");
                    ui->ButtonB->setText("");
                    ui->ButtonA->setStyleSheet("border: none;");
                    ui->ButtonB->setStyleSheet("border: none;");

                           break;
            case 3:
                    ui->ButtonB->setText("");
                    ui->ButtonC->setText("");
                    ui->ButtonB->setStyleSheet("border: none;");
                    ui->ButtonC->setStyleSheet("border: none;");

                           break;

                }
            }
        }
    else
    {
         QMessageBox Msgbox;
        Msgbox.setText("Wykorzystales juz to kolo");
        Msgbox.exec();
    }
}
