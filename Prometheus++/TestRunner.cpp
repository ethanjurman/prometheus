#include "TestRunner.h"

void TestRunner::addTest(void (*func)()) {
  tests.push_back(func);
}

void TestRunner::runTests() {
  /*for(std::vector<void (*)()>::iterator i = tests.begin(); i != tests.end(); ++i)
	*i();*/
  
  // eww...this looks like java, since I'm not using iter
  for(int i = 0; i < tests.size(); ++i)
	tests[i]();
}