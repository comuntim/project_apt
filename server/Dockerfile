<<<<<<< HEAD
FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y


EXPOSE 33333

WORKDIR /root/
RUN mkdir apt_server
WORKDIR /root/apt_server/
COPY . /root/apt_server/


RUN qmake server.pro
RUN make

ENTRYPOINT ["./server"]
=======
FROM ubuntu:20.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y


EXPOSE 33333

WORKDIR /root/
RUN mkdir apt_server
WORKDIR /root/apt_server/
COPY . /root/apt_server/


RUN qmake server.pro
RUN make

ENTRYPOINT ["./server"]
>>>>>>> 470cb26b6b19acdffc772e94c783a419b4700a77
