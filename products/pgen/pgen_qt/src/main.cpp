#include <QApplication>
#include "UIProjectCreatorMain.h"

int main(int argc, char ** argv)
{
    QApplication a(argc,argv);
    cbtek::products::development::projectgen::UIProjectCreatorMain main;
    return main.exec();
}
