#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QString>

class Restaurant
{
public:
    int id;
    QString name;
    QString address;
    QString cuisine;
    double rating;
    bool is_open;
};

#endif
