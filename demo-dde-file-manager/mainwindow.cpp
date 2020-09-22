#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initInterfaces();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initInterfaces()
{
    m_copymoveInter = new ComDemoIoDaemonCopyMoveServiceInterface("com.demo.io.daemon",
                                                                  "/com/demo/io/daemon/CopyMoveService",
                                                                  QDBusConnection::sessionBus(), this);
    m_rootInter = new ComDemoFilemanagerDaemonRootServiceInterface("com.demo.filemanager.daemon",
                                                               "/com/demo/filemanager/daemon/RootService",
                                                               QDBusConnection::systemBus(), this);
    m_pluginsInter = new ComDemoPluginsDaemonPluginTestServiceInterface("com.demo.plugins.daemon",
                                                                        "/com/demo/plugins/daemon/PluginTestService",
                                                                        QDBusConnection::sessionBus(), this);
}

void MainWindow::on_pushButton_2_clicked()
{
    m_copymoveInter->Copy("/tmp/a", "/tmp/b");
}

void MainWindow::on_pushButton_clicked()
{
    m_rootInter->createFileInAnyWhere("/tmp/root.txt");
}

void MainWindow::on_pushButton_3_clicked()
{
    m_pluginsInter->doSomething();
}
