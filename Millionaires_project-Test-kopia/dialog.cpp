#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "Question.h"
#include <random>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::pytanie(string corra)
{
    random_device dev;
                                          mt19937 rng7(dev());
                                          uniform_int_distribution<std::mt19937::result_type> dist50(50,97); // wybor pytania 1-50.
                                                 int procent=dist50(rng7);
                                          random_device a;
                                                 mt19937 rng1(dev());
                                                 uniform_int_distribution<std::mt19937::result_type> dist1(0,100-procent); // wybor pytania 1-50.
                                                        int procent2=dist1(rng1);
                                          random_device b;
                                                 mt19937 rng2(dev());
                                                 uniform_int_distribution<std::mt19937::result_type> dist2(0,100-procent-procent2); // wybor pytania 1-50.
                                                     int   procent3=dist2(rng2);
                                         int procent4=100-procent3-procent2-procent;
                                          if(corra=="A")
                                          {
                                              ui->ProcA->setText(QString::number(procent));
                                              ui->ProcB->setText(QString::number(procent2));
                                              ui->ProcC->setText(QString::number(procent3));
                                              ui->ProcD->setText(QString::number(procent4));
                                          }
                                          if(corra=="B")
                                          {
                                              ui->ProcA->setText(QString::number(procent2));
                                              ui->ProcB->setText(QString::number(procent));
                                              ui->ProcC->setText(QString::number(procent4));
                                              ui->ProcD->setText(QString::number(procent3));
                                          }
                                          if(corra=="C")
                                          {
                                              ui->ProcA->setText(QString::number(procent2));
                                              ui->ProcB->setText(QString::number(procent4));
                                              ui->ProcC->setText(QString::number(procent));
                                              ui->ProcD->setText(QString::number(procent3));
                                          }
                                          if(corra=="D")
                                          {
                                              ui->ProcA->setText(QString::number(procent3));
                                              ui->ProcB->setText(QString::number(procent4));
                                              ui->ProcC->setText(QString::number(procent2));
                                              ui->ProcD->setText(QString::number(procent));
                                          }

}
