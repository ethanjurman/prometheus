#include "TestRunner.h"
#include "../Dev/Model/NodeDatabase.h"
#include <string>
#include <iostream>
using namespace std;
using namespace Model;

class NodeDatabaseTest {
public:
  static void basicDatabaseTest() {
	Node* n = new Node("Test Node");
	NodeDatabase db;
	db.insertNode(*n);
	
	TestRunner::assertEquals<int>("Verify there's only 1 child", 1, db.parentQuery(n->getName())->size());
	
	db.removeNode(*n);
	TestRunner::assertEquals<int>("Verify the node was deleted.", 0, db.parentQuery(n->getName())->size());
	
	delete n;
  }
};

int main() {
  TestRunner run;
  run.addTest(NodeDatabaseTest::basicDatabaseTest, "basicDatabaseTest");
  run.runTests();
  
  return 0;
}