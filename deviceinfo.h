#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QObject>
#include <QString>
class DeviceInfo : public QObject
{
    Q_OBJECT
public:
    explicit DeviceInfo(QObject *parent = nullptr);
    void setRemoteInfo(const QString &host ,quint16 port);
    QString getRemoteHost();
    quint16 getRemotePort();

signals:

private:
    QString m_remoteHost;
    quint16 m_remotePort;
};

#endif // DEVICEINFO_H
