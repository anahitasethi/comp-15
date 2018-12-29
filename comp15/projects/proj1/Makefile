# Anahita Sethi
# COMP 15
# Project 1
# Makefile 

CC = clang++
CFLAGS = -Wall -Wextra -c --std=c++11
DEPS = Tree.h BinaryTree.h BinarySearchTree.h Survivor.h Queue.h 
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

survivor: survivor-driver.o BinaryTree.o BinarySearchTree.o Survivor.o Queue.o
	$(CC) -o survivor survivor-driver.o BinaryTree.o BinarySearchTree.o \
	Survivor.o Queue.o 

testbt: test-bt-driver.o BinaryTree.o Survivor.o Queue.o 
	$(CC) -o testbt test-bt-driver.o BinaryTree.o Survivor.o Queue.o 

testbst: test-bst-driver.o BinarySearchTree.o BinaryTree.o Survivor.o Queue.o
	$(CC) -o testbst test-bst-driver.o BinarySearchTree.o BinaryTree.o \
	Survivor.o Queue.o 

clean: 
	rm -f *.o core* *~ survivor 
	rm -f *.o core* *~ testbt
	rm -f *.o core* *~ testbst 
