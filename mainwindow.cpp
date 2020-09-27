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
#include <QFile>
#include   <QTextCodec>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//kodowanie utf 8 w celu wyswietlania polskich znakow

start();//uruchamia gre

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::fileopen_qfile()
{
    QFile file(":/pyt/pulapytan/plik.txt");// korzystamy z qfile poniewaz daje mozliwosc przypisania pliku zasobow do programu
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in (&file);
int qestnr = q1.score;// problem z nie inkrementujacym sie numerem pytania
for(int k=0; k<wartosc[qestnr];k++)//petla for aktualizuje tresc pytan przechowywanych w klasie do czasu dotarcia do wlasciwego numeru pytania
{
   q1.question=in.readLine(); //przypisani pytania
   q1.answera=in.readLine();//przypisanie jednej z odpowiedzi
   q1.answerb=in.readLine();
   q1.answerc=in.readLine();
   q1.answerd=in.readLine();
   q1.correct = in.readLine();//przypisanie poprawnej odpowiedzi




    ui->QuestionTextBox->setText(q1.question);//wyswietla pytanie oraz odpowiedzi na przyciskach poprzednio zamieniajac stringa w Qstring
    ui->ButtonD->setText(q1.answerd);
    ui->ButtonA->setText(q1.answera);
    ui->ButtonC->setText(q1.answerc);
    ui->ButtonB->setText(q1.answerb);
    QString anss =q1.correct;
    text = QString("Proponowana odpwoiedz to: %1").arg(anss);
    pola = QString("Proponowana odpwoiedz to: A i %1").arg(anss);//odpowedzi w procentach, formula zamienia q qstring tekst oraz string z poprawna odpowiedzia
    polb = QString("Proponowana odpwoiedz to: B i %1").arg(anss);
    polc = QString("Proponowana odpwoiedz to: C i %1").arg(anss);
    pold = QString("Proponowana odpwoiedz to: D i %1").arg(anss);



    ui->ButtonA->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");//domyslne ustawienie przycisik?w
    ui->ButtonB->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");//aby po urzyciu kola 50/50
    ui->ButtonC->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");//przyciski ponownie byly widoczne
    ui->ButtonD->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");


    }
}
}
//void MainWindow::fileopen()
//{

//    string filee;
//    fstream file;

//    file.open("C://Users//cwyna//Desktop//plik.txt",std::ios::in);

//    //file.open(":/plikitextowe/pulapytan/plik.txt",std::ios::in); // tak nie dzia³a ///////////////////////////////////////////////////////////

//    int qestnr = q1.score;// problem z nie inkrementujacym sie numerem pytania
//    for(int k=0; k<wartosc[qestnr];k++)//petla for aktualizuje tresc pytan przechowywanych w klasie do czasu dotarcia do wlasciwego numeru pytania
//    {
//       getline(file,filee);
//       q1.question=filee;//odczyt pytania
//       getline(file,filee);
//       q1.answera=filee;//odczyt odpowiedzi a
//      getline(file,filee);
//      q1.answerb=filee;//odczyt odpowiedzi b
//       getline(file,filee);
//       q1.answerc=filee;//odczyt odpowiedzi c
//       getline(file,filee);
//       q1.answerd=filee;//odczyt odpowiedzi d
//       getline(file,filee);
//       q1.correct=filee;//odczyt odpowiedzi poprawnej

//        //wyswietla pytanie oraz odpowiedzi na przyciskach poprzednio zamieniajac stringa w Qstring
//        ui->ButtonD->setText(QString::fromStdString(q1.answerd));
//        ui->ButtonA->setText(QString::fromStdString(q1.answera));
//        ui->ButtonC->setText(QString::fromStdString(q1.answerc));
//        ui->ButtonB->setText(QString::fromStdString(q1.answerb));
//        QString anss = QString::fromStdString(q1.correct);
//        text = QString("Proponowana odpwoiedz to: %1").arg(anss);
//        pola = QString("Proponowana odpwoiedz to: A i %1").arg(anss);//odpowedzi w procentach, formula zamienia q qstring tekst oraz string z poprawna odpowiedzia
//        polb = QString("Proponowana odpwoiedz to: B i %1").arg(anss);
//        polc = QString("Proponowana odpwoiedz to: C i %1").arg(anss);
//        pold = QString("Proponowana odpwoiedz to: D i %1").arg(anss);



//        ui->ButtonA->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");
//        ui->ButtonB->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");
//        ui->ButtonC->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");
//        ui->ButtonD->setStyleSheet("background-color:#D3D3D3;border:1px solid #000000;border-radius: 10px;}"":hover{ background-color:#87CEEB;border:1px solid #000000;border-radius: 10px");



//    }
//}
bool MainWindow::verifieanswer()
{

if(q1.correct==q1.users_answer)//porownuje odpowiedz uzytkownika do poprawnej wczytanej z pliku tekstowego oraz zwara wartosc boolowska prawda lub falsz
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

  q1.users_answer = "D";//po kliknieciu odpowiedniego przyciusku ustala odpowiedz uzytkownika
  nextquestion();//przenosi do funkcji zawierajacej sprawdzenie odpowiedzi oraz otwierajacej nowe pytanie

}

void MainWindow::on_ButtonA_clicked()
{

     q1.users_answer = "A";//po kliknieciu odpowiedniego przyciusku ustala odpowiedz uzytkownika
     nextquestion();//przenosi do funkcji zawierajacej sprawdzenie odpowiedzi oraz otwierajacej nowe pytanie
}

void MainWindow::on_ButtonC_clicked()
{

     q1.users_answer = "C";//po kliknieciu odpowiedniego przyciusku ustala odpowiedz uzytkownika
     nextquestion();//przenosi do funkcji zawierajacej sprawdzenie odpowiedzi oraz otwierajacej nowe pytanie
}

void MainWindow::on_ButtonB_clicked()
{

     q1.users_answer = "B";//po kliknieciu odpowiedniego przyciusku ustala odpowiedz uzytkownika
     nextquestion();//przenosi do funkcji zawierajacej sprawdzenie odpowiedzi oraz otwierajacej nowe pytanie
}
void MainWindow::nextquestion()
{
    if(verifieanswer())
    {
        q1.score++;// zwikesza nam zmienna score w celu ustawienia nagrody
        greenborder();//test
        winning();//informnacja o wygranej
fileopen_qfile();//otiwera kolejne pytanie
    }
    else
    {
        redborder();
        lost();
    }
}
void MainWindow::start()
{
    random_question();                 //losuje pytania dla gry
    fileopen_qfile();//wywoluje funkcje pokazujaca na ekran pytania oraz odpowiedzi
}
void MainWindow::random_question()//funkcja lousujaca losowe numery pytan, bez powtazania
{

    for (int i=0;i<11;i++)
        {
            do
            {
                qsrand(time(NULL));
                 liczba=qrand() % 49;
            sprawdz=true;//sprawdza czy sie nie powtarza
            for (int j=0;j<i;j++)
                if (liczba == wartosc[j]) //jezeli numer sie powtarza
                {
                    sprawdz=false;
                    break; //dodaje do tabeli nie powtarzajacy sie numer
                }

            } while (!sprawdz); //petla dopoki nie znajdzie
            wartosc[i]=liczba; //wpisuje liczbe do tabeli
        }


}
void MainWindow::lost()//funkja uzywana w przypadku przegranej
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

void MainWindow::greenborder(){
    if(q1.users_answer=="A"){
        ui->ButtonA->setStyleSheet("background-color:#dcedc8;border:1px solid #76ff03;border-radius: 10px;}");
    }
    else if(q1.users_answer=="B"){
        ui->ButtonB->setStyleSheet("background-color:#dcedc8;border:1px solid #76ff03;border-radius: 10px;}");
    }
    else if(q1.users_answer=="C"){
        ui->ButtonC->setStyleSheet("background-color:#dcedc8;border:1px solid #76ff03;border-radius: 10px;}");
    }
    else{ui->ButtonD->setStyleSheet("background-color:#dcedc8;border:1px solid #76ff03;border-radius: 10px;}");}
}

void MainWindow::redborder(){
    if(q1.users_answer=="A"){
        ui->ButtonA->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
    }
    else if(q1.users_answer=="B"){
        ui->ButtonB->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
    }
    else if(q1.users_answer=="C"){
        ui->ButtonC->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
    }
    else{ui->ButtonD->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");}
}

void MainWindow::winning()// w zaleznosci od ilsoci uzyskanych punktow wyswietla komunikat o nagrodzie
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
            Msgbox.setText("Gratulacje wygrywasz 1000zl!");
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
            Msgbox.setText("Gratulacje wygrywasz 40000zl!");
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
    if(q1.score==2)
    {
         Msgbox.setText("Twoja bezpieczna kwota to 1000zl");
         Msgbox.exec();
    }
    if(q1.score==6)
    {
         Msgbox.setText("Twoja bezpieczna kwota to 40000zl");
         Msgbox.exec();
    }
}
void MainWindow::won()
{
    QMessageBox::StandardButton reply;
   reply = QMessageBox::question(this," ","ZOSTAJESZ MILIONEREM !. Czy chcesz zagrac ponownie?",QMessageBox::Yes | QMessageBox::No );
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
void MainWindow::pytanie()// wywoluje osobne okno z procentpwymi wynikami pytania do publicznosci
{

    if(q1.pytanie)
    {

Dialog dialog;
dialog.setModal(true);
dialog.pytanie(q1.correct.toStdString());
dialog.exec();//wywoluje okno
q1.pytanie=0;
ui->ButtonPub->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
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
        int odpowiedztel=(qrand() % 6)+1;



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
                    ui->ButtonCall->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
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
                int random = (rand()%3)+1;  // zamiana z %4 na %3+1

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
                 int random = (rand()%3)+1;
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
                int random = (rand()%3)+1;
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
                int random = (rand()%3)+1;
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
        ui->ButtonFifty->setStyleSheet("background-color:#e57373;border:1px solid #d50000;border-radius: 10px;}");
        }

    else
    {
         QMessageBox Msgbox;
        Msgbox.setText("Wykorzystales juz to kolo");
        Msgbox.exec();
    }

}
