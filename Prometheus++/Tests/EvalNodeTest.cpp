#include "TestRunner.h"
#include "../Dev/Model/EvalNode.h"
#include <string>
using namespace std;
using namespace Model;

class EvalNodeTest {
public:
  static void isNumberTest() {
	EvalNode node("Test Eval Node", 0);
	
	node.setEvaluation("1.55");
	TestRunner::assertTrue("Failure: 1.55 is a number", node.isNumber());
	
	node.setEvaluation("0.05");
	TestRunner::assertTrue("Failure: 0.05 is a number", node.isNumber());
	
	node.setEvaluation("0.0.0.0");
	TestRunner::assertFalse("Failure: 0.0.0.0 isn't a number.", node.isNumber());
	
	node.setEvaluation("oh hai");
	TestRunner::assertFalse("Failure: 'oh hai' isn't a number.", node.isNumber());
  }
};

int main() {
  TestRunner run;
  run.addTest(EvalNodeTest::isNumberTest, "isNumberTest");
  run.runTests();
  
  return 0;
}