FROM alpine


# Download dependencies for building vic
RUN apk add --update --no-cache \
  build-base\
  wget\
  inotify-tools
# Download cc65, compile it, add it to the path
## This revision is the master branch from Nov 17, 2022.
ENV CC65_REVISION=88b926e91464c041d958bbab1e08042ab904155b
RUN wget https://github.com/cc65/cc65/archive/${CC65_REVISION}.zip -O cc65.zip
RUN unzip cc65.zip
RUN mv cc65-${CC65_REVISION} cc65
RUN rm cc65.zip

RUN make -C /cc65 
ENV PATH=${PATH}:/cc65/bin
ENV CC65_INC=/cc65/include
#ENV LD65_LIB=/usr/local/share/cc65/lib
#ENV LD65_CFG=/usr/local/share/cc65/cfg

COPY ./utils /utils
RUN chmod +x /utils/*


# Specify volumes here for source and output
RUN mkdir /src
RUN mkdir /output

ENTRYPOINT [ "/utils/watch.sh" ]