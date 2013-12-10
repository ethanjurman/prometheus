#include <vector>
#include <exception>
#include<string>

class AssertException: public std::exception {
  std::string message;
  
public:
  AssertException(std::string m = "Assert failure."): message(m) {}
  ~AssertException() throw() {}
  
  virtual std::string getMessage() const throw() {
	return message;
  }
};

class TestStore {
  std::string testName;
  void (*func)();
  
public:
  TestStore(std::string, void (*)());
  TestStore(void (*)());
  void runFunction();
};

class TestRunner {
private:
  std::vector<TestStore*> tests;
  int total, pass;
  
  // don't allow copies or assignment
  TestRunner(const TestRunner&) {}
  TestRunner& operator=(const TestRunner&) { return *this; }
  
public:
  TestRunner(): total(0), pass(0) {}
  ~TestRunner();
  void addTest(void (*)());
  void addTest(void (*)(), std::string);
  void runTests();
  static void assertTrue(std::string, bool);
  static void assertTrue(bool);
  static void assertFalse(std::string, bool);
  static void assertFalse(bool);
  
  template<typename T>
  static void assertEquals(std::string message, T& first, T& second) {
	if(first != second)
	  throw AssertException(message);
  }
  
  template<typename T>
  static void assertEquals(T& first, T& second) {
	if(first != second)
	  throw AssertException();
  }
};