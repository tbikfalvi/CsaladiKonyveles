#-------------------------------------------------
#
# Project created by QtCreator 2012-12-30T20:02:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET       = CsaladiKonyveles
TEMPLATE     = app
INCLUDEPATH += framework

RC_FILE      = csaladikonyveles.rc
RESOURCES   += csaladikonyveles.qrc

SOURCES     += framework/filewriter.cpp \
               framework/guiwriter.cpp \
               framework/logger.cpp \
               framework/logmessage.cpp \
               framework/preferences.cpp \
               framework/tracer.cpp \
               main.cpp\
               mainwindow.cpp \
    projectkonyveles.cpp

HEADERS     += framework/filewriter.h \
               framework/guiwriter.h \
               framework/logger.h \
               framework/logmessage.h \
               framework/logwriter.h \
               framework/preferences.h \
               framework/severity.h \
               framework/sevexception.h \
               framework/singleton.h \
               framework/tracer.h \
               mainwindow.h \
    projectkonyveles.h

FORMS       += mainwindow.ui
