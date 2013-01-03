#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent( QCloseEvent *p_poEvent );
    
private slots:
    void on_action_New_triggered();
    void on_action_Open_triggered();
    void on_action_Close_triggered();
    void on_action_Save_triggered();
    void on_action_ExitApplication_triggered();

private:

    Ui::MainWindow      *ui;

    bool                _bCanBeClosed;

    void                _setActionsEnabled();
};

#endif // MAINWINDOW_H
