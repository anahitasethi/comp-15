#Anahita Sethi
#COMP 15
#Homework 4
#Makefile 

CC = clang++
CFLAGS = -Wall -Wextra -c --std=c++11
DEPS = Heap.h MinHeap.h MaxHeap.h Patient.h 

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

heaps: intake.o Heap.o Patient.o MinHeap.o MaxHeap.o
	$(CC) -o heapify intake.o Heap.o Patient.o MinHeap.o MaxHeap.o 

testmin: test-min-heap.o Heap.o Patient.o MinHeap.o
	$(CC) -o testmin test-min-heap.o Heap.o Patient.o MinHeap.o

clean:
	rm -f *.o core* *~ heapify 
	rm -f *.o core* *~ testmin 
