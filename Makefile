CC=g++
CFLAGS=-std=c++11 -Wall

all: loja

db:
	rm -rf ./build/data/ && cp -R ./data/ ./build/data

loja:
	${CC} ${CFLAGS} src/inventory/*.cpp src/user/*.cpp src/core/*.cpp  src/main.cpp -o build/loja

run:
	./build/loja
