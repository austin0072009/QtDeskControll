#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>
#include <QSettings>
#include "networkhandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_passive_netWorkHandler(Q_NULLPTR),
      m_qnyInfo(new DeviceInfo(this))
{
    ui->setupUi(this);



//    NetworkHandler *net = new NetworkHandler;
//    net->createSocket();

    loadSetting();
}

void MainWindow::loadSetting(){

    QSettings settings("config.ini",QSettings::IniFormat);
    settings.beginGroup("REMOTE_DESKTOP_SERVER");
    QString remoteHost = settings.value("remoteHost").toString();
    if(remoteHost.isEmpty()){
        remoteHost = "11";
        settings.setValue("remoteHost",remoteHost);
    }
    int remotePort = settings.value("remotePort",0).toInt();
    if(0 == remotePort) {
            remotePort = 443;
            settings.setValue("remotePort",remotePort);
}


    settings.endGroup();
    settings.sync();



    listenPort();
}
void MainWindow::listenPort(){

    QThread *thread = new QThread();
    m_passive_netWorkHandler = new NetworkHandler();
    m_passive_netWorkHandler->moveToThread(thread);
    thread->start();

    connect(thread,&QThread::started,m_passive_netWorkHandler,&NetworkHandler::createSocket);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_listen_clicked()
{
    qDebug() << "TEST!!!!!!!! Listening to Port : " << ui->port->text().toInt();
}

