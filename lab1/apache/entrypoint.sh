#!/bin/sh

mkdir -p /usr/local/apache2/conf/certs

if [ ! -f /usr/local/apache2/conf/certs/lab2.crt ]; then

    echo "Генерация самоподписанных TLS-сертификатов..."

    openssl req \
        -x509 \
        -nodes \
        -days 365 \
        -newkey rsa:2048 \
        -keyout /usr/local/apache2/conf/certs/lab2.key \
        -out /usr/local/apache2/conf/certs/lab2.crt \
        -subj "/CN=localhost"

fi

httpd-foreground