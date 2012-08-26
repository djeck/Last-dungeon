#include "Generation/menubash.h"

#include <QtCore/QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{    QCoreApplication a(argc, argv);

      LD::MenuBash menu;
      menu.start();
     return a.exec();
}
