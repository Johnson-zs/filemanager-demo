#ifndef COPYMOVESERVICE_H
#define COPYMOVESERVICE_H

#include <QObject>
#include <QDBusContext>

class CopyMoveServiceAdaptor;
class CopyMoveService : public QObject, public QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.demo.io.daemon.CopyMoveService")

public:
    static QString kObjectPath;

    explicit CopyMoveService(QObject *parent = nullptr);

public slots:
    void Copy(const QString &src, const QString &dest);

private:
    CopyMoveServiceAdaptor *m_adaptor {nullptr};
};

#endif // COPYMOVESERVICE_H
