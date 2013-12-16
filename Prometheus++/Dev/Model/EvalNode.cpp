#include "EvalNode.h"
using namespace Model;
using namespace std;

bool EvalNode::isNumber() {
  const int ZERO = 48, NINE = 57, END = 0, POINT = 46;
  bool isDec = false;
  
  for(auto it = eval.cbegin(); it != eval.cend(); ++it) {
    if(*it != END && (*it < ZERO || *it > NINE) && *it != POINT) {
      return false;
    }
    
    // Make sure there's only one decimal
    if(*it == POINT) {
      if(isDec) {
	return false;
      } else {
	isDec = true;
      }
    }
  }
  
  return true;
}

void EvalNode::setEvaluation(string e) {
  eval = e;
}

EvalNode& EvalNode::operator=(const EvalNode& e) {
  eval = e.eval;
  name = e.name;
  return *this;
}