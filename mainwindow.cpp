
#include <QCloseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _bCanBeClosed   = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ExitApplication_triggered()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *p_poEvent)
{
    if( _bCanBeClosed )
    {
        p_poEvent->accept();
    }
    else
    {
        p_poEvent->ignore();
    }
}

void MainWindow::on_action_Open_triggered()
{
    ui->action_ExitApplication->setEnabled( false );

    _bCanBeClosed = false;
}

void MainWindow::on_action_Close_triggered()
{
    ui->action_ExitApplication->setEnabled( true );

    _bCanBeClosed = true;
}
