#include "Node.h"
using namespace std;
using namespace Model;

Node::~Node() {
  /*if(parent != NULL)
	delete parent;*/
}

Node& Node::getParent() const {
  return *parent;
}

string Node::getName() const {
  return name;
}

void Node::setName(string s) {
  name = s;
}