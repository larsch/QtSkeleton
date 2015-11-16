#include "MainWindow.hpp"

#include <QApplication>
#include <QDialog>

int main(int argc, char** argv)
{
   QApplication application(argc, argv);
   MainWindow mainWindow;
   mainWindow.show();
   return application.exec();
}
