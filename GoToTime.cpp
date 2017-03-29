// StdIncludes
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

// QIncludes
#include <QApplication>
#include <QString>
#include <QCoreApplication>
#include <QDebug>

#include "mainwindow.h"
using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    qSetMessagePattern("%{file}(%{line}): %{message}");

    MainWindow *m = new MainWindow();
    m->show();

    return app.exec();
}
