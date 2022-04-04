#include "deviceinfo.h"

DeviceInfo::DeviceInfo(QObject *parent)
    : QObject{parent}
{

}


void DeviceInfo::setRemoteInfo(const QString &host ,quint16 port)
{
}
QString DeviceInfo::getRemoteHost()
{
    return this->m_remoteHost;
}

quint16 DeviceInfo::getRemotePort()
{
    return this->m_remotePort;
}
