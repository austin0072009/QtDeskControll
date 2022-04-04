#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "networkhandler.h"
#include "deviceinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_listen_clicked();

private:
    Ui::MainWindow *ui;
    void loadSetting();
    void listenPort();

    //controlled socket function
    NetworkHandler *m_passive_netWorkHandler;

    //DeviceInfo

    DeviceInfo *m_qnyInfo;
};
#endif // MAINWINDOW_H
