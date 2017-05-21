
objects = log_test.o log.o

log_test : $(objects)
	g++ -std=c++11 -o log_test $(objects) -lgtest -lpthread -llog4cpp

log.o : log.cc log.h
	g++ -std=c++11 -c log.cc -o log.o

log_test.o : log_test.cc
	g++ -std=c++11 -c log_test.cc -o log_test.o

.PHONY : clean
clean : 
	rm log_test $(objects)