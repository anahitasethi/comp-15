#Anahita Sethi
#COMP15
#HW3
#Makefile 

CC = clang++
CFLAGS = -Wall -Wextra -c --std=c++11
DEPS = Stack.h RPNCalc.h
%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

calculator: run-calc.o RPNCalc.o Stack.o
	$(CC) -o calculator run-calc.o RPNCalc.o Stack.o 

stacktest: test-stack.o Stack.o
	$(CC) -o stacktest test-stack.o Stack.o  

clean: 
	rm -f *.o core* *~ calculator 
	rm -f *.o core* *~ stacktest 
