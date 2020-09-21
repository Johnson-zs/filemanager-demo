#include "bluetoothplugin.h"

#include <QDebug>

BluetoothPlugin::BluetoothPlugin(QObject *parent) : QObject(parent)
{

}

void BluetoothPlugin::doAction()
{
    qDebug() << "bluetooth plugin do something...";
}
