#include "mainwindow.h"
#include "Question.h"
#include <string>
#include <fstream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;


    w.show();
    return a.exec();




}
