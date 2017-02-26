// StdIncludes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// QIncludes
#include <QApplication>
#include <QString>

#include "include/GoToTime.h"
#include "include/mainwindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow *m = new MainWindow();
    m->show();

    return app.exec();
}
