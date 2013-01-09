
#include <QCloseEvent>
#include <QFileDialog>

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

void MainWindow::on_action_New_triggered()
{

}

void MainWindow::on_action_Open_triggered()
{
    QString qsDirConf = QDir::currentPath();
    QString qsFileName = QFileDialog::getOpenFileName(this, tr("Open Project file"), qsDirConf, tr("All Files (*.csk)"));

    if( qsFileName.length() > 0 )
    {
        ProjectKonyveles *obProjectKonyveles = new ProjectKonyveles( this, qsFileName );

        qvProjects.append( obProjectKonyveles );

//        ui->ledFileName->setText( QFileInfo(qsFileName).fileName() );
//        ui->ledFileName->setToolTip( qsFileName );
//        m_qsDirConf = QFileInfo(qsFileName).path();

        _bCanBeClosed = false;
    }
}

void MainWindow::on_action_Close_triggered()
{
    ui->action_ExitApplication->setEnabled( true );

    _bCanBeClosed = true;
}

void MainWindow::on_action_Save_triggered()
{

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

void MainWindow::_setActionsEnabled()
{

}

/*

#ifndef DLGCONFIGEDITOR_H
#define DLGCONFIGEDITOR_H

#include <QDialog>
#include <QVector>
#include <QStringList>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QTextStream>
----------------------------------------

*/

void MainWindow::on_tabProjects_tabCloseRequested(int index)
{

}
