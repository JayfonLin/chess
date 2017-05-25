all : piece_test board_test move_generator_test
.PHONY : all


piece_test_objects = piece_test.o piece.o

piece_test : $(piece_test_objects)
	g++ -std=c++11 -o piece_test $(piece_test_objects) -lpthread -lgtest

board_test_objects = board_test.o board.o piece.o move.o exceptions.o move_state.o

board_test : $(board_test_objects)
	g++ -std=c++11 -o board_test $(board_test_objects) -lpthread -lgtest

move_generator_test_objects = move_generator_test.o move_generator.o move.o piece.o board.o exceptions.o move_state.o

move_generator_test : $(move_generator_test_objects)
	g++ -std=c++11 -o move_generator_test $(move_generator_test_objects) -lpthread -lgtest

piece.o : piece.cc piece.h
	g++ -std=c++11 -c piece.cc -o piece.o

piece_test.o : piece_test.cc piece.h
	g++ -std=c++11 -c piece_test.cc -o piece_test.o

board_test.o : board_test.cc board.h piece.h move.h move_state.h
	g++ -std=c++11 -c board_test.cc -o board_test.o

board.o : board.cc board.h move_state.h
	g++ -std=c++11 -c board.cc -o board.o

move.o : move.cc move.h
	g++ -std=c++11 -c move.cc -o move.o

exceptions.o : exceptions.cc exceptions.h
	g++ -std=c++11 -c exceptions.cc -o exceptions.o

move_state.o : move_state.cc move_state.h move.h piece.h
	g++ -std=c++11 -c move_state.cc -o move_state.o

move_generator.o : move_generator.cc move_generator.h move.h piece.h
	g++ -std=c++11 -c move_generator.cc -o move_generator.o

move_generator_test.o : move_generator_test.cc move_generator.h 
	g++ -std=c++11 -c move_generator_test.cc -o move_generator_test.o

.PHONY : clean
clean : 
	rm piece_test board_test move_generator_test $(piece_test_objects)  $(board_test_objects)  $(move_generator_test_objects)