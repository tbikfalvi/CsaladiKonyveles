#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "projectkonyveles.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:

    QVector<ProjectKonyveles*>  qvProjects;

    void closeEvent( QCloseEvent *p_poEvent );
    
private slots:
    void on_action_New_triggered();
    void on_action_Open_triggered();
    void on_action_Close_triggered();
    void on_action_Save_triggered();
    void on_action_ExitApplication_triggered();

    void on_tabProjects_tabCloseRequested(int index);

private:

    Ui::MainWindow      *ui;

    bool                _bCanBeClosed;

    void                _setActionsEnabled();
};

#endif // MAINWINDOW_H
