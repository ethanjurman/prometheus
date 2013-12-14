#include <vector>
#include <exception>
#include <string>

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
  TestStore(const char*, void (*)());
  TestStore(void (*)());
  void runFunction();
  std::string getTestName();
};

class TestRunner {
private:
  std::vector<TestStore*> tests;
  int total, pass;
  
  // don't allow copies or assignment
  TestRunner(const TestRunner&);
  TestRunner& operator=(const TestRunner&);
  
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
  static void assertEquals(const std::string msg, const T& first, const T& second) {
	if(first != second)
	  throw AssertException(msg);
  }
  
  template<typename T>
  static void assertEquals(const T& first, const T& second) {
	if(first != second)
	  throw AssertException();
  }
  
  template<typename T>
  static void assertNotEquals(const std::string msg, const T& first, const T& second) {
	if(first == second)
	  throw AssertException(msg);
  }
  
  template<typename T>
  static void assertNotEquals(const T& first, const T& second) {
	if(first == second)
	  throw AssertException();
  }
};