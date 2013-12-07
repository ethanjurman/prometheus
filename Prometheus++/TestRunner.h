#include <vector>

class TestRunner {
private:
  std::vector<void (*)()> tests;
  int total, pass;
  
  //don't allow copies or assignment
  
  
public:
  TestRunner(): total(0), pass(0) {}
  void addTest(void (*)());
  void runTests();
};