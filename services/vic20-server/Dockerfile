FROM alpine

# Set up web server
RUN apk add --update --no-cache \
  lighttpd

EXPOSE 80


ENV HTDOCS=/var/www/localhost/htdocs/

# Download VIC20 emulator
# This is the "master" branch as of 2021
ENV VIC20REVISION=3907af09f782f02f8bf69a4e44f35c5268c86ebc
RUN mkdir vic20-emu
RUN wget https://github.com/nippur72/vic20-emu/archive/${VIC20REVISION}.zip
RUN unzip ${VIC20REVISION}.zip
RUN rm ${VIC20REVISION}.zip
RUN mv vic20-emu-${VIC20REVISION} ${HTDOCS}/vic20-emu

COPY index.html ${HTDOCS}/index.html
COPY favicon.ico ${HTDOCS}/favicon.ico

RUN mkdir ${HTDOCS}/vic20-shell


# Configure webserver
ENV LIGHTTPD_CONFIG=/etc/lighttpd/lighttpd.conf
## Enable cgi on .sh files
RUN sed -i "s/static-file.exclude-extensions = (/static-file.exclude-extensions = (\".sh\", /" ${LIGHTTPD_CONFIG}
RUN sed -i "s/#   include \"mod_cgi.conf\"/include \"mod_cgi.conf\"/" ${LIGHTTPD_CONFIG}
RUN sed -i "s/cgi.assign = (/cgi.assign = (\n\t\t\".sh\"\t=>\t\"\/bin\/sh\",/" etc/lighttpd/mod_cgi.conf
### Also let's allow subdirectories to have cgi-bins
RUN sed -i "s/\^\/cgi-bin/\/cgi-bin/" etc/lighttpd/mod_cgi.conf
## Enable dir listing
RUN sed -i "s/#   dir-listing.activate      = \"enable\"/dir-listing.activate=\"enable\"/" ${LIGHTTPD_CONFIG}
## Enabled debugging
RUN sed -i "s/# debug/debug/" ${LIGHTTPD_CONFIG}

ENTRYPOINT ["/usr/sbin/lighttpd", "-D", "-f", "/etc/lighttpd/lighttpd.conf"]
