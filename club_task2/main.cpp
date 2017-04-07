#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(0,"me");
    Widget w_another(0,"you");
    w.set_Widget(&w_another);
    w_another.set_Widget(&w);
    w.show();
    w_another.show();
    return a.exec();
}
