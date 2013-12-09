#include "TestRunner.h"
#include <iostream>
using namespace std;

void test1() {
  cout << "Hello World" << endl;
}

void test2() {
  for(int i = 0; ++i < 10;)
	cout << i << endl;
}

int main() {
  TestRunner test;
  
  test.addTest(test1);
  test.addTest(test2);
  
  test.runTests();
  return 0;
}