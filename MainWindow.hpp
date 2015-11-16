#ifndef _MainWindow_hpp
#define _MainWindow_hpp

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, Ui::MainWindow
{
   Q_OBJECT
public:
   MainWindow(QWidget* _parent = nullptr);
public slots:
   void on_action_Quit_triggered();
};

#endif // _MainWindow_hpp
