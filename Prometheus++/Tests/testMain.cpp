#include "TestRunner.h"
#include <iostream>
using namespace std;

void test1() {
  string s1 = "Hello";
  string s2 = " World";
  cout << s1 + s2 << endl;
  TestRunner::assertNotEquals<string>(s1, s2);
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