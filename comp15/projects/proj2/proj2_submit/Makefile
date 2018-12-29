#Anahita Sethi
#Makefile
#COMP 15
#Project 2 

CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11 -O2
DEPS = Hasher.h DirNode.h FSTree.h
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

gerp: Main.o Hasher.o DirNode.o FSTree.o
	$(CC) -o gerp $^

clean:
	rm -f *.o core* *~ gerp 
