CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main:
	${CC} ${CFLAGS} src/inventory/*.cpp src/user/*.cpp  src/main.cpp -o build/loja

run:
	./build/loja
