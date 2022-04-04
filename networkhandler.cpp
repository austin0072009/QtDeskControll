#include "networkhandler.h"
#include <QString>
#include <QDebug>
NetworkHandler::NetworkHandler(QObject *parent)
    : QObject{parent}
{

}
//用于连接主机
void NetworkHandler::createSocket()
{
    m_tcp = new QTcpSocket(this);
    QString Ipaddr = "51df232252.51vip.biz";

    connect(m_tcp,&QTcpSocket::connected,this,&NetworkHandler::handlerConnected);
    m_tcp->connectToHost(Ipaddr,15927);
}

void NetworkHandler::handlerConnected()
{
    qDebug() << "Connected to host" ;
}
