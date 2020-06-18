FROM debian

WORKDIR /root
COPY . .

RUN apt-get update
RUN apt-get install cmake -y
RUN apt-get install build-essential -y
RUN cmake /root/
RUN cmake --build /root/ --target CPP-AntsColony -- -j 8

ENTRYPOINT ["/root/CPP-AntsColony"]