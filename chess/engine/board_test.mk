objects = board_test.o board.o piece.o move.o exceptions.o

board_test : $(objects)
	g++ -std=c++11 -o board_test $(objects) -lpthread -lgtest

board_test.o : board_test.cc board.h
	g++ -std=c++11 -c board_test.cc -o board_test.o

board.o : board.cc board.h
	g++ -std=c++11 -c board.cc -o board.o

piece.o : piece.cc piece.h
	g++ -std=c++11 -c piece.cc -o piece.o

move.o : move.cc move.h
	g++ -std=c++11 -c move.cc -o move.o

exceptions.o : exceptions.cc exceptions.h
	g++ -std=c++11 -c exceptions.cc -o exceptions.o

.PHONY : clean
clean : 
	rm board_test $(objects)