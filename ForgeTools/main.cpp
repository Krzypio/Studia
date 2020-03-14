#include <QApplication>

#include "mainwindow.h"
#include "dbconnection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    createConnection("ForgeTools.db");

    MainWindow window;
    window.show();
    return app.exec();
}
