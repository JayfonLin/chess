all : piece_test board_test move_generator_test rule_test
.PHONY : all


piece_test_objects = piece_test.o piece.o

piece_test : $(piece_test_objects)
	g++ -std=c++11 -g -Wall -o piece_test $(piece_test_objects) -lpthread -lgtest

board_test_objects = board_test.o board.o piece.o move.o exceptions.o move_state.o \
location.o ../log/log.o

board_test : $(board_test_objects)
	g++ -std=c++11 -I../ -g -Wall -o board_test $(board_test_objects) -lpthread -lgtest -llog4cpp

move_generator_test_objects = move_generator_test.o move_generator.o move.o piece.o board.o exceptions.o move_state.o location.o

move_generator_test : $(move_generator_test_objects)
	g++ -std=c++11 -g -Wall -o move_generator_test $(move_generator_test_objects) -lpthread -lgtest

rule_test_objects = rule_test.o rule.o board.o move.o move_state.o move_generator.o piece.o exceptions.o location.o

rule_test : $(rule_test_objects)
	g++ -std=c++11 -g -Wall -o rule_test $(rule_test_objects) -lpthread -lgtest

piece.o : piece.cc piece.h
	g++ -std=c++11 -g -Wall -c piece.cc -o piece.o

piece_test.o : piece_test.cc piece.h
	g++ -std=c++11 -g -Wall -c piece_test.cc -o piece_test.o

board_test.o : board_test.cc board.h piece.h move.h move_state.h
	g++ -std=c++11 -g -Wall -c board_test.cc -o board_test.o

board.o : board.cc board.h exceptions.h move.h move_state.h piece.h
	g++ -std=c++11 -I../ -g -Wall -c board.cc -o board.o

move.o : move.cc move.h
	g++ -std=c++11 -g -Wall -c move.cc -o move.o

exceptions.o : exceptions.cc exceptions.h
	g++ -std=c++11 -g -Wall -c exceptions.cc -o exceptions.o

move_state.o : move_state.cc move_state.h move.h piece.h
	g++ -std=c++11 -g -Wall -c move_state.cc -o move_state.o

move_generator.o : move_generator.cc move_generator.h move.h piece.h
	g++ -std=c++11 -g -Wall -c move_generator.cc -o move_generator.o

move_generator_test.o : move_generator_test.cc move_generator.h 
	g++ -std=c++11 -g -Wall -c move_generator_test.cc -o move_generator_test.o

rule_test.o : rule_test.cc
	g++ -std=c++11 -g -Wall -c rule_test.cc -o rule_test.o

rule.o : rule.cc rule.h
	g++ -std=c++11 -g -Wall -c rule.cc -o rule.o 

location.o : location.cc location.h
	g++ -std=c++11 -g -Wall -c location.cc -o location.o

log.o : log.cc log.h
	g++ -std=c++11 -I../log -g -Wall -c log.cc -o log.o -lpthread -llog4cpp

.PHONY : clean
clean : 
	rm piece_test board_test move_generator_test rule_test $(piece_test_objects)  $(board_test_objects)  $(move_generator_test_objects) $(rule_test_objects)