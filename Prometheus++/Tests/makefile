#Some variables
COMP = g++
FLAGS = -g -Wall

all: build

build: testMain.o TestRunner.o
	$(COMP) $(FLAGS) -o test testMain.o TestRunner.o
	
testMain.o: testMain.cpp TestRunner.cpp
	$(COMP) $(FLAGS) -c testMain.cpp TestRunner.cpp
	
clean: testMain.o TestRunner.o test
	rm test *.o