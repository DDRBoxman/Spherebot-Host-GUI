#ifndef TXTHREAD_H
#define TXTHREAD_H
#include <QThread>
#include <QString>
#include "spherebot.h"
#include <QMessageBox>
#include <QTimer>

class txThread : public QThread
{
    Q_OBJECT
public:
    txThread();
    void set(QString textfile,spherebot &bot);
    void run();
    ~txThread();
    int getLineCounter();

signals:
    void progressChanged(int);
    void fileTransmitted();

public slots:
    void sendNext();
private:
    QString textfile;
    int lineCounter;
    int lineMax;
    spherebot *bot;
};

#endif // TXTHREAD_H
