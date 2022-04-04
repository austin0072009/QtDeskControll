#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QTcpSocket>
class NetworkHandler : public QObject
{
    Q_OBJECT
public:
    explicit NetworkHandler(QObject *parent = nullptr);

    QTcpSocket *m_tcp;

signals:

public slots:
    void createSocket();
    void handlerConnected();

};

#endif // NETWORKHANDLER_H
