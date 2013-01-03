
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

void MainWindow::on_action_New_triggered()
{

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

#include <QTextStream>
#include <QDomDocument>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>

    QString qsFileName = QFileDialog::getOpenFileName(this, tr("Open Config File"), m_qsDirConf, tr("All Files (*.*)"));

    if( qsFileName.length() > 0 )
    {
        ui->ledFileName->setText( QFileInfo(qsFileName).fileName() );
        ui->ledFileName->setToolTip( qsFileName );
        m_qsDirConf = QFileInfo(qsFileName).path();
    }

void dlgConfigEditor::_readConfigXml(QString p_qsFileName)
{
    cTracer tracer("_readConfigXml");

    QDomDocument doc( "atpconfig" );
    QFile file( p_qsFileName );

    if( !file.open(QIODevice::ReadOnly) )
        return;

    QString      qsErrorMsg  = "";
    int          inErrorLine = 0;
    file.seek( 0 );
    if( !doc.setContent( &file, &qsErrorMsg, &inErrorLine ) )
    {
        QMessageBox::warning( this, tr("Warning"), QString( "Parsing Batch file: %1 - Error in line %2: %3" ).arg( p_qsFileName ).arg( inErrorLine ).arg( qsErrorMsg ) );
        file.close();
        return;
    }
    file.close();

    QDomElement docRoot = doc.documentElement();

    QDomNodeList nodeList = docRoot.elementsByTagName("header").at(0).toElement().elementsByTagName("setting");

    for(int i = 0; i < nodeList.count(); i++ )
    {
        QString qsFailSilent( nodeList.at(i).toElement().attribute( "fail_silent", "" ) );
        if( qsFailSilent.length() )
        {
            m_bSilentMode = qsFailSilent.toInt();
            ui->chkSilent->setChecked( (qsFailSilent.compare("1")==0?true:false) );
        }
        QString qsOnlyTP( nodeList.at(i).toElement().attribute( "only_tp", "" ) );
        if( qsOnlyTP.length() )
        {
            m_bOnlyTP = qsOnlyTP.toInt();
            ui->chkOnlyTP->setChecked( (qsOnlyTP.compare("1")==0?true:false) );
        }
    }

    QStringList qslTestCase;

    QDomNodeList obTestItems = docRoot.elementsByTagName("testcases").at(0).toElement().elementsByTagName("testitem");

    for( int i = 0; i < obTestItems.count(); i++ )
    {
        QString qsName = obTestItems.at(i).toElement().attribute( "filename", "" );
        QString qsTitle = obTestItems.at(i).toElement().attribute( "name", "" );
        QString qsEnabled = obTestItems.at(i).toElement().attribute( "execute", "" );
        QString qsComment = obTestItems.at(i).toElement().attribute( "flags", "" );

        qslTestCase.clear();
        qslTestCase.append( QString("%1|%2|%3%4|%5").arg(qsName).arg(qsEnabled).arg((qsComment.length()>0?"#":"")).arg(qsComment).arg(qsTitle) );

        QDomNodeList obTestProcedures = obTestItems.at(i).toElement().elementsByTagName("testproc");

        for( int j=0; j < obTestProcedures.count(); j++ )
        {
            qsName = obTestProcedures.at(j).toElement().attribute("name", "");
            qsEnabled = obTestProcedures.at(j).toElement().attribute("execute", "");
            qsComment = obTestProcedures.at(j).toElement().attribute("flags", "");

            qslTestCase.append( QString("%1|%2|%3%4").arg(qsName).arg(qsEnabled).arg((qsComment.length()>0?"#":"")).arg(qsComment) );
        }

        m_vTestCases.append( qslTestCase );
    }
}
*/
