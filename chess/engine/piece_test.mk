objects = piece_test.o piece.o

piece_test : $(objects)
	g++ -std=c++11 -o piece_test $(objects) -lpthread -lgtest

#piece.o : piece.cc piece.h
#	g++ -std=c++11 -c piece.cc -o piece.o

#piece_test.o : piece_test.cc piece.h
#	g++ -std=c++11 -c piece_test.cc -o piece_test.o

$(objects) : %.o: %.cc
	g++ -std=c++11 -c $< -o $@

.PHONY : clean
clean : 
	rm piece_test $(objects)