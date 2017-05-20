#!/usr/bin/sh
g++ -std=c++11 -Wall -c engine/board.cc -o engine/board.o
g++ -std=c++11 -Wall -c engine/exceptions.cc -o engine/exceptions.o
g++ -std=c++11 -Wall -c engine/move.cc -o engine/move.o
g++ -std=c++11 -Wall -c engine/piece.cc -o engine/piece.o
g++ -std=c++11 -Wall -o engine/piece_test engine/piece_test.o engine/piece.o -lpthread -lgtest
g++ -std=c++11 -Wall -llog4cpp -lpthread log/log.cc -o log/log