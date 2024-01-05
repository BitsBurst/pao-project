#include <QApplication>
#include "src/controller/Controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller appController;

    return a.exec();
}
