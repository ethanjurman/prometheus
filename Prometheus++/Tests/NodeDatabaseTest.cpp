#include "TestRunner.h"
#include "../Dev/Model/NodeDatabase.h"
#include <string>
#include <iostream>
using namespace std;
using namespace Model;

class NodeDatabaseTest {
public:
  static void basicDatabaseTest() {
	Node n("Test Node");
	NodeDatabase db;
	db.insertNode(n);
	
	TestRunner::assertEquals<int>("Verify there's 1 child.", 1, db.parentQuery(n.getName())->size());
	
	db.removeNode(n);
	vector<Node*>* v = db.parentQuery(n.getName());
	TestRunner::assertTrue("Verify the node was deleted.", v == NULL);
  }
};

int main() {
  TestRunner run;
  run.addTest(NodeDatabaseTest::basicDatabaseTest, "basicDatabaseTest");
  run.runTests();
  
  return 0;
}