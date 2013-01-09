
#include <QTextStream>
#include <QDomDocument>
#include <QFile>


#include "projectkonyveles.h"

ProjectKonyveles::ProjectKonyveles(QObject *parent, QString p_qsFileName) : QObject(parent)
{
    _qsFileName = p_qsFileName;

    _open();
}

QString ProjectKonyveles::fileName() const
{
    return _qsFileName;
}

int ProjectKonyveles::tabIndex()
{
    return _nTabIndex;
}

void ProjectKonyveles::setFileName(const QString &p_qsFileName)
{
    _qsFileName = p_qsFileName;
}

void ProjectKonyveles::setTabIndex(int p_nTabIndex)
{
    _nTabIndex = p_nTabIndex;
}

void ProjectKonyveles::_open()
{
    QDomDocument doc( "atpconfig" );
    QFile file( p_qsFileName );

    if( !file.open(QIODevice::ReadOnly) )
        return;


}





/*
#include <QTextStream>
#include <QDomDocument>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>


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
