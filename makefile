FLAGS = -Wall -g
COMP = g++

main: main.o implements.o quiz.o
	$(COMP) $(FLAGS) -o main main.o scenarioImpl.o quiz.o
	del main.o
	del scenarioImpl.o
	del quiz.o

main.o: main.cpp scenarioImpl.cpp quiz/quiz.cpp
	$(COMP) $(FLAGS) -c main.cpp scenarioImpl.cpp quiz/quiz.cpp

implements.o: prototypes.hpp

quiz.o: quiz/quiz.hpp