#include "restadapter.h"
#include "httpclient.h"
#include "restaurant.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QUrl>
#include <QSslError>

RestAdapter::RestAdapter(QObject *parent)
    : QObject(parent)
{
}

void RestAdapter::getList()
{
    QUrl url("http://127.0.0.1:8080/restaurants");

    QNetworkRequest request(url);

    auto reply = HttpClient::getInstance()
                     ->getManager()
                     ->get(request);

    connect(reply, &QNetworkReply::finished, [=]()
            {
                QByteArray data = reply->readAll();

                QString response = QString(data);

                emit responseReady(response);

                qDebug() << response;

                QJsonDocument doc = QJsonDocument::fromJson(data);

                if(doc.isArray())
                {
                    QJsonArray arr = doc.array();

                    for(auto item : arr)
                    {
                        QJsonObject obj = item.toObject();

                        Restaurant r;

                        r.id = obj["id"].toInt();
                        r.name = obj["name"].toString();
                        r.address = obj["address"].toString();
                        r.cuisine = obj["cuisine"].toString();
                        r.rating = obj["rating"].toDouble();
                        r.is_open = obj["is_open"].toBool();

                        qDebug() << "Restaurant:" << r.name;
                    }
                }

                reply->deleteLater();
            });

    connect(reply, &QNetworkReply::sslErrors,
            [=](const QList<QSslError> &errors)
            {
                Q_UNUSED(errors);

                reply->ignoreSslErrors();
            });
}

void RestAdapter::getOne(int id)
{
    QUrl url("http://127.0.0.1:8080/restaurants/" + QString::number(id));

    QNetworkRequest request(url);

    auto reply = HttpClient::getInstance()
                     ->getManager()
                     ->get(request);

    connect(reply, &QNetworkReply::finished, [=]()
            {
                QString response = reply->readAll();

                emit responseReady(response);

                qDebug() << response;

                reply->deleteLater();
            });
}

void RestAdapter::createRestaurant()
{
    QUrl url("http://127.0.0.1:8080/restaurants");

    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/json");

    QJsonObject obj;

    obj["name"] = "Qt Restaurant";
    obj["address"] = "Berlin";
    obj["cuisine"] = "Italian";
    obj["rating"] = 4.5;
    obj["is_open"] = true;

    QJsonDocument doc(obj);

    auto reply = HttpClient::getInstance()
                     ->getManager()
                     ->post(request, doc.toJson());

    connect(reply, &QNetworkReply::finished, [=]()
            {
                QString response = reply->readAll();

                emit responseReady(response);

                qDebug() << response;

                reply->deleteLater();
            });
}

void RestAdapter::updateRestaurant(int id)
{
    QUrl url("http://127.0.0.1:8080/restaurants/" + QString::number(id));

    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/json");

    QJsonObject obj;

    obj["rating"] = 5.0;

    QJsonDocument doc(obj);

    auto reply = HttpClient::getInstance()
                     ->getManager()
                     ->sendCustomRequest(
                         request,
                         "PATCH",
                         doc.toJson()
                         );

    connect(reply, &QNetworkReply::finished, [=]()
            {
                QString response = reply->readAll();

                emit responseReady(response);

                qDebug() << response;

                reply->deleteLater();
            });
}

void RestAdapter::deleteRestaurant(int id)
{
    QUrl url("http://127.0.0.1:8080/restaurants/" + QString::number(id));

    QNetworkRequest request(url);

    auto reply = HttpClient::getInstance()
                     ->getManager()
                     ->deleteResource(request);

    connect(reply, &QNetworkReply::finished, [=]()
            {
                QString response = reply->readAll();

                emit responseReady(response);

                qDebug() << response;

                reply->deleteLater();
            });
}
