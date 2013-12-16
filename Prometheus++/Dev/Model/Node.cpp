#include "Node.h"
using namespace std;
using namespace Model;

Node& Node::getParent() const {
  return *parent;
}

string Node::getName() const {
  return name;
}

void Node::setName(string s) {
  name = s;
}