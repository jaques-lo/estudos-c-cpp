#include "blocodenotas.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlocoDeNotas w;
    w.show();
    return a.exec();
}
