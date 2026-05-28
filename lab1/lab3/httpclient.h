#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QNetworkAccessManager>

class HttpClient : public QObject
{
    Q_OBJECT

private:
    static HttpClient* instance;

    explicit HttpClient(QObject *parent = nullptr);

    QNetworkAccessManager manager;

public:
    static HttpClient* getInstance();

    QNetworkAccessManager* getManager();
};

#endif
