#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "dbus-api/copymoveservice_interface.h"
#include "dbus-api/rootservice_interface.h"
#include "dbus-api/pluginservice_interface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    void initInterfaces();

private:
    Ui::MainWindow *ui;

    ComDemoIoDaemonCopyMoveServiceInterface *m_copymoveInter {nullptr};
    ComDemoFilemanagerDaemonRootServiceInterface *m_rootInter {nullptr};
    ComDemoPluginsDaemonPluginTestServiceInterface *m_pluginsInter {nullptr};
};

#endif // MAINWINDOW_H
