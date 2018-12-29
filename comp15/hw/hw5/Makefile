#Anahita Sethi
#COMP15
#Homework5
#Makefile

CC = clang++
CFLAGS = -Wall -Wextra -c --std=c++11
DEPS = LinkedList.h Graph.h NodeType.h Queue.h Actor.h Stack.h SixDegrees.h 

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

sixdegrees: main.o LinkedList.o Actor.o Graph.o Stack.o \
	Queue.o SixDegrees.o
	$(CC) -o sixdegrees main.o LinkedList.o Actor.o Graph.o \
	Stack.o Queue.o SixDegrees.o

graphtest: test-graph.o Graph.o Actor.o Stack.o LinkedList.o \
	Queue.o SixDegrees.o
	$(CC) -o graphtest test-graph.o Graph.o Actor.o Stack.o \
	LinkedList.o Queue.o SixDegrees.o 

clean:
	rm -f *.o core* *~ sixdegrees
	rm -f *.o core* *~ graphtest 
