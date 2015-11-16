#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget* _parent)
   : QMainWindow(_parent)
{
   setupUi(this);
}

void MainWindow::on_action_Quit_triggered()
{
   close();
}
