#ifndef RESTADAPTER_H
#define RESTADAPTER_H

#include <QObject>

class RestAdapter : public QObject
{
    Q_OBJECT

public:
    explicit RestAdapter(QObject *parent = nullptr);

    void getList();

    void getOne(int id);

    void createRestaurant();

    void updateRestaurant(int id);

    void deleteRestaurant(int id);

signals:
    void responseReady(QString response);
};

#endif
