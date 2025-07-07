FROM gcc:latest AS build

ADD ./src /app/src

WORKDIR /app/build

RUN apt-get update && \
    apt-get install -y \
      cmake

RUN cmake ../src && \
    cmake --build .

# -------------------------------------------

FROM ubuntu:latest

RUN groupadd -r sample && useradd -r -g sample sample

USER sample

WORKDIR /app

COPY --from=build /app/build/run .

ENTRYPOINT ["./run"]
