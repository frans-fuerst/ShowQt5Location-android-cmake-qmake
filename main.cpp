#include <QMainWindow>
#include <QApplication>

#include <QGeoPositionInfoSource>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;

    qWarning() << "Creating";
    auto source = QGeoPositionInfoSource::createDefaultSource(&a);
    if ( source )
        qWarning() << "Created";
    else
        qWarning() << "NULL";

    w.show();

    return a.exec();
}

