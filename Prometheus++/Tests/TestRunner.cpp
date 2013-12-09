#include "TestRunner.h"
#include <iostream>
using namespace std;

void TestRunner::addTest(void (*func)()) {
  tests.push_back(func);
}

void TestRunner::runTests() {
  for(unsigned int i = 0; i < tests.size(); ++i) {
	try {
	  tests[i]();
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