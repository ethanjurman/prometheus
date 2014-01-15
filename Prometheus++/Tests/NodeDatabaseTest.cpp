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
	TestRunner::assertTrue("Verify removal.", db.removeNode(*n));
	TestRunner::assertEquals<int>("Verify the node was deleted.", 0, db.parentQuery(n->getName())->size());
	
	delete n;
  }
  
  static void multipleInsertionTest() {
	Node n("Parent Node");
	Node c1("Child 1", &n);
	Node c2("Child 2", &n);
	NodeDatabase db;
	
	db.insertNode(n);
	db.insertNode(c1);
	db.insertNode(c2);
	
	TestRunner::assertEquals<int>("Verify 2 children nodes and reference to self.", 3, db.parentQuery(n.getName())->size());
  }
};

int main() {
  TestRunner run;
  run.addTest(NodeDatabaseTest::basicDatabaseTest, "basicDatabaseTest");
  run.addTest(NodeDatabaseTest::multipleInsertionTest, "multipleInsertionTest");
  run.runTests();
  
  return 0;
}