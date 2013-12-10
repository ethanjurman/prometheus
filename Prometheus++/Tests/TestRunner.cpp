#include "TestRunner.h"
#include <iostream>
using namespace std;

void TestRunner::addTest(void (*func)()) {
  TestStore* t = new TestStore(func);
  tests.push_back(t);
}

void TestRunner::addTest(void (*func)(), string name) {
  TestStore* t = new TestStore(name, func);
  tests.push_back(t);
}

void TestRunner::runTests() {
  for(unsigned int i = 0; i < tests.size(); ++i) {
	try {
	  tests[i]->runFunction();
	} catch(AssertException& e) {
	  cerr <<  e.getMessage() << endl;
	}
  }
}

void TestRunner::assertTrue(string message, bool value) {
  if(!value) {
	throw AssertException(message);
  }
}

void TestRunner::assertTrue(bool value) {
  if(!value) {
	throw AssertException();
  }
}

void TestRunner::assertFalse(string message, bool value) {
  if(value) {
	throw AssertException(message);
  }
}

void TestRunner::assertFalse(bool value) {
  if(value) {
	throw AssertException();
  }
}

TestStore::TestStore(string funcName, void (*f)()) {
  testName = funcName;
  func = f;
}

TestStore::TestStore(void (*f)()) {
  testName = "";
  func = f;
}

TestRunner::~TestRunner() {
  for(vector<TestStore*>::iterator i = tests.begin(); i != tests.end(); ++i) {
    delete *i;
  }
}

void TestStore::runFunction() {
  func();
}