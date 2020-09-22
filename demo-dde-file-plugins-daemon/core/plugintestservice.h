#ifndef PLUGINTESTSERVICE_H
#define PLUGINTESTSERVICE_H

#include <QObject>
#include <QDBusContext>

class PluginTestServiceAdaptor;
class PluginTestService : public QObject, public QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.demo.plugins.daemon.PluginTestService")

public:
    static QString kObjectPath;

    explicit PluginTestService(QObject *parent = nullptr);

public slots:
    void doSomething();

private:
    PluginTestServiceAdaptor *m_adaptor {nullptr};
};

#endif // PLUGINTESTSERVICE_H
