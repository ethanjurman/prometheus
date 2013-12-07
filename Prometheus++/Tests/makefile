all: build

build: testMain.o TestRunner.o
	g++ -o test testMain.o TestRunner.o
	
testMain.o: testMain.cpp TestRunner.cpp
	g++ -c testMain.cpp TestRunner.cpp
	
clean: testMain.o TestRunner.o test
	rm testMain.o TestRunner.o test