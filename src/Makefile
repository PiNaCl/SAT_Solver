CC = g++
CFLAGS = -Wall -std=c++11
				
clean:
	rm -rf *.o

util.o: Utils.cpp Utils.h
	$(CC) $(CFLAGS) -o util.o -c Utils.cpp

solver.o: Solver.cpp Solver.h
	$(CC) $(CFLAGS) -o solver.o -c Solver.cpp


sat.o: SAT_Solver.cpp 
	$(CC) $(CFLAGS) -o sat.o -c SAT_Solver.cpp

sat : sat.o solver.o util.o
	$(CC) $(CFLAGS) -o sat sat.o solver.o util.o

