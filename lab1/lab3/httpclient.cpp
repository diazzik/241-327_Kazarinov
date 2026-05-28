#include "httpclient.h"

HttpClient* HttpClient::instance = nullptr;

HttpClient::HttpClient(QObject *parent)
    : QObject(parent)
{
}

HttpClient* HttpClient::getInstance()
{
    if(instance == nullptr)
    {
        instance = new HttpClient();
    }

    return instance;
}

QNetworkAccessManager* HttpClient::getManager()
{
    return &manager;
}
