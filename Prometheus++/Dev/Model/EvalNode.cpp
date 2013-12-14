#include "EvalNode.h"
using namespace Model;
using namespace std;

bool EvalNode::isNumber() {
  int test = atoi(eval.c_str());
  
  if(test == 0)
	return (eval[0] == '0' || eval[0] == '.');
  
  return test;
}

void EvalNode::setEvaluation(string e) {
  eval = e;
}

EvalNode& EvalNode::operator=(const EvalNode& e) {
  eval = e.eval;
  name = e.name;
  return *this;
}