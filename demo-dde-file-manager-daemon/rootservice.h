#ifndef ROOTSERVICE_H
#define ROOTSERVICE_H

#include <QObject>
#include <QDBusContext>

class RootServiceAdaptor;
class RootService : public QObject, public QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.demo.filemanager.daemon.RootService")

public:
    static QString kObjectPath;

    explicit RootService(QObject *parent = nullptr);

public slots:
    bool createFileInAnyWhere(const QString &filePath);

private:
    RootServiceAdaptor *m_adaptor {nullptr};

};

#endif // ROOTSERVICE_H
