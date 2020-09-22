#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "dbus-api/copymoveservice_interface.h"

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

private:
    void initInterfaces();

private:
    Ui::MainWindow *ui;

    ComDemoIoDaemonCopyMoveServiceInterface *m_copymoveInter {nullptr};
};

#endif // MAINWINDOW_H
