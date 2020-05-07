#include "mainwindow.h"
#include "Question.h"
#include <string>
#include <fstream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
   // static int const EXIT_CODE_REBOOT;

    w.show();
    return a.exec();




}
