all : piece_test board_test
.PHONY : all

#piece_test begin
piece_test_objects = piece_test.o piece.o

piece_test : $(piece_test_objects)
	g++ -std=c++11 -o piece_test $(piece_test_objects) -lpthread -lgtest
#piece_test end

#board_test begin
board_test_objects = board_test.o board.o piece.o move.o exceptions.o

board_test : $(board_test_objects)
	g++ -std=c++11 -o board_test $(board_test_objects) -lpthread -lgtest
#board_test end

piece.o : piece.cc piece.h
	g++ -std=c++11 -c piece.cc -o piece.o

piece_test.o : piece_test.cc piece.h
	g++ -std=c++11 -c piece_test.cc -o piece_test.o

board_test.o : board_test.cc board.h
	g++ -std=c++11 -c board_test.cc -o board_test.o

board.o : board.cc board.h
	g++ -std=c++11 -c board.cc -o board.o

move.o : move.cc move.h
	g++ -std=c++11 -c move.cc -o move.o

exceptions.o : exceptions.cc exceptions.h
	g++ -std=c++11 -c exceptions.cc -o exceptions.o

.PHONY : clean
clean : 
	rm piece_test board_test $(piece_test_objects) $(board_test_objects)