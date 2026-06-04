FROM httpd:2.4

RUN apt-get update && apt-get install -y openssl

COPY httpd.conf /usr/local/apache2/conf/httpd.conf

COPY entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]