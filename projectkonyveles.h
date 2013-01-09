#ifndef PROJECTKONYVELES_H
#define PROJECTKONYVELES_H

#include <QObject>

class ProjectKonyveles : public QObject
{
    Q_OBJECT
public:
    explicit ProjectKonyveles(QObject *parent = 0, QString p_qsFileName = "");

    QString     statusMessage() const;
    QString     fileName() const;
    int         tabIndex();

    void        setFileName( const QString &p_qsFileName );
    void        setTabIndex( int p_nTabIndex );

private:
    QString     _qsFileName;
    int         _nTabIndex;
    QString     _qsStatusMessage;

    void        _setStatusMessage( const QString &p_qsStatusMessage );
    void        _open();
    
signals:
    void        signalStatusChanged( const QString &p_qsStatusMessage );
    
public slots:
    
};

#endif // PROJECTKONYVELES_H
