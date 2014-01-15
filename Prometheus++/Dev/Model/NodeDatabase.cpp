#include "NodeDatabase.h"
using namespace std;
using namespace Model;

NodeDatabase::NodeDatabase() {}

NodeDatabase::~NodeDatabase() {
  for(auto it = nodes.begin(); it != nodes.end(); ++it) {
	delete it->second;
  }
}

void NodeDatabase::insertNode(Node& n) {
  vector<Node*>* v = findParentVector(n);
  
  if(v == NULL) {
	vector<Node*>* children = new vector<Node*>;
	children->push_back(&n);
	nodes[n.getName()] = children; // creates the key-value pair
  } else {
	v->push_back(&n);
  }
}

bool NodeDatabase::removeNode(Node& n) {
  auto it = nodes.find(n.getName());
  
  if(it == nodes.end()) {
	return NULL;
  } else {
	vector<Node*>* children = it->second;
	for(auto i = children->begin(); i != children->end(); ++i) {
	  if((*i)->getName() == n.getName()) {
		children->erase(i);
		return true;
	  }
	}
  }
}

vector<Node*>* NodeDatabase::parentQuery(string parent) const {
  auto it = nodes.find(parent);
  
  if(it == nodes.end()) {
	return NULL;
  } else {
	return it->second;
  }
}

// NOTE: This is linear time wheras map::find is logarithmic
vector<Node*>* NodeDatabase::findParentVector(Node& n) const {
  for(auto it = nodes.begin(); it != nodes.end(); ++it) {
	if(it->first == n.getParent().getName())
	  return it->second;
  }
  
  return NULL;
}

void NodeDatabase::insertParentNode(Node& n) {
  vector<Node*>* children = new vector<Node*>;
  children->push_back(&n);
  nodes[n.getName()] = children;
}