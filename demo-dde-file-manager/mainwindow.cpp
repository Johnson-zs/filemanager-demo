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
}

void MainWindow::on_pushButton_2_clicked()
{
    m_copymoveInter->Copy("/tmp/a", "/tmp/b");
}
