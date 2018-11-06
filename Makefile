CC=g++
CFLAGS=-std=c++11 -Wall

all: main

main:
	${CC} ${CFLAGS} -o build/main src/*.cpp

run:
	./build/main
