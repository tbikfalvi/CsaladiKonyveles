#include "mainwindow.h"
#include <QApplication>

#include <logger.h>
#include <guiwriter.h>
#include <filewriter.h>

int main(int argc, char *argv[])
{
    int  inRetVal = 0;

    QApplication obApp(argc, argv);

    tgLogger::instance().registerWriter( new cGUIWriter( cSeverity::ERROR ) );
    tgLogger::instance().registerWriter( new cFileWriter( cSeverity::DEBUG, "csaladikonyveles.log", cFileWriter::APPEND ) );

    tgLogger::instance() << cSeverity::INFO << QObject::tr("Application started") << cLogMessage::EOM;

    try
    {
        MainWindow obMainWindow;
        obMainWindow.show();

        inRetVal = obApp.exec();
    }
    catch( cSevException &e )
    {
        inRetVal = 1;
    }

    tgLogger::instance() << cSeverity::INFO << QObject::tr("Application exited") << cLogMessage::EOM;

    return inRetVal;
}
