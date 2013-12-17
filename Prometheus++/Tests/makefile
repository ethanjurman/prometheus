#Some variables
COMP = g++
FLAGS = -g -Wall
C11FLAG = -std=c++11

all: build

build: testMain.o TestRunner.o
	$(COMP) $(FLAGS) -o test testMain.o TestRunner.o
	
testMain.o: testMain.cpp TestRunner.cpp
	$(COMP) $(FLAGS) -c testMain.cpp TestRunner.cpp
	
clean: testMain.o TestRunner.o test
	rm test *.o
	
cleanEvalNode: evalNodeTest
	rm evalNodeTest 
	
evalTest: EvalNodeTest.cpp TestRunner.cpp TestRunner.h
	$(COMP) $(FLAGS) $(C11FLAG) -o evalNodeTest EvalNodeTest.cpp TestRunner.cpp "../Dev/Model/EvalNode.cpp"

nodeDbTest: TestRunner.cpp NodeDatabaseTest.cpp
	$(COMP) $(C11FLAG) -o nodeDbTest NodeDatabaseTest.cpp TestRunner.cpp "../Dev/Model/NodeDatabase.cpp" "../Dev/Model/Node.cpp"
cleanNodeDbTest: nodeDbTest
	rm nodeDbTest