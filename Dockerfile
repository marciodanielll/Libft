FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    gcc=4:9.3.0-1ubuntu2 \
    clang \
    make=4.2.1-1.2 \
    gdb=9.2-0ubuntu1~20.04.2 \
    valgrind=1:3.15.0-1ubuntu9.1 \
    python3 \
    python3-pip \
    python3-dev=3.8.2-0ubuntu2 \
    build-essential \
    curl \
    vim \
    nano \
    git \
    zsh && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Instalação de pacotes Python
RUN pip3 install \
    attrs==19.3.0 \
    autobahn==17.10.1 \
    automat==0.8.0 \
    blinker==1.4 \
    bottle==0.12.23 \
    c-formatter-42==0.2.7 \
    Cython==0.29.14 \
    norminette==3.3.51 \
    requests==2.22.0 \
    setuptools==45.2.0 \
    wheel==0.34.2

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

RUN mkdir -p /workspace && \
    chmod -R 777 /workspace

WORKDIR /workspace

CMD ["zsh"]