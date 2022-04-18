FLAGS = -Wall -g

main: main.o implements.o 
	g++ $(FLAGS) -o main main.o scenarioImpl.o
	del main.o
	del scenarioImpl.o

main.o: main.cpp scenarioImpl.cpp
	g++ $(FLAGS) -c main.cpp scenarioImpl.cpp

implements.o: scenarioProt.h
