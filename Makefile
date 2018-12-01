CC = g++
CFLAGS = -Wall -std=c++11
				
clean:
	rm -rf *.o

util.o: ./src/Utils.cpp ./src/Utils.h
	$(CC) $(CFLAGS) -o util.o -c src/Utils.cpp

solver.o: ./src/Solver.cpp ./src/Solver.h
	$(CC) $(CFLAGS) -o solver.o -c src/Solver.cpp

sat.o: ./src/SAT_Solver.cpp 
	$(CC) $(CFLAGS) -o sat.o -c src/SAT_Solver.cpp

sat : sat.o solver.o util.o
	$(CC) $(CFLAGS) -o sat sat.o solver.o util.o

